// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: messaging/request/payload/endpoint/subscription.proto

#ifndef PROTOBUF_messaging_2frequest_2fpayload_2fendpoint_2fsubscription_2eproto__INCLUDED
#define PROTOBUF_messaging_2frequest_2fpayload_2fendpoint_2fsubscription_2eproto__INCLUDED

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
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace protobuf_messaging_2frequest_2fpayload_2fendpoint_2fsubscription_2eproto {
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
void InitDefaultsSubscription_MessageTypeSubscriptionItemImpl();
void InitDefaultsSubscription_MessageTypeSubscriptionItem();
void InitDefaultsSubscriptionImpl();
void InitDefaultsSubscription();
inline void InitDefaults() {
  InitDefaultsSubscription_MessageTypeSubscriptionItem();
  InitDefaultsSubscription();
}
}  // namespace protobuf_messaging_2frequest_2fpayload_2fendpoint_2fsubscription_2eproto
namespace agrirouter {
namespace request {
namespace payload {
namespace endpoint {
class Subscription;
class SubscriptionDefaultTypeInternal;
extern SubscriptionDefaultTypeInternal _Subscription_default_instance_;
class Subscription_MessageTypeSubscriptionItem;
class Subscription_MessageTypeSubscriptionItemDefaultTypeInternal;
extern Subscription_MessageTypeSubscriptionItemDefaultTypeInternal _Subscription_MessageTypeSubscriptionItem_default_instance_;
}  // namespace endpoint
}  // namespace payload
}  // namespace request
}  // namespace agrirouter
namespace agrirouter {
namespace request {
namespace payload {
namespace endpoint {

// ===================================================================

class Subscription_MessageTypeSubscriptionItem : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:agrirouter.request.payload.endpoint.Subscription.MessageTypeSubscriptionItem) */ {
 public:
  Subscription_MessageTypeSubscriptionItem();
  virtual ~Subscription_MessageTypeSubscriptionItem();

  Subscription_MessageTypeSubscriptionItem(const Subscription_MessageTypeSubscriptionItem& from);

