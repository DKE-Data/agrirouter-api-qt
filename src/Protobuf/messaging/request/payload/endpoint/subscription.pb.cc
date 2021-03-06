// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: messaging/request/payload/endpoint/subscription.proto

#include "messaging/request/payload/endpoint/subscription.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// This is a temporary google only hack
#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
#include "third_party/protobuf/version.h"
#endif
// @@protoc_insertion_point(includes)
namespace agrirouter {
namespace request {
namespace payload {
namespace endpoint {
class Subscription_MessageTypeSubscriptionItemDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<Subscription_MessageTypeSubscriptionItem>
      _instance;
} _Subscription_MessageTypeSubscriptionItem_default_instance_;
class SubscriptionDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<Subscription>
      _instance;
} _Subscription_default_instance_;
}  // namespace endpoint
}  // namespace payload
}  // namespace request
}  // namespace agrirouter
namespace protobuf_messaging_2frequest_2fpayload_2fendpoint_2fsubscription_2eproto {
void InitDefaultsSubscription_MessageTypeSubscriptionItemImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  ::google::protobuf::internal::InitProtobufDefaultsForceUnique();
#else
  ::google::protobuf::internal::InitProtobufDefaults();
#endif  // GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  {
    void* ptr = &::agrirouter::request::payload::endpoint::_Subscription_MessageTypeSubscriptionItem_default_instance_;
    new (ptr) ::agrirouter::request::payload::endpoint::Subscription_MessageTypeSubscriptionItem();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::agrirouter::request::payload::endpoint::Subscription_MessageTypeSubscriptionItem::InitAsDefaultInstance();
}

void InitDefaultsSubscription_MessageTypeSubscriptionItem() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &InitDefaultsSubscription_MessageTypeSubscriptionItemImpl);
}

void InitDefaultsSubscriptionImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  ::google::protobuf::internal::InitProtobufDefaultsForceUnique();
#else
  ::google::protobuf::internal::InitProtobufDefaults();
#endif  // GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  protobuf_messaging_2frequest_2fpayload_2fendpoint_2fsubscription_2eproto::InitDefaultsSubscription_MessageTypeSubscriptionItem();
  {
    void* ptr = &::agrirouter::request::payload::endpoint::_Subscription_default_instance_;
    new (ptr) ::agrirouter::request::payload::endpoint::Subscription();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::agrirouter::request::payload::endpoint::Subscription::InitAsDefaultInstance();
}

void InitDefaultsSubscription() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &InitDefaultsSubscriptionImpl);
}

::google::protobuf::Metadata file_level_metadata[2];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::agrirouter::request::payload::endpoint::Subscription_MessageTypeSubscriptionItem, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::agrirouter::request::payload::endpoint::Subscription_MessageTypeSubscriptionItem, technical_message_type_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::agrirouter::request::payload::endpoint::Subscription_MessageTypeSubscriptionItem, ddis_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::agrirouter::request::payload::endpoint::Subscription_MessageTypeSubscriptionItem, position_),
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::agrirouter::request::payload::endpoint::Subscription, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::agrirouter::request::payload::endpoint::Subscription, technical_message_types_),
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::agrirouter::request::payload::endpoint::Subscription_MessageTypeSubscriptionItem)},
  { 8, -1, sizeof(::agrirouter::request::payload::endpoint::Subscription)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::agrirouter::request::payload::endpoint::_Subscription_MessageTypeSubscriptionItem_default_instance_),
  reinterpret_cast<const ::google::protobuf::Message*>(&::agrirouter::request::payload::endpoint::_Subscription_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  ::google::protobuf::MessageFactory* factory = NULL;
  AssignDescriptors(
      "messaging/request/payload/endpoint/subscription.proto", schemas, file_default_instances, TableStruct::offsets, factory,
      file_level_metadata, NULL, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_PROTOBUF_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 2);
}

void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n5messaging/request/payload/endpoint/sub"
      "scription.proto\022#agrirouter.request.payl"
      "oad.endpoint\"\335\001\n\014Subscription\022n\n\027technic"
      "al_message_types\030\001 \003(\0132M.agrirouter.requ"
      "est.payload.endpoint.Subscription.Messag"
      "eTypeSubscriptionItem\032]\n\033MessageTypeSubs"
      "criptionItem\022\036\n\026technical_message_type\030\001"
      " \001(\t\022\014\n\004ddis\030\002 \003(\r\022\020\n\010position\030\003 \001(\010b\006pr"
      "oto3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 324);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "messaging/request/payload/endpoint/subscription.proto", &protobuf_RegisterTypes);
}

