// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: messaging/request/payload/account/endpoints.proto

#ifndef PROTOBUF_messaging_2frequest_2fpayload_2faccount_2fendpoints_2eproto__INCLUDED
#define PROTOBUF_messaging_2frequest_2fpayload_2faccount_2fendpoints_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace protobuf_messaging_2frequest_2fpayload_2faccount_2fendpoints_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[1];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
void InitDefaultsListEndpointsQueryImpl();
void InitDefaultsListEndpointsQuery();
inline void InitDefaults() {
  InitDefaultsListEndpointsQuery();
}
}  // namespace protobuf_messaging_2frequest_2fpayload_2faccount_2fendpoints_2eproto
namespace agrirouter {
namespace request {
namespace payload {
namespace account {
class ListEndpointsQuery;
class ListEndpointsQueryDefaultTypeInternal;
extern ListEndpointsQueryDefaultTypeInternal _ListEndpointsQuery_default_instance_;
}  // namespace account
}  // namespace payload
}  // namespace request
}  // namespace agrirouter
namespace agrirouter {
namespace request {
namespace payload {
namespace account {

enum ListEndpointsQuery_Direction {
  ListEndpointsQuery_Direction_SEND = 0,
  ListEndpointsQuery_Direction_RECEIVE = 1,
  ListEndpointsQuery_Direction_SEND_RECEIVE = 2,
  ListEndpointsQuery_Direction_ListEndpointsQuery_Direction_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  ListEndpointsQuery_Direction_ListEndpointsQuery_Direction_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool ListEndpointsQuery_Direction_IsValid(int value);
const ListEndpointsQuery_Direction ListEndpointsQuery_Direction_Direction_MIN = ListEndpointsQuery_Direction_SEND;
const ListEndpointsQuery_Direction ListEndpointsQuery_Direction_Direction_MAX = ListEndpointsQuery_Direction_SEND_RECEIVE;
const int ListEndpointsQuery_Direction_Direction_ARRAYSIZE = ListEndpointsQuery_Direction_Direction_MAX + 1;

const ::google::protobuf::EnumDescriptor* ListEndpointsQuery_Direction_descriptor();
inline const ::std::string& ListEndpointsQuery_Direction_Name(ListEndpointsQuery_Direction value) {
  return ::google::protobuf::internal::NameOfEnum(
    ListEndpointsQuery_Direction_descriptor(), value);
}
inline bool ListEndpointsQuery_Direction_Parse(
    const ::std::string& name, ListEndpointsQuery_Direction* value) {
  return ::google::protobuf::internal::ParseNamedEnum<ListEndpointsQuery_Direction>(
    ListEndpointsQuery_Direction_descriptor(), name, value);
}
// ===================================================================

class ListEndpointsQuery : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:agrirouter.request.payload.account.ListEndpointsQuery) */ {
 public:
  ListEndpointsQuery();
  virtual ~ListEndpointsQuery();

  ListEndpointsQuery(const ListEndpointsQuery& from);

