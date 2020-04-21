// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: messaging/response/response.proto

#ifndef PROTOBUF_messaging_2fresponse_2fresponse_2eproto__INCLUDED
#define PROTOBUF_messaging_2fresponse_2fresponse_2eproto__INCLUDED

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
#include <google/protobuf/any.pb.h>
#include <google/protobuf/timestamp.pb.h>
// @@protoc_insertion_point(includes)

namespace protobuf_messaging_2fresponse_2fresponse_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[2];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
void InitDefaultsResponseEnvelopeImpl();
void InitDefaultsResponseEnvelope();
void InitDefaultsResponsePayloadWrapperImpl();
void InitDefaultsResponsePayloadWrapper();
inline void InitDefaults() {
  InitDefaultsResponseEnvelope();
  InitDefaultsResponsePayloadWrapper();
}
}  // namespace protobuf_messaging_2fresponse_2fresponse_2eproto
namespace agrirouter {
namespace response {
class ResponseEnvelope;
class ResponseEnvelopeDefaultTypeInternal;
extern ResponseEnvelopeDefaultTypeInternal _ResponseEnvelope_default_instance_;
class ResponsePayloadWrapper;
class ResponsePayloadWrapperDefaultTypeInternal;
extern ResponsePayloadWrapperDefaultTypeInternal _ResponsePayloadWrapper_default_instance_;
}  // namespace response
}  // namespace agrirouter
namespace agrirouter {
namespace response {

enum ResponseEnvelope_ResponseBodyType {
  ResponseEnvelope_ResponseBodyType_MESSAGES = 0,
  ResponseEnvelope_ResponseBodyType_ACK = 1,
  ResponseEnvelope_ResponseBodyType_ACK_WITH_MESSAGES = 2,
  ResponseEnvelope_ResponseBodyType_ACK_WITH_FAILURE = 3,
  ResponseEnvelope_ResponseBodyType_ACK_FOR_FEED_HEADER_LIST = 6,
  ResponseEnvelope_ResponseBodyType_ACK_FOR_FEED_MESSAGE = 7,
  ResponseEnvelope_ResponseBodyType_ACK_FOR_FEED_FAILED_MESSAGE = 8,
  ResponseEnvelope_ResponseBodyType_ENDPOINTS_LISTING = 10,
  ResponseEnvelope_ResponseBodyType_CLOUD_REGISTRATIONS = 11,
  ResponseEnvelope_ResponseBodyType_ResponseEnvelope_ResponseBodyType_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  ResponseEnvelope_ResponseBodyType_ResponseEnvelope_ResponseBodyType_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool ResponseEnvelope_ResponseBodyType_IsValid(int value);
const ResponseEnvelope_ResponseBodyType ResponseEnvelope_ResponseBodyType_ResponseBodyType_MIN = ResponseEnvelope_ResponseBodyType_MESSAGES;
const ResponseEnvelope_ResponseBodyType ResponseEnvelope_ResponseBodyType_ResponseBodyType_MAX = ResponseEnvelope_ResponseBodyType_CLOUD_REGISTRATIONS;
const int ResponseEnvelope_ResponseBodyType_ResponseBodyType_ARRAYSIZE = ResponseEnvelope_ResponseBodyType_ResponseBodyType_MAX + 1;

const ::google::protobuf::EnumDescriptor* ResponseEnvelope_ResponseBodyType_descriptor();
inline const ::std::string& ResponseEnvelope_ResponseBodyType_Name(ResponseEnvelope_ResponseBodyType value) {
  return ::google::protobuf::internal::NameOfEnum(
    ResponseEnvelope_ResponseBodyType_descriptor(), value);
}
inline bool ResponseEnvelope_ResponseBodyType_Parse(
    const ::std::string& name, ResponseEnvelope_ResponseBodyType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<ResponseEnvelope_ResponseBodyType>(
    ResponseEnvelope_ResponseBodyType_descriptor(), name, value);
}
// ===================================================================

class ResponseEnvelope : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:agrirouter.response.ResponseEnvelope) */ {
 public:
  ResponseEnvelope();
  virtual ~ResponseEnvelope();

  ResponseEnvelope(const ResponseEnvelope& from);