void AddDescriptors() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at dynamic initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;
}  // namespace protobuf_messaging_2frequest_2fpayload_2fendpoint_2fsubscription_2eproto
namespace agrirouter {
namespace request {
namespace payload {
namespace endpoint {

// ===================================================================

void Subscription_MessageTypeSubscriptionItem::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int Subscription_MessageTypeSubscriptionItem::kTechnicalMessageTypeFieldNumber;
const int Subscription_MessageTypeSubscriptionItem::kDdisFieldNumber;
const int Subscription_MessageTypeSubscriptionItem::kPositionFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

Subscription_MessageTypeSubscriptionItem::Subscription_MessageTypeSubscriptionItem()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    ::protobuf_messaging_2frequest_2fpayload_2fendpoint_2fsubscription_2eproto::InitDefaultsSubscription_MessageTypeSubscriptionItem();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:agrirouter.request.payload.endpoint.Subscription.MessageTypeSubscriptionItem)
}
Subscription_MessageTypeSubscriptionItem::Subscription_MessageTypeSubscriptionItem(const Subscription_MessageTypeSubscriptionItem& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      ddis_(from.ddis_),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  technical_message_type_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.technical_message_type().size() > 0) {
    technical_message_type_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.technical_message_type_);
  }
  position_ = from.position_;
  // @@protoc_insertion_point(copy_constructor:agrirouter.request.payload.endpoint.Subscription.MessageTypeSubscriptionItem)
}

void Subscription_MessageTypeSubscriptionItem::SharedCtor() {
  technical_message_type_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  position_ = false;
  _cached_size_ = 0;
}

Subscription_MessageTypeSubscriptionItem::~Subscription_MessageTypeSubscriptionItem() {
  // @@protoc_insertion_point(destructor:agrirouter.request.payload.endpoint.Subscription.MessageTypeSubscriptionItem)
  SharedDtor();
}