  inline ListEndpointsQuery& operator=(const ListEndpointsQuery& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  ListEndpointsQuery(ListEndpointsQuery&& from) noexcept
    : ListEndpointsQuery() {
    *this = ::std::move(from);
  }

  inline ListEndpointsQuery& operator=(ListEndpointsQuery&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const ListEndpointsQuery& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const ListEndpointsQuery* internal_default_instance() {
    return reinterpret_cast<const ListEndpointsQuery*>(
               &_ListEndpointsQuery_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(ListEndpointsQuery* other);
  friend void swap(ListEndpointsQuery& a, ListEndpointsQuery& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline ListEndpointsQuery* New() const PROTOBUF_FINAL { return New(NULL); }

  ListEndpointsQuery* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const ListEndpointsQuery& from);
  void MergeFrom(const ListEndpointsQuery& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(ListEndpointsQuery* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  typedef ListEndpointsQuery_Direction Direction;
  static const Direction SEND =
    ListEndpointsQuery_Direction_SEND;
  static const Direction RECEIVE =
    ListEndpointsQuery_Direction_RECEIVE;
  static const Direction SEND_RECEIVE =
    ListEndpointsQuery_Direction_SEND_RECEIVE;
  static inline bool Direction_IsValid(int value) {
    return ListEndpointsQuery_Direction_IsValid(value);
  }
  static const Direction Direction_MIN =
    ListEndpointsQuery_Direction_Direction_MIN;
  static const Direction Direction_MAX =
    ListEndpointsQuery_Direction_Direction_MAX;
  static const int Direction_ARRAYSIZE =
    ListEndpointsQuery_Direction_Direction_ARRAYSIZE;
  static inline const ::google::protobuf::EnumDescriptor*
  Direction_descriptor() {
    return ListEndpointsQuery_Direction_descriptor();
  }
  static inline const ::std::string& Direction_Name(Direction value) {
    return ListEndpointsQuery_Direction_Name(value);
  }
  static inline bool Direction_Parse(const ::std::string& name,
      Direction* value) {
    return ListEndpointsQuery_Direction_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  // string technical_message_type = 1;
  void clear_technical_message_type();
  static const int kTechnicalMessageTypeFieldNumber = 1;
  const ::std::string& technical_message_type() const;
  void set_technical_message_type(const ::std::string& value);
  #if LANG_CXX11
  void set_technical_message_type(::std::string&& value);
  #endif
  void set_technical_message_type(const char* value);
  void set_technical_message_type(const char* value, size_t size);
  ::std::string* mutable_technical_message_type();
  ::std::string* release_technical_message_type();
  void set_allocated_technical_message_type(::std::string* technical_message_type);

  // .agrirouter.request.payload.account.ListEndpointsQuery.Direction direction = 2;
  void clear_direction();
  static const int kDirectionFieldNumber = 2;
  ::agrirouter::request::payload::account::ListEndpointsQuery_Direction direction() const;
  void set_direction(::agrirouter::request::payload::account::ListEndpointsQuery_Direction value);

  // @@protoc_insertion_point(class_scope:agrirouter.request.payload.account.ListEndpointsQuery)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr technical_message_type_;
  int direction_;
  mutable int _cached_size_;
  friend struct ::protobuf_messaging_2frequest_2fpayload_2faccount_2fendpoints_2eproto::TableStruct;
  friend void ::protobuf_messaging_2frequest_2fpayload_2faccount_2fendpoints_2eproto::InitDefaultsListEndpointsQueryImpl();
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// ListEndpointsQuery

// string technical_message_type = 1;
inline void ListEndpointsQuery::clear_technical_message_type() {
  technical_message_type_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& ListEndpointsQuery::technical_message_type() const {
  // @@protoc_insertion_point(field_get:agrirouter.request.payload.account.ListEndpointsQuery.technical_message_type)
  return technical_message_type_.GetNoArena();
}
inline void ListEndpointsQuery::set_technical_message_type(const ::std::string& value) {
  
  technical_message_type_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:agrirouter.request.payload.account.ListEndpointsQuery.technical_message_type)
}
#if LANG_CXX11
inline void ListEndpointsQuery::set_technical_message_type(::std::string&& value) {
  
  technical_message_type_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:agrirouter.request.payload.account.ListEndpointsQuery.technical_message_type)
}
#endif
inline void ListEndpointsQuery::set_technical_message_type(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  technical_message_type_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:agrirouter.request.payload.account.ListEndpointsQuery.technical_message_type)
}
inline void ListEndpointsQuery::set_technical_message_type(const char* value, size_t size) {
  
  technical_message_type_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:agrirouter.request.payload.account.ListEndpointsQuery.technical_message_type)
}
inline ::std::string* ListEndpointsQuery::mutable_technical_message_type() {
  
  // @@protoc_insertion_point(field_mutable:agrirouter.request.payload.account.ListEndpointsQuery.technical_message_type)
  return technical_message_type_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* ListEndpointsQuery::release_technical_message_type() {
  // @@protoc_insertion_point(field_release:agrirouter.request.payload.account.ListEndpointsQuery.technical_message_type)
  
  return technical_message_type_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ListEndpointsQuery::set_allocated_technical_message_type(::std::string* technical_message_type) {
  if (technical_message_type != NULL) {
    
  } else {
    
  }
  technical_message_type_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), technical_message_type);
  // @@protoc_insertion_point(field_set_allocated:agrirouter.request.payload.account.ListEndpointsQuery.technical_message_type)
}

// .agrirouter.request.payload.account.ListEndpointsQuery.Direction direction = 2;
inline void ListEndpointsQuery::clear_direction() {
  direction_ = 0;
}
inline ::agrirouter::request::payload::account::ListEndpointsQuery_Direction ListEndpointsQuery::direction() const {
  // @@protoc_insertion_point(field_get:agrirouter.request.payload.account.ListEndpointsQuery.direction)
  return static_cast< ::agrirouter::request::payload::account::ListEndpointsQuery_Direction >(direction_);
}
inline void ListEndpointsQuery::set_direction(::agrirouter::request::payload::account::ListEndpointsQuery_Direction value) {
  
  direction_ = value;
  // @@protoc_insertion_point(field_set:agrirouter.request.payload.account.ListEndpointsQuery.direction)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace account
}  // namespace payload
}  // namespace request
}  // namespace agrirouter

namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::agrirouter::request::payload::account::ListEndpointsQuery_Direction> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::agrirouter::request::payload::account::ListEndpointsQuery_Direction>() {
  return ::agrirouter::request::payload::account::ListEndpointsQuery_Direction_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_messaging_2frequest_2fpayload_2faccount_2fendpoints_2eproto__INCLUDED