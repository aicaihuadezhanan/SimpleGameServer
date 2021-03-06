// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MsgID.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_MsgID_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_MsgID_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3012000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3012002 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_MsgID_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_MsgID_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_MsgID_2eproto;
PROTOBUF_NAMESPACE_OPEN
PROTOBUF_NAMESPACE_CLOSE

enum MessageID : int {
  MSG_BEGIN = 0,
  MSG_NORMAL_MSGID_BEGIN = 100000,
  MSG_DBSVR_HEART_REQ = 100001,
  MSG_DBSVR_HEART_ACK = 100002,
  MSG_ACCOUNT_REG_REQ = 100003,
  MSG_ACCOUNT_REG_ACK = 100004,
  MSG_ACCOUNT_LOGIN_REQ = 100005,
  MSG_ACCOUNT_LOGIN_ACK = 100006,
  MSG_SERVER_LIST_REQ = 100009,
  MSG_SERVER_LIST_ACK = 100010,
  MSG_SELECT_SERVER_REQ = 100011,
  MSG_SELECT_SERVER_ACK = 100012,
  MSG_HEART_BEAT_REQ = 100013,
  MSG_HEART_BEAT_ACK = 100014,
  MSG_LOGICSVR_HEART_REQ = 100015,
  MSG_LOGICSVR_HEART_ACK = 100016,
  MSG_LOST_CONNECT_REQ = 100017,
  MSG_GAMESVR_REGISTER_REQ = 100018,
  MSG_GAMESVR_REGISTER_ACK = 100019,
  MSG_LOGINSVR_REGISTER_REQ = 100020,
  MSG_LOGINSVR_REGISTER_ACK = 100021,
  MSG_LOAD_PLAYER_LIST_REQ = 100022,
  MSG_LOAD_PLAYER_LIST_ACK = 100023,
  MSG_CREATE_PLAYER_REQ = 100024,
  MSG_CREATE_PLAYER_ACK = 100025,
  MSG_SELECT_PLAYER_ENTER_REQ = 100026,
  MSG_SELECT_PLAYER_ENTER_ACK = 100027,
  MSG_SELECT_ENTER_LOGICSVR_REQ = 100028,
  MSG_SELECT_ENTER_LOGICSVR_ACK = 100029,
  MSG_LOGOUT_REQ = 100030,
  MSG_LOGOUT_ACK = 100031,
  MSG_NORMAL_MSGID_END = 199999,
  MSG_LOGICSVR_MSGID_BEGIN = 200000,
  MSG_BAG_UNLOCK_REQ = 200001,
  MSG_BAG_UNLOCK_ACK = 200002,
  MSG_STORE_BUY_REQ = 200010,
  MSG_STORE_BUY_ACK = 200011,
  MSG_GAMESVR_MSGID_BEGIN = 300000,
  MSG_COMMAND_ATK_REQ = 300001,
  MSG_COMMAND_ATK_ACK = 300002,
  MSG_COMMAND_SKILL_REQ = 300003,
  MSG_COMMAND_SKILL_ACK = 300004,
  MSG_COMMAND_DEFINE_REQ = 300005,
  MSG_COMMAND_DEFINE_ACK = 300006,
  MSG_COMMAND_USING_REQ = 300007,
  MSG_COMMAND_USING_ACK = 300008,
  MSG_COMMAND_CHANGE_CARD_REQ = 300009,
  MSG_COMMAND_CHANGE_CARD_ACK = 300010,
  MSG_COMMAND_ESCAPE_REQ = 300011,
  MSG_COMMAND_ESCAPE_ACK = 300012,
  MSG_DBSVR_MSGID_BEGIN = 400000,
  MSG_DB_EXE_SQL_REQ = 400001,
  MSG_DB_EXE_SQL_ACK = 400002,
  MSG_ACCOUNT_LOGIN_VERIFY_REQ = 400003,
  MSG_ACCOUNT_LOGIN_VERIFY_ACK = 400004,
  MSG_ACCOUNT_REG_TO_DBSVR_REQ = 400005,
  MSG_ACCOUNT_REG_TO_DBSVR_ACK = 400006,
  MSG_LOAD_LOGICSVR_LIST_FROM_DBSVR_REQ = 400007,
  MSG_LOAD_LOGICSVR_LIST_FROM_DBSVR_ACK = 400008,
  MSG_DBSVR_MSGID_END = 499999,
  MessageID_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::min(),
  MessageID_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::max()
};
bool MessageID_IsValid(int value);
constexpr MessageID MessageID_MIN = MSG_BEGIN;
constexpr MessageID MessageID_MAX = MSG_DBSVR_MSGID_END;
constexpr int MessageID_ARRAYSIZE = MessageID_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* MessageID_descriptor();
template<typename T>
inline const std::string& MessageID_Name(T enum_t_value) {
  static_assert(::std::is_same<T, MessageID>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function MessageID_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    MessageID_descriptor(), enum_t_value);
}
inline bool MessageID_Parse(
    const std::string& name, MessageID* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<MessageID>(
    MessageID_descriptor(), name, value);
}
// ===================================================================


// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


PROTOBUF_NAMESPACE_OPEN

template <> struct is_proto_enum< ::MessageID> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::MessageID>() {
  return ::MessageID_descriptor();
}

PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_MsgID_2eproto