void Subscription_MessageTypeSubscriptionItem::SharedDtor() {
  technical_message_type_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void Subscription_MessageTypeSubscriptionItem::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Subscription_MessageTypeSubscriptionItem::descriptor() {
  ::protobuf_messaging_2frequest_2fpayload_2fendpoint_2fsubscription_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_messaging_2frequest_2fpayload_2fendpoint_2fsubscription_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const Subscription_MessageTypeSubscriptionItem& Subscription_MessageTypeSubscriptionItem::default_instance() {
  ::protobuf_messaging_2frequest_2fpayload_2fendpoint_2fsubscription_2eproto::InitDefaultsSubscription_MessageTypeSubscriptionItem();
  return *internal_default_instance();
}

Subscription_MessageTypeSubscriptionItem* Subscription_MessageTypeSubscriptionItem::New(::google::protobuf::Arena* arena) const {
  Subscription_MessageTypeSubscriptionItem* n = new Subscription_MessageTypeSubscriptionItem;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void Subscription_MessageTypeSubscriptionItem::Clear() {
// @@protoc_insertion_point(message_clear_start:agrirouter.request.payload.endpoint.Subscription.MessageTypeSubscriptionItem)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ddis_.Clear();
  technical_message_type_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  position_ = false;
  _internal_metadata_.Clear();
}

bool Subscription_MessageTypeSubscriptionItem::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:agrirouter.request.payload.endpoint.Subscription.MessageTypeSubscriptionItem)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // string technical_message_type = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u /* 10 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_technical_message_type()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->technical_message_type().data(), static_cast<int>(this->technical_message_type().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "agrirouter.request.payload.endpoint.Subscription.MessageTypeSubscriptionItem.technical_message_type"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // repeated uint32 ddis = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(18u /* 18 & 0xFF */)) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, this->mutable_ddis())));
        } else if (
            static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(16u /* 16 & 0xFF */)) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitiveNoInline<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 1, 18u, input, this->mutable_ddis())));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // bool position = 3;
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(24u /* 24 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &position_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:agrirouter.request.payload.endpoint.Subscription.MessageTypeSubscriptionItem)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:agrirouter.request.payload.endpoint.Subscription.MessageTypeSubscriptionItem)
  return false;
#undef DO_
}

void Subscription_MessageTypeSubscriptionItem::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:agrirouter.request.payload.endpoint.Subscription.MessageTypeSubscriptionItem)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string technical_message_type = 1;
  if (this->technical_message_type().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->technical_message_type().data(), static_cast<int>(this->technical_message_type().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "agrirouter.request.payload.endpoint.Subscription.MessageTypeSubscriptionItem.technical_message_type");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->technical_message_type(), output);
  }

  // repeated uint32 ddis = 2;
  if (this->ddis_size() > 0) {
    ::google::protobuf::internal::WireFormatLite::WriteTag(2, ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
    output->WriteVarint32(static_cast< ::google::protobuf::uint32>(
        _ddis_cached_byte_size_));
  }
  for (int i = 0, n = this->ddis_size(); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32NoTag(
      this->ddis(i), output);
  }

  // bool position = 3;
  if (this->position() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(3, this->position(), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:agrirouter.request.payload.endpoint.Subscription.MessageTypeSubscriptionItem)
}

::google::protobuf::uint8* Subscription_MessageTypeSubscriptionItem::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:agrirouter.request.payload.endpoint.Subscription.MessageTypeSubscriptionItem)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string technical_message_type = 1;
  if (this->technical_message_type().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->technical_message_type().data(), static_cast<int>(this->technical_message_type().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "agrirouter.request.payload.endpoint.Subscription.MessageTypeSubscriptionItem.technical_message_type");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->technical_message_type(), target);
  }

  // repeated uint32 ddis = 2;
  if (this->ddis_size() > 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(
      2,
      ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED,
      target);
    target = ::google::protobuf::io::CodedOutputStream::WriteVarint32ToArray(
        static_cast< ::google::protobuf::int32>(
            _ddis_cached_byte_size_), target);
    target = ::google::protobuf::internal::WireFormatLite::
      WriteUInt32NoTagToArray(this->ddis_, target);
  }

  // bool position = 3;
  if (this->position() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(3, this->position(), target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:agrirouter.request.payload.endpoint.Subscription.MessageTypeSubscriptionItem)
  return target;
}

size_t Subscription_MessageTypeSubscriptionItem::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:agrirouter.request.payload.endpoint.Subscription.MessageTypeSubscriptionItem)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // repeated uint32 ddis = 2;
  {
    size_t data_size = ::google::protobuf::internal::WireFormatLite::
      UInt32Size(this->ddis_);
    if (data_size > 0) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
            static_cast< ::google::protobuf::int32>(data_size));
    }
    int cached_size = ::google::protobuf::internal::ToCachedSize(data_size);
    GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
    _ddis_cached_byte_size_ = cached_size;
    GOOGLE_SAFE_CONCURRENT_WRITES_END();
    total_size += data_size;
  }

  // string technical_message_type = 1;
  if (this->technical_message_type().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->technical_message_type());
  }

  // bool position = 3;
  if (this->position() != 0) {
    total_size += 1 + 1;
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Subscription_MessageTypeSubscriptionItem::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:agrirouter.request.payload.endpoint.Subscription.MessageTypeSubscriptionItem)
  GOOGLE_DCHECK_NE(&from, this);
  const Subscription_MessageTypeSubscriptionItem* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const Subscription_MessageTypeSubscriptionItem>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:agrirouter.request.payload.endpoint.Subscription.MessageTypeSubscriptionItem)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:agrirouter.request.payload.endpoint.Subscription.MessageTypeSubscriptionItem)
    MergeFrom(*source);
  }
}

void Subscription_MessageTypeSubscriptionItem::MergeFrom(const Subscription_MessageTypeSubscriptionItem& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:agrirouter.request.payload.endpoint.Subscription.MessageTypeSubscriptionItem)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  ddis_.MergeFrom(from.ddis_);
  if (from.technical_message_type().size() > 0) {

    technical_message_type_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.technical_message_type_);
  }
  if (from.position() != 0) {
    set_position(from.position());
  }
}

void Subscription_MessageTypeSubscriptionItem::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:agrirouter.request.payload.endpoint.Subscription.MessageTypeSubscriptionItem)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Subscription_MessageTypeSubscriptionItem::CopyFrom(const Subscription_MessageTypeSubscriptionItem& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:agrirouter.request.payload.endpoint.Subscription.MessageTypeSubscriptionItem)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Subscription_MessageTypeSubscriptionItem::IsInitialized() const {
  return true;
}

void Subscription_MessageTypeSubscriptionItem::Swap(Subscription_MessageTypeSubscriptionItem* other) {
  if (other == this) return;
  InternalSwap(other);
}
void Subscription_MessageTypeSubscriptionItem::InternalSwap(Subscription_MessageTypeSubscriptionItem* other) {
  using std::swap;
  ddis_.InternalSwap(&other->ddis_);
  technical_message_type_.Swap(&other->technical_message_type_);
  swap(position_, other->position_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata Subscription_MessageTypeSubscriptionItem::GetMetadata() const {
  protobuf_messaging_2frequest_2fpayload_2fendpoint_2fsubscription_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_messaging_2frequest_2fpayload_2fendpoint_2fsubscription_2eproto::file_level_metadata[kIndexInFileMessages];
}


// ===================================================================

void Subscription::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int Subscription::kTechnicalMessageTypesFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

Subscription::Subscription()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    ::protobuf_messaging_2frequest_2fpayload_2fendpoint_2fsubscription_2eproto::InitDefaultsSubscription();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:agrirouter.request.payload.endpoint.Subscription)
}
Subscription::Subscription(const Subscription& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      technical_message_types_(from.technical_message_types_),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:agrirouter.request.payload.endpoint.Subscription)
}

void Subscription::SharedCtor() {
  _cached_size_ = 0;
}

Subscription::~Subscription() {
  // @@protoc_insertion_point(destructor:agrirouter.request.payload.endpoint.Subscription)
  SharedDtor();
}

void Subscription::SharedDtor() {
}

void Subscription::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Subscription::descriptor() {
  ::protobuf_messaging_2frequest_2fpayload_2fendpoint_2fsubscription_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_messaging_2frequest_2fpayload_2fendpoint_2fsubscription_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const Subscription& Subscription::default_instance() {
  ::protobuf_messaging_2frequest_2fpayload_2fendpoint_2fsubscription_2eproto::InitDefaultsSubscription();
  return *internal_default_instance();
}

Subscription* Subscription::New(::google::protobuf::Arena* arena) const {
  Subscription* n = new Subscription;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void Subscription::Clear() {
// @@protoc_insertion_point(message_clear_start:agrirouter.request.payload.endpoint.Subscription)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  technical_message_types_.Clear();
  _internal_metadata_.Clear();
}

bool Subscription::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:agrirouter.request.payload.endpoint.Subscription)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .agrirouter.request.payload.endpoint.Subscription.MessageTypeSubscriptionItem technical_message_types = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u /* 10 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessage(input, add_technical_message_types()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:agrirouter.request.payload.endpoint.Subscription)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:agrirouter.request.payload.endpoint.Subscription)
  return false;
#undef DO_
}

void Subscription::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:agrirouter.request.payload.endpoint.Subscription)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .agrirouter.request.payload.endpoint.Subscription.MessageTypeSubscriptionItem technical_message_types = 1;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->technical_message_types_size()); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->technical_message_types(static_cast<int>(i)), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:agrirouter.request.payload.endpoint.Subscription)
}

::google::protobuf::uint8* Subscription::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:agrirouter.request.payload.endpoint.Subscription)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .agrirouter.request.payload.endpoint.Subscription.MessageTypeSubscriptionItem technical_message_types = 1;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->technical_message_types_size()); i < n; i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageToArray(
        1, this->technical_message_types(static_cast<int>(i)), deterministic, target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:agrirouter.request.payload.endpoint.Subscription)
  return target;
}

size_t Subscription::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:agrirouter.request.payload.endpoint.Subscription)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // repeated .agrirouter.request.payload.endpoint.Subscription.MessageTypeSubscriptionItem technical_message_types = 1;
  {
    unsigned int count = static_cast<unsigned int>(this->technical_message_types_size());
    total_size += 1UL * count;
    for (unsigned int i = 0; i < count; i++) {
      total_size +=
        ::google::protobuf::internal::WireFormatLite::MessageSize(
          this->technical_message_types(static_cast<int>(i)));
    }
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Subscription::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:agrirouter.request.payload.endpoint.Subscription)
  GOOGLE_DCHECK_NE(&from, this);
  const Subscription* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const Subscription>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:agrirouter.request.payload.endpoint.Subscription)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:agrirouter.request.payload.endpoint.Subscription)
    MergeFrom(*source);
  }
}

void Subscription::MergeFrom(const Subscription& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:agrirouter.request.payload.endpoint.Subscription)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  technical_message_types_.MergeFrom(from.technical_message_types_);
}

void Subscription::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:agrirouter.request.payload.endpoint.Subscription)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Subscription::CopyFrom(const Subscription& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:agrirouter.request.payload.endpoint.Subscription)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Subscription::IsInitialized() const {
  return true;
}

void Subscription::Swap(Subscription* other) {
  if (other == this) return;
  InternalSwap(other);
}
void Subscription::InternalSwap(Subscription* other) {
  using std::swap;
  technical_message_types_.InternalSwap(&other->technical_message_types_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata Subscription::GetMetadata() const {
  protobuf_messaging_2frequest_2fpayload_2fendpoint_2fsubscription_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_messaging_2frequest_2fpayload_2fendpoint_2fsubscription_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace endpoint
}  // namespace payload
}  // namespace request
}  // namespace agrirouter

// @@protoc_insertion_point(global_scope)