  inline ResponseEnvelope& operator=(const ResponseEnvelope& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  ResponseEnvelope(ResponseEnvelope&& from) noexcept
    : ResponseEnvelope() {
    *this = ::std::move(from);
  }

  inline ResponseEnvelope& operator=(ResponseEnvelope&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const ResponseEnvelope& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const ResponseEnvelope* internal_default_instance() {
    return reinterpret_cast<const ResponseEnvelope*>(
               &_ResponseEnvelope_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(ResponseEnvelope* other);
  friend void swap(ResponseEnvelope& a, ResponseEnvelope& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline ResponseEnvelope* New() const PROTOBUF_FINAL { return New(NULL); }

  ResponseEnvelope* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const ResponseEnvelope& from);
  void MergeFrom(const ResponseEnvelope& from);
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
  void InternalSwap(ResponseEnvelope* other);
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

  typedef ResponseEnvelope_ResponseBodyType ResponseBodyType;
  static const ResponseBodyType MESSAGES =
    ResponseEnvelope_ResponseBodyType_MESSAGES;
  static const ResponseBodyType ACK =
    ResponseEnvelope_ResponseBodyType_ACK;
  static const ResponseBodyType ACK_WITH_MESSAGES =
    ResponseEnvelope_ResponseBodyType_ACK_WITH_MESSAGES;
  static const ResponseBodyType ACK_WITH_FAILURE =
    ResponseEnvelope_ResponseBodyType_ACK_WITH_FAILURE;
  static const ResponseBodyType ACK_FOR_FEED_HEADER_LIST =
    ResponseEnvelope_ResponseBodyType_ACK_FOR_FEED_HEADER_LIST;
  static const ResponseBodyType ACK_FOR_FEED_MESSAGE =
    ResponseEnvelope_ResponseBodyType_ACK_FOR_FEED_MESSAGE;
  static const ResponseBodyType ACK_FOR_FEED_FAILED_MESSAGE =
    ResponseEnvelope_ResponseBodyType_ACK_FOR_FEED_FAILED_MESSAGE;
  static const ResponseBodyType ENDPOINTS_LISTING =
    ResponseEnvelope_ResponseBodyType_ENDPOINTS_LISTING;
  static const ResponseBodyType CLOUD_REGISTRATIONS =
    ResponseEnvelope_ResponseBodyType_CLOUD_REGISTRATIONS;
  static inline bool ResponseBodyType_IsValid(int value) {
    return ResponseEnvelope_ResponseBodyType_IsValid(value);
  }
  static const ResponseBodyType ResponseBodyType_MIN =
    ResponseEnvelope_ResponseBodyType_ResponseBodyType_MIN;
  static const ResponseBodyType ResponseBodyType_MAX =
    ResponseEnvelope_ResponseBodyType_ResponseBodyType_MAX;
  static const int ResponseBodyType_ARRAYSIZE =
    ResponseEnvelope_ResponseBodyType_ResponseBodyType_ARRAYSIZE;
  static inline const ::google::protobuf::EnumDescriptor*
  ResponseBodyType_descriptor() {
    return ResponseEnvelope_ResponseBodyType_descriptor();
  }
  static inline const ::std::string& ResponseBodyType_Name(ResponseBodyType value) {
    return ResponseEnvelope_ResponseBodyType_Name(value);
  }
  static inline bool ResponseBodyType_Parse(const ::std::string& name,
      ResponseBodyType* value) {
    return ResponseEnvelope_ResponseBodyType_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  // string application_message_id = 3;
  void clear_application_message_id();
  static const int kApplicationMessageIdFieldNumber = 3;
  const ::std::string& application_message_id() const;
  void set_application_message_id(const ::std::string& value);
  #if LANG_CXX11
  void set_application_message_id(::std::string&& value);
  #endif
  void set_application_message_id(const char* value);
  void set_application_message_id(const char* value, size_t size);
  ::std::string* mutable_application_message_id();
  ::std::string* release_application_message_id();
  void set_allocated_application_message_id(::std::string* application_message_id);

  // string message_id = 4;
  void clear_message_id();
  static const int kMessageIdFieldNumber = 4;
  const ::std::string& message_id() const;
  void set_message_id(const ::std::string& value);
  #if LANG_CXX11
  void set_message_id(::std::string&& value);
  #endif
  void set_message_id(const char* value);
  void set_message_id(const char* value, size_t size);
  ::std::string* mutable_message_id();
  ::std::string* release_message_id();
  void set_allocated_message_id(::std::string* message_id);

  // .google.protobuf.Timestamp timestamp = 5;
  bool has_timestamp() const;
  void clear_timestamp();
  static const int kTimestampFieldNumber = 5;
  const ::google::protobuf::Timestamp& timestamp() const;
  ::google::protobuf::Timestamp* release_timestamp();
  ::google::protobuf::Timestamp* mutable_timestamp();
  void set_allocated_timestamp(::google::protobuf::Timestamp* timestamp);

  // int32 response_code = 1;
  void clear_response_code();
  static const int kResponseCodeFieldNumber = 1;
  ::google::protobuf::int32 response_code() const;
  void set_response_code(::google::protobuf::int32 value);

  // .agrirouter.response.ResponseEnvelope.ResponseBodyType type = 2;
  void clear_type();
  static const int kTypeFieldNumber = 2;
  ::agrirouter::response::ResponseEnvelope_ResponseBodyType type() const;
  void set_type(::agrirouter::response::ResponseEnvelope_ResponseBodyType value);

  // @@protoc_insertion_point(class_scope:agrirouter.response.ResponseEnvelope)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr application_message_id_;
  ::google::protobuf::internal::ArenaStringPtr message_id_;
  ::google::protobuf::Timestamp* timestamp_;
  ::google::protobuf::int32 response_code_;
  int type_;
  mutable int _cached_size_;
  friend struct ::protobuf_messaging_2fresponse_2fresponse_2eproto::TableStruct;
  friend void ::protobuf_messaging_2fresponse_2fresponse_2eproto::InitDefaultsResponseEnvelopeImpl();
};
// -------------------------------------------------------------------

class ResponsePayloadWrapper : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:agrirouter.response.ResponsePayloadWrapper) */ {
 public:
  ResponsePayloadWrapper();
  virtual ~ResponsePayloadWrapper();

  ResponsePayloadWrapper(const ResponsePayloadWrapper& from);

  inline ResponsePayloadWrapper& operator=(const ResponsePayloadWrapper& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  ResponsePayloadWrapper(ResponsePayloadWrapper&& from) noexcept
    : ResponsePayloadWrapper() {
    *this = ::std::move(from);
  }

  inline ResponsePayloadWrapper& operator=(ResponsePayloadWrapper&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const ResponsePayloadWrapper& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const ResponsePayloadWrapper* internal_default_instance() {
    return reinterpret_cast<const ResponsePayloadWrapper*>(
               &_ResponsePayloadWrapper_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    1;

  void Swap(ResponsePayloadWrapper* other);
  friend void swap(ResponsePayloadWrapper& a, ResponsePayloadWrapper& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline ResponsePayloadWrapper* New() const PROTOBUF_FINAL { return New(NULL); }

  ResponsePayloadWrapper* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const ResponsePayloadWrapper& from);
  void MergeFrom(const ResponsePayloadWrapper& from);
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
  void InternalSwap(ResponsePayloadWrapper* other);
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

  // accessors -------------------------------------------------------

  // .google.protobuf.Any details = 1;
  bool has_details() const;
  void clear_details();
  static const int kDetailsFieldNumber = 1;
  const ::google::protobuf::Any& details() const;
  ::google::protobuf::Any* release_details();
  ::google::protobuf::Any* mutable_details();
  void set_allocated_details(::google::protobuf::Any* details);

  // @@protoc_insertion_point(class_scope:agrirouter.response.ResponsePayloadWrapper)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::Any* details_;
  mutable int _cached_size_;
  friend struct ::protobuf_messaging_2fresponse_2fresponse_2eproto::TableStruct;
  friend void ::protobuf_messaging_2fresponse_2fresponse_2eproto::InitDefaultsResponsePayloadWrapperImpl();
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// ResponseEnvelope

// int32 response_code = 1;
inline void ResponseEnvelope::clear_response_code() {
  response_code_ = 0;
}
inline ::google::protobuf::int32 ResponseEnvelope::response_code() const {
  // @@protoc_insertion_point(field_get:agrirouter.response.ResponseEnvelope.response_code)
  return response_code_;
}
inline void ResponseEnvelope::set_response_code(::google::protobuf::int32 value) {
  
  response_code_ = value;
  // @@protoc_insertion_point(field_set:agrirouter.response.ResponseEnvelope.response_code)
}

// .agrirouter.response.ResponseEnvelope.ResponseBodyType type = 2;
inline void ResponseEnvelope::clear_type() {
  type_ = 0;
}
inline ::agrirouter::response::ResponseEnvelope_ResponseBodyType ResponseEnvelope::type() const {
  // @@protoc_insertion_point(field_get:agrirouter.response.ResponseEnvelope.type)
  return static_cast< ::agrirouter::response::ResponseEnvelope_ResponseBodyType >(type_);
}
inline void ResponseEnvelope::set_type(::agrirouter::response::ResponseEnvelope_ResponseBodyType value) {
  
  type_ = value;
  // @@protoc_insertion_point(field_set:agrirouter.response.ResponseEnvelope.type)
}

// string application_message_id = 3;
inline void ResponseEnvelope::clear_application_message_id() {
  application_message_id_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& ResponseEnvelope::application_message_id() const {
  // @@protoc_insertion_point(field_get:agrirouter.response.ResponseEnvelope.application_message_id)
  return application_message_id_.GetNoArena();
}
inline void ResponseEnvelope::set_application_message_id(const ::std::string& value) {
  
  application_message_id_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:agrirouter.response.ResponseEnvelope.application_message_id)
}
#if LANG_CXX11
inline void ResponseEnvelope::set_application_message_id(::std::string&& value) {
  
  application_message_id_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:agrirouter.response.ResponseEnvelope.application_message_id)
}
#endif
inline void ResponseEnvelope::set_application_message_id(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  application_message_id_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:agrirouter.response.ResponseEnvelope.application_message_id)
}
inline void ResponseEnvelope::set_application_message_id(const char* value, size_t size) {
  
  application_message_id_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:agrirouter.response.ResponseEnvelope.application_message_id)
}
inline ::std::string* ResponseEnvelope::mutable_application_message_id() {
  
  // @@protoc_insertion_point(field_mutable:agrirouter.response.ResponseEnvelope.application_message_id)
  return application_message_id_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* ResponseEnvelope::release_application_message_id() {
  // @@protoc_insertion_point(field_release:agrirouter.response.ResponseEnvelope.application_message_id)
  
  return application_message_id_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ResponseEnvelope::set_allocated_application_message_id(::std::string* application_message_id) {
  if (application_message_id != NULL) {
    
  } else {
    
  }
  application_message_id_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), application_message_id);
  // @@protoc_insertion_point(field_set_allocated:agrirouter.response.ResponseEnvelope.application_message_id)
}

// string message_id = 4;
inline void ResponseEnvelope::clear_message_id() {
  message_id_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& ResponseEnvelope::message_id() const {
  // @@protoc_insertion_point(field_get:agrirouter.response.ResponseEnvelope.message_id)
  return message_id_.GetNoArena();
}
inline void ResponseEnvelope::set_message_id(const ::std::string& value) {
  
  message_id_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:agrirouter.response.ResponseEnvelope.message_id)
}
#if LANG_CXX11
inline void ResponseEnvelope::set_message_id(::std::string&& value) {
  
  message_id_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:agrirouter.response.ResponseEnvelope.message_id)
}
#endif
inline void ResponseEnvelope::set_message_id(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  message_id_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:agrirouter.response.ResponseEnvelope.message_id)
}
inline void ResponseEnvelope::set_message_id(const char* value, size_t size) {
  
  message_id_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:agrirouter.response.ResponseEnvelope.message_id)
}
inline ::std::string* ResponseEnvelope::mutable_message_id() {
  
  // @@protoc_insertion_point(field_mutable:agrirouter.response.ResponseEnvelope.message_id)
  return message_id_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* ResponseEnvelope::release_message_id() {
  // @@protoc_insertion_point(field_release:agrirouter.response.ResponseEnvelope.message_id)
  
  return message_id_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ResponseEnvelope::set_allocated_message_id(::std::string* message_id) {
  if (message_id != NULL) {
    
  } else {
    
  }
  message_id_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), message_id);
  // @@protoc_insertion_point(field_set_allocated:agrirouter.response.ResponseEnvelope.message_id)
}

// .google.protobuf.Timestamp timestamp = 5;
inline bool ResponseEnvelope::has_timestamp() const {
  return this != internal_default_instance() && timestamp_ != NULL;
}
inline const ::google::protobuf::Timestamp& ResponseEnvelope::timestamp() const {
  const ::google::protobuf::Timestamp* p = timestamp_;
  // @@protoc_insertion_point(field_get:agrirouter.response.ResponseEnvelope.timestamp)
  return p != NULL ? *p : *reinterpret_cast<const ::google::protobuf::Timestamp*>(
      &::google::protobuf::_Timestamp_default_instance_);
}
inline ::google::protobuf::Timestamp* ResponseEnvelope::release_timestamp() {
  // @@protoc_insertion_point(field_release:agrirouter.response.ResponseEnvelope.timestamp)
  
  ::google::protobuf::Timestamp* temp = timestamp_;
  timestamp_ = NULL;
  return temp;
}
inline ::google::protobuf::Timestamp* ResponseEnvelope::mutable_timestamp() {
  
  if (timestamp_ == NULL) {
    timestamp_ = new ::google::protobuf::Timestamp;
  }
  // @@protoc_insertion_point(field_mutable:agrirouter.response.ResponseEnvelope.timestamp)
  return timestamp_;
}
inline void ResponseEnvelope::set_allocated_timestamp(::google::protobuf::Timestamp* timestamp) {
  ::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == NULL) {
    delete reinterpret_cast< ::google::protobuf::MessageLite*>(timestamp_);
  }
  if (timestamp) {
    ::google::protobuf::Arena* submessage_arena =
      reinterpret_cast< ::google::protobuf::MessageLite*>(timestamp)->GetArena();
    if (message_arena != submessage_arena) {
      timestamp = ::google::protobuf::internal::GetOwnedMessage(
          message_arena, timestamp, submessage_arena);
    }
    
  } else {
    
  }
  timestamp_ = timestamp;
  // @@protoc_insertion_point(field_set_allocated:agrirouter.response.ResponseEnvelope.timestamp)
}

// -------------------------------------------------------------------

// ResponsePayloadWrapper

// .google.protobuf.Any details = 1;
inline bool ResponsePayloadWrapper::has_details() const {
  return this != internal_default_instance() && details_ != NULL;
}
inline const ::google::protobuf::Any& ResponsePayloadWrapper::details() const {
  const ::google::protobuf::Any* p = details_;
  // @@protoc_insertion_point(field_get:agrirouter.response.ResponsePayloadWrapper.details)
  return p != NULL ? *p : *reinterpret_cast<const ::google::protobuf::Any*>(
      &::google::protobuf::_Any_default_instance_);
}
inline ::google::protobuf::Any* ResponsePayloadWrapper::release_details() {
  // @@protoc_insertion_point(field_release:agrirouter.response.ResponsePayloadWrapper.details)
  
  ::google::protobuf::Any* temp = details_;
  details_ = NULL;
  return temp;
}
inline ::google::protobuf::Any* ResponsePayloadWrapper::mutable_details() {
  
  if (details_ == NULL) {
    details_ = new ::google::protobuf::Any;
  }
  // @@protoc_insertion_point(field_mutable:agrirouter.response.ResponsePayloadWrapper.details)
  return details_;
}
inline void ResponsePayloadWrapper::set_allocated_details(::google::protobuf::Any* details) {
  ::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == NULL) {
    delete reinterpret_cast< ::google::protobuf::MessageLite*>(details_);
  }
  if (details) {
    ::google::protobuf::Arena* submessage_arena = NULL;
    if (message_arena != submessage_arena) {
      details = ::google::protobuf::internal::GetOwnedMessage(
          message_arena, details, submessage_arena);
    }
    
  } else {
    
  }
  details_ = details;
  // @@protoc_insertion_point(field_set_allocated:agrirouter.response.ResponsePayloadWrapper.details)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace response
}  // namespace agrirouter

namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::agrirouter::response::ResponseEnvelope_ResponseBodyType> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::agrirouter::response::ResponseEnvelope_ResponseBodyType>() {
  return ::agrirouter::response::ResponseEnvelope_ResponseBodyType_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_messaging_2fresponse_2fresponse_2eproto__INCLUDED