  inline Subscription_MessageTypeSubscriptionItem& operator=(const Subscription_MessageTypeSubscriptionItem& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Subscription_MessageTypeSubscriptionItem(Subscription_MessageTypeSubscriptionItem&& from) noexcept
    : Subscription_MessageTypeSubscriptionItem() {
    *this = ::std::move(from);
  }

  inline Subscription_MessageTypeSubscriptionItem& operator=(Subscription_MessageTypeSubscriptionItem&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const Subscription_MessageTypeSubscriptionItem& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Subscription_MessageTypeSubscriptionItem* internal_default_instance() {
    return reinterpret_cast<const Subscription_MessageTypeSubscriptionItem*>(
               &_Subscription_MessageTypeSubscriptionItem_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(Subscription_MessageTypeSubscriptionItem* other);
  friend void swap(Subscription_MessageTypeSubscriptionItem& a, Subscription_MessageTypeSubscriptionItem& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Subscription_MessageTypeSubscriptionItem* New() const PROTOBUF_FINAL { return New(NULL); }

  Subscription_MessageTypeSubscriptionItem* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const Subscription_MessageTypeSubscriptionItem& from);
  void MergeFrom(const Subscription_MessageTypeSubscriptionItem& from);
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
  void InternalSwap(Subscription_MessageTypeSubscriptionItem* other);
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

  // repeated uint32 ddis = 2;
  int ddis_size() const;
  void clear_ddis();
  static const int kDdisFieldNumber = 2;
  ::google::protobuf::uint32 ddis(int index) const;
  void set_ddis(int index, ::google::protobuf::uint32 value);
  void add_ddis(::google::protobuf::uint32 value);
  const ::google::protobuf::RepeatedField< ::google::protobuf::uint32 >&
      ddis() const;
  ::google::protobuf::RepeatedField< ::google::protobuf::uint32 >*
      mutable_ddis();

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

  // bool position = 3;
  void clear_position();
  static const int kPositionFieldNumber = 3;
  bool position() const;
  void set_position(bool value);

  // @@protoc_insertion_point(class_scope:agrirouter.request.payload.endpoint.Subscription.MessageTypeSubscriptionItem)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedField< ::google::protobuf::uint32 > ddis_;
  mutable int _ddis_cached_byte_size_;
  ::google::protobuf::internal::ArenaStringPtr technical_message_type_;
  bool position_;
  mutable int _cached_size_;
  friend struct ::protobuf_messaging_2frequest_2fpayload_2fendpoint_2fsubscription_2eproto::TableStruct;
  friend void ::protobuf_messaging_2frequest_2fpayload_2fendpoint_2fsubscription_2eproto::InitDefaultsSubscription_MessageTypeSubscriptionItemImpl();
};
// -------------------------------------------------------------------

class Subscription : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:agrirouter.request.payload.endpoint.Subscription) */ {
 public:
  Subscription();
  virtual ~Subscription();

  Subscription(const Subscription& from);

  inline Subscription& operator=(const Subscription& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Subscription(Subscription&& from) noexcept
    : Subscription() {
    *this = ::std::move(from);
  }

  inline Subscription& operator=(Subscription&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const Subscription& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Subscription* internal_default_instance() {
    return reinterpret_cast<const Subscription*>(
               &_Subscription_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    1;

  void Swap(Subscription* other);
  friend void swap(Subscription& a, Subscription& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Subscription* New() const PROTOBUF_FINAL { return New(NULL); }

  Subscription* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const Subscription& from);
  void MergeFrom(const Subscription& from);
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
  void InternalSwap(Subscription* other);
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

  typedef Subscription_MessageTypeSubscriptionItem MessageTypeSubscriptionItem;

  // accessors -------------------------------------------------------

  // repeated .agrirouter.request.payload.endpoint.Subscription.MessageTypeSubscriptionItem technical_message_types = 1;
  int technical_message_types_size() const;
  void clear_technical_message_types();
  static const int kTechnicalMessageTypesFieldNumber = 1;
  const ::agrirouter::request::payload::endpoint::Subscription_MessageTypeSubscriptionItem& technical_message_types(int index) const;
  ::agrirouter::request::payload::endpoint::Subscription_MessageTypeSubscriptionItem* mutable_technical_message_types(int index);
  ::agrirouter::request::payload::endpoint::Subscription_MessageTypeSubscriptionItem* add_technical_message_types();
  ::google::protobuf::RepeatedPtrField< ::agrirouter::request::payload::endpoint::Subscription_MessageTypeSubscriptionItem >*
      mutable_technical_message_types();
  const ::google::protobuf::RepeatedPtrField< ::agrirouter::request::payload::endpoint::Subscription_MessageTypeSubscriptionItem >&
      technical_message_types() const;

  // @@protoc_insertion_point(class_scope:agrirouter.request.payload.endpoint.Subscription)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedPtrField< ::agrirouter::request::payload::endpoint::Subscription_MessageTypeSubscriptionItem > technical_message_types_;
  mutable int _cached_size_;
  friend struct ::protobuf_messaging_2frequest_2fpayload_2fendpoint_2fsubscription_2eproto::TableStruct;
  friend void ::protobuf_messaging_2frequest_2fpayload_2fendpoint_2fsubscription_2eproto::InitDefaultsSubscriptionImpl();
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Subscription_MessageTypeSubscriptionItem

// string technical_message_type = 1;
inline void Subscription_MessageTypeSubscriptionItem::clear_technical_message_type() {
  technical_message_type_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& Subscription_MessageTypeSubscriptionItem::technical_message_type() const {
  // @@protoc_insertion_point(field_get:agrirouter.request.payload.endpoint.Subscription.MessageTypeSubscriptionItem.technical_message_type)
  return technical_message_type_.GetNoArena();
}
inline void Subscription_MessageTypeSubscriptionItem::set_technical_message_type(const ::std::string& value) {
  
  technical_message_type_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:agrirouter.request.payload.endpoint.Subscription.MessageTypeSubscriptionItem.technical_message_type)
}
#if LANG_CXX11
inline void Subscription_MessageTypeSubscriptionItem::set_technical_message_type(::std::string&& value) {
  
  technical_message_type_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:agrirouter.request.payload.endpoint.Subscription.MessageTypeSubscriptionItem.technical_message_type)
}
#endif
inline void Subscription_MessageTypeSubscriptionItem::set_technical_message_type(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  technical_message_type_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:agrirouter.request.payload.endpoint.Subscription.MessageTypeSubscriptionItem.technical_message_type)
}
inline void Subscription_MessageTypeSubscriptionItem::set_technical_message_type(const char* value, size_t size) {
  
  technical_message_type_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:agrirouter.request.payload.endpoint.Subscription.MessageTypeSubscriptionItem.technical_message_type)
}
inline ::std::string* Subscription_MessageTypeSubscriptionItem::mutable_technical_message_type() {
  
  // @@protoc_insertion_point(field_mutable:agrirouter.request.payload.endpoint.Subscription.MessageTypeSubscriptionItem.technical_message_type)
  return technical_message_type_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Subscription_MessageTypeSubscriptionItem::release_technical_message_type() {
  // @@protoc_insertion_point(field_release:agrirouter.request.payload.endpoint.Subscription.MessageTypeSubscriptionItem.technical_message_type)
  
  return technical_message_type_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Subscription_MessageTypeSubscriptionItem::set_allocated_technical_message_type(::std::string* technical_message_type) {
  if (technical_message_type != NULL) {
    
  } else {
    
  }
  technical_message_type_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), technical_message_type);
  // @@protoc_insertion_point(field_set_allocated:agrirouter.request.payload.endpoint.Subscription.MessageTypeSubscriptionItem.technical_message_type)
}

// repeated uint32 ddis = 2;
inline int Subscription_MessageTypeSubscriptionItem::ddis_size() const {
  return ddis_.size();
}
inline void Subscription_MessageTypeSubscriptionItem::clear_ddis() {
  ddis_.Clear();
}
inline ::google::protobuf::uint32 Subscription_MessageTypeSubscriptionItem::ddis(int index) const {
  // @@protoc_insertion_point(field_get:agrirouter.request.payload.endpoint.Subscription.MessageTypeSubscriptionItem.ddis)
  return ddis_.Get(index);
}
inline void Subscription_MessageTypeSubscriptionItem::set_ddis(int index, ::google::protobuf::uint32 value) {
  ddis_.Set(index, value);
  // @@protoc_insertion_point(field_set:agrirouter.request.payload.endpoint.Subscription.MessageTypeSubscriptionItem.ddis)
}
inline void Subscription_MessageTypeSubscriptionItem::add_ddis(::google::protobuf::uint32 value) {
  ddis_.Add(value);
  // @@protoc_insertion_point(field_add:agrirouter.request.payload.endpoint.Subscription.MessageTypeSubscriptionItem.ddis)
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::uint32 >&
Subscription_MessageTypeSubscriptionItem::ddis() const {
  // @@protoc_insertion_point(field_list:agrirouter.request.payload.endpoint.Subscription.MessageTypeSubscriptionItem.ddis)
  return ddis_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::uint32 >*
Subscription_MessageTypeSubscriptionItem::mutable_ddis() {
  // @@protoc_insertion_point(field_mutable_list:agrirouter.request.payload.endpoint.Subscription.MessageTypeSubscriptionItem.ddis)
  return &ddis_;
}

// bool position = 3;
inline void Subscription_MessageTypeSubscriptionItem::clear_position() {
  position_ = false;
}
inline bool Subscription_MessageTypeSubscriptionItem::position() const {
  // @@protoc_insertion_point(field_get:agrirouter.request.payload.endpoint.Subscription.MessageTypeSubscriptionItem.position)
  return position_;
}
inline void Subscription_MessageTypeSubscriptionItem::set_position(bool value) {
  
  position_ = value;
  // @@protoc_insertion_point(field_set:agrirouter.request.payload.endpoint.Subscription.MessageTypeSubscriptionItem.position)
}

// -------------------------------------------------------------------

// Subscription

// repeated .agrirouter.request.payload.endpoint.Subscription.MessageTypeSubscriptionItem technical_message_types = 1;
inline int Subscription::technical_message_types_size() const {
  return technical_message_types_.size();
}
inline void Subscription::clear_technical_message_types() {
  technical_message_types_.Clear();
}
inline const ::agrirouter::request::payload::endpoint::Subscription_MessageTypeSubscriptionItem& Subscription::technical_message_types(int index) const {
  // @@protoc_insertion_point(field_get:agrirouter.request.payload.endpoint.Subscription.technical_message_types)
  return technical_message_types_.Get(index);
}
inline ::agrirouter::request::payload::endpoint::Subscription_MessageTypeSubscriptionItem* Subscription::mutable_technical_message_types(int index) {
  // @@protoc_insertion_point(field_mutable:agrirouter.request.payload.endpoint.Subscription.technical_message_types)
  return technical_message_types_.Mutable(index);
}
inline ::agrirouter::request::payload::endpoint::Subscription_MessageTypeSubscriptionItem* Subscription::add_technical_message_types() {
  // @@protoc_insertion_point(field_add:agrirouter.request.payload.endpoint.Subscription.technical_message_types)
  return technical_message_types_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::agrirouter::request::payload::endpoint::Subscription_MessageTypeSubscriptionItem >*
Subscription::mutable_technical_message_types() {
  // @@protoc_insertion_point(field_mutable_list:agrirouter.request.payload.endpoint.Subscription.technical_message_types)
  return &technical_message_types_;
}
inline const ::google::protobuf::RepeatedPtrField< ::agrirouter::request::payload::endpoint::Subscription_MessageTypeSubscriptionItem >&
Subscription::technical_message_types() const {
  // @@protoc_insertion_point(field_list:agrirouter.request.payload.endpoint.Subscription.technical_message_types)
  return technical_message_types_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace endpoint
}  // namespace payload
}  // namespace request
}  // namespace agrirouter

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_messaging_2frequest_2fpayload_2fendpoint_2fsubscription_2eproto__INCLUDED
