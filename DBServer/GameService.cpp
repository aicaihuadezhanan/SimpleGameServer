#include"GameService.h"
#include"MsgHandlerManager.hpp"
#include"Agent.h"
#include"AgentManager.h"
#include"ConnectServerMgr.h"

CGameService::CGameService()
{
	m_dwGateConnID = -1;
	m_dwLoginConnID = -1;
	_oldTime = CELLTime::getNowInMilliSec();
}

CGameService::~CGameService()
{
}

CGameService* CGameService::GetInstancePtr()
{
	static CGameService _GameService;
	return &_GameService;
}

//服务初始化
bool CGameService::Init()
{
	if(!CConfigFile::GetInstancePtr()->Load("./ServerEngine/servercfg.ini"))
	{
		CELLLog::Info("加载 servercfg.ini文件失败!");
		return false;
	}

	// get mysql config
	std::string strHost = CConfigFile::GetInstancePtr()->GetStringValue("mysql_logic_svr_ip");
	int nPort = CConfigFile::GetInstancePtr()->GetIntValue("mysql_logic_svr_port");
	std::string strUser = CConfigFile::GetInstancePtr()->GetStringValue("mysql_logic_svr_user");
	std::string strPwd = CConfigFile::GetInstancePtr()->GetStringValue("mysql_logic_svr_pwd");
	std::string strDb = CConfigFile::GetInstancePtr()->GetStringValue("mysql_logic_svr_db_name");
	// mysql connect
	if(!tDBConnection.open(strHost.c_str(), strUser.c_str(), strPwd.c_str(), strDb.c_str(), nPort))
	{
		CELLLog::Info("Error: Can not open mysql database! Reason:%s", tDBConnection.GetErrorMsg());
		return false;
	}

	// ConnectServerMgr init
	ConnectServerMgr::GetInstancePtr()->Init();

	// add heartBeat timer
	CSysTimerManager::GetInstancePtr()->AddTimer(2000, 1, &CGameService::HeartBeat, this, true);

	return true;
}

//定时操作
bool CGameService::OnSecondTimer()
{
	//连接网关
	//ConnectToGateServer();

	return true;
}

//Update
void CGameService::OnUpdate()
{
	CSysTimerManager::GetInstancePtr()->UpdateTimer();
}

//给其他服发送心跳包
bool CGameService::HeartBeat(unsigned int msec)
{
	if (m_dwLoginConnID != 1)
	{

		//SendData(m_dwLoginConnID, MSG_GAME_REGTO_LOGIC_ACK, )
	}
	return true;
}

//连接网关
bool CGameService::ConnectToGateServer()
{
	if (m_dwGateConnID != -1)
	{
		return true;
	}

	UINT32 nGatePort = CConfigFile::GetInstancePtr()->GetIntValue("gate_svr_port");
	std::string strGateIp = CConfigFile::GetInstancePtr()->GetStringValue("gate_svr_ip");
	m_dwGateConnID = Connect(strGateIp.c_str(), nGatePort);
	ERROR_RETURN_FALSE(m_dwGateConnID != -1);
	return true;
}

//连接登录服
bool CGameService::ConnectToLoginServer()
{
	if (m_dwLoginConnID != -1)
	{
		return true;
	}

	UINT32 nLoginPort = CConfigFile::GetInstancePtr()->GetIntValue("login_svr_port");
	std::string strLoginIp = CConfigFile::GetInstancePtr()->GetStringValue("login_svr_ip");
	m_dwLoginConnID = Connect(strLoginIp.c_str(), nLoginPort);
	ERROR_RETURN_FALSE(m_dwLoginConnID != -1);
	return true;
}

//客户端加入事件
void CGameService::OnNetJoin(CELLClient * pClient)
{
	EasyTcpServer::OnNetJoin(pClient);
	int fd = pClient->sockfd();
	Agent* agent = new Agent();
	agent->SetFd(fd);
	if (fd == m_dwGateConnID || fd == m_dwLoginConnID)
	{
		agent->SetConnect(true);
	}

	AgentManager::GetInstancePtr()->SetPortToAgent(fd, agent);
}

//客户端离开事件
void CGameService::OnNetLeave(CELLClient * pClient)
{
	//移除fd和agent的映射关系
	EasyTcpServer::OnNetLeave(pClient);
	int fd = pClient->sockfd();
	AgentManager::GetInstancePtr()->RemovePortToAgent(fd);
	//删除agent对象
	Agent* agent = AgentManager::GetInstancePtr()->FindAgentByPort(fd);
	delete agent;

	// 断开连接 重置connectID
	if (fd == m_dwGateConnID)
	{
		m_dwGateConnID = -1;
	}
	else if (fd == m_dwLoginConnID)
	{
		m_dwLoginConnID = -1;
	}
}

//处理网络消息
void CGameService::OnNetMsg(CELLServer* pServer, CELLClient* pClient, netmsg_DataHeader* package)
{
	EasyTcpServer::OnNetMsg(pServer, pClient, package);
	int fd = pClient->sockfd();
	Agent* agent = AgentManager::GetInstancePtr()->FindAgentByPort(fd);
	if (agent == nullptr)
	{
		CELLLog::Info("CGameService::OnNetMsg Error Invalid sockfd:%d, MessageID:%d", pClient->sockfd(), package->cmd);
		return;
	}

	NetPacket pack(fd, package);
	if (!agent->IsUser())
	{
		// system or other message
		if (!CMsgHandlerManager::GetInstancePtr()->ExecuteMessage(package->cmd, &pack))
		{
			CELLLog::Info("CGameService::OnNetMsg Not Find SystemMessage sockfd:%d, MessageID:%d", pClient->sockfd(), package->cmd);
			return;
		}
	}
	else
	{
		// player message
		if (agent->m_NetMessagePump.ExecuteMessage(package->cmd, &pack))
		{
			CELLLog::Info("CGameService::OnNetMsg Not Find PlayerMessage sockfd:%d, MessageID:%d", pClient->sockfd(), package->cmd);
			return;
		}
	}
}

//推送网络消息
bool CGameService::SendData(int fd, int MsgID, const google::protobuf::Message& pdata)
{
	CELLClient* pClient = GetClientByFD(fd);
	if(pClient == nullptr)
	{
		CELLLog::Info("Error: pClient is nullptr!!!!!!\n");
		return false;
	}

	char szBuff[102400] = { 0 };
	ERROR_RETURN_FALSE(pdata.ByteSizeLong() < 102400);
	pdata.SerializePartialToArray(szBuff, pdata.GetCachedSize());

	netmsg_DataHeader data;
	data.cmd = MsgID;
	memcpy(data.buff, "%s", sizeof(szBuff));
	
	pClient->SendData(&data);
	return true;
}