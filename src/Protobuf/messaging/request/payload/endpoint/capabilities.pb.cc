// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: messaging/request/payload/endpoint/capabilities.proto

#include "messaging/request/payload/endpoint/capabilities.pb.h"

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
class CapabilitySpecification_CapabilityDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<CapabilitySpecification_Capability>
      _instance;
} _CapabilitySpecification_Capability_default_instance_;
class CapabilitySpecificationDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<CapabilitySpecification>
      _instance;
} _CapabilitySpecification_default_instance_;
}  // namespace endpoint
}  // namespace payload
}  // namespace request
}  // namespace agrirouter
namespace protobuf_messaging_2frequest_2fpayload_2fendpoint_2fcapabilities_2eproto {
void InitDefaultsCapabilitySpecification_CapabilityImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  ::google::protobuf::internal::InitProtobufDefaultsForceUnique();
#else
  ::google::protobuf::internal::InitProtobufDefaults();
#endif  // GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  {
    void* ptr = &::agrirouter::request::payload::endpoint::_CapabilitySpecification_Capability_default_instance_;
    new (ptr) ::agrirouter::request::payload::endpoint::CapabilitySpecification_Capability();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::agrirouter::request::payload::endpoint::CapabilitySpecification_Capability::InitAsDefaultInstance();
}

void InitDefaultsCapabilitySpecification_Capability() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &InitDefaultsCapabilitySpecification_CapabilityImpl);
}

void InitDefaultsCapabilitySpecificationImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  ::google::protobuf::internal::InitProtobufDefaultsForceUnique();
#else
  ::google::protobuf::internal::InitProtobufDefaults();
#endif  // GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  protobuf_messaging_2frequest_2fpayload_2fendpoint_2fcapabilities_2eproto::InitDefaultsCapabilitySpecification_Capability();
  {
    void* ptr = &::agrirouter::request::payload::endpoint::_CapabilitySpecification_default_instance_;
    new (ptr) ::agrirouter::request::payload::endpoint::CapabilitySpecification();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::agrirouter::request::payload::endpoint::CapabilitySpecification::InitAsDefaultInstance();
}

void InitDefaultsCapabilitySpecification() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &InitDefaultsCapabilitySpecificationImpl);
}

::google::protobuf::Metadata file_level_metadata[2];
const ::google::protobuf::EnumDescriptor* file_level_enum_descriptors[1];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::agrirouter::request::payload::endpoint::CapabilitySpecification_Capability, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::agrirouter::request::payload::endpoint::CapabilitySpecification_Capability, technical_message_type_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::agrirouter::request::payload::endpoint::CapabilitySpecification_Capability, direction_),
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::agrirouter::request::payload::endpoint::CapabilitySpecification, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::agrirouter::request::payload::endpoint::CapabilitySpecification, capabilities_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::agrirouter::request::payload::endpoint::CapabilitySpecification, app_certification_id_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::agrirouter::request::payload::endpoint::CapabilitySpecification, app_certification_version_id_),
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::agrirouter::request::payload::endpoint::CapabilitySpecification_Capability)},
  { 7, -1, sizeof(::agrirouter::request::payload::endpoint::CapabilitySpecification)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::agrirouter::request::payload::endpoint::_CapabilitySpecification_Capability_default_instance_),
  reinterpret_cast<const ::google::protobuf::Message*>(&::agrirouter::request::payload::endpoint::_CapabilitySpecification_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  ::google::protobuf::MessageFactory* factory = NULL;
  AssignDescriptors(
      "messaging/request/payload/endpoint/capabilities.proto", schemas, file_default_instances, TableStruct::offsets, factory,
      file_level_metadata, file_level_enum_descriptors, NULL);
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
      "\n5messaging/request/payload/endpoint/cap"
      "abilities.proto\022#agrirouter.request.payl"
      "oad.endpoint\"\374\002\n\027CapabilitySpecification"
      "\022]\n\014capabilities\030\001 \003(\0132G.agrirouter.requ"
      "est.payload.endpoint.CapabilitySpecifica"
      "tion.Capability\022\034\n\024app_certification_id\030"
      "\002 \001(\t\022$\n\034app_certification_version_id\030\003 "
      "\001(\t\032\207\001\n\nCapability\022\036\n\026technical_message_"
      "type\030\001 \001(\t\022Y\n\tdirection\030\002 \001(\0162F.agrirout"
      "er.request.payload.endpoint.CapabilitySp"
      "ecification.Direction\"4\n\tDirection\022\010\n\004SE"
      "ND\020\000\022\013\n\007RECEIVE\020\001\022\020\n\014SEND_RECEIVE\020\002b\006pro"
      "to3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 483);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "messaging/request/payload/endpoint/capabilities.proto", &protobuf_RegisterTypes);
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
}  // namespace protobuf_messaging_2frequest_2fpayload_2fendpoint_2fcapabilities_2eproto
namespace agrirouter {
namespace request {
namespace payload {
namespace endpoint {
const ::google::protobuf::EnumDescriptor* CapabilitySpecification_Direction_descriptor() {
  protobuf_messaging_2frequest_2fpayload_2fendpoint_2fcapabilities_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_messaging_2frequest_2fpayload_2fendpoint_2fcapabilities_2eproto::file_level_enum_descriptors[0];
}
bool CapabilitySpecification_Direction_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
      return true;
    default:
      return false;
  }
}

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const CapabilitySpecification_Direction CapabilitySpecification::SEND;
const CapabilitySpecification_Direction CapabilitySpecification::RECEIVE;
const CapabilitySpecification_Direction CapabilitySpecification::SEND_RECEIVE;
const CapabilitySpecification_Direction CapabilitySpecification::Direction_MIN;
const CapabilitySpecification_Direction CapabilitySpecification::Direction_MAX;
const int CapabilitySpecification::Direction_ARRAYSIZE;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

// ===================================================================

void CapabilitySpecification_Capability::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int CapabilitySpecification_Capability::kTechnicalMessageTypeFieldNumber;
const int CapabilitySpecification_Capability::kDirectionFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

CapabilitySpecification_Capability::CapabilitySpecification_Capability()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    ::protobuf_messaging_2frequest_2fpayload_2fendpoint_2fcapabilities_2eproto::InitDefaultsCapabilitySpecification_Capability();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:agrirouter.request.payload.endpoint.CapabilitySpecification.Capability)
}
CapabilitySpecification_Capability::CapabilitySpecification_Capability(const CapabilitySpecification_Capability& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  technical_message_type_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.technical_message_type().size() > 0) {
    technical_message_type_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.technical_message_type_);
  }
  direction_ = from.direction_;
  // @@protoc_insertion_point(copy_constructor:agrirouter.request.payload.endpoint.CapabilitySpecification.Capability)
}

void CapabilitySpecification_Capability::SharedCtor() {
  technical_message_type_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  direction_ = 0;
  _cached_size_ = 0;
}

CapabilitySpecification_Capability::~CapabilitySpecification_Capability() {
  // @@protoc_insertion_point(destructor:agrirouter.request.payload.endpoint.CapabilitySpecification.Capability)
  SharedDtor();
}

void CapabilitySpecification_Capability::SharedDtor() {
  technical_message_type_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void CapabilitySpecification_Capability::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* CapabilitySpecification_Capability::descriptor() {
  ::protobuf_messaging_2frequest_2fpayload_2fendpoint_2fcapabilities_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_messaging_2frequest_2fpayload_2fendpoint_2fcapabilities_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const CapabilitySpecification_Capability& CapabilitySpecification_Capability::default_instance() {
  ::protobuf_messaging_2frequest_2fpayload_2fendpoint_2fcapabilities_2eproto::InitDefaultsCapabilitySpecification_Capability();
  return *internal_default_instance();
}

CapabilitySpecification_Capability* CapabilitySpecification_Capability::New(::google::protobuf::Arena* arena) const {
  CapabilitySpecification_Capability* n = new CapabilitySpecification_Capability;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void CapabilitySpecification_Capability::Clear() {
// @@protoc_insertion_point(message_clear_start:agrirouter.request.payload.endpoint.CapabilitySpecification.Capability)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  technical_message_type_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  direction_ = 0;
  _internal_metadata_.Clear();
}

bool CapabilitySpecification_Capability::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:agrirouter.request.payload.endpoint.CapabilitySpecification.Capability)
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
            "agrirouter.request.payload.endpoint.CapabilitySpecification.Capability.technical_message_type"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // .agrirouter.request.payload.endpoint.CapabilitySpecification.Direction direction = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(16u /* 16 & 0xFF */)) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          set_direction(static_cast< ::agrirouter::request::payload::endpoint::CapabilitySpecification_Direction >(value));
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
  // @@protoc_insertion_point(parse_success:agrirouter.request.payload.endpoint.CapabilitySpecification.Capability)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:agrirouter.request.payload.endpoint.CapabilitySpecification.Capability)
  return false;
#undef DO_
}

void CapabilitySpecification_Capability::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:agrirouter.request.payload.endpoint.CapabilitySpecification.Capability)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string technical_message_type = 1;
  if (this->technical_message_type().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->technical_message_type().data(), static_cast<int>(this->technical_message_type().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "agrirouter.request.payload.endpoint.CapabilitySpecification.Capability.technical_message_type");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->technical_message_type(), output);
  }

  // .agrirouter.request.payload.endpoint.CapabilitySpecification.Direction direction = 2;
  if (this->direction() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      2, this->direction(), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:agrirouter.request.payload.endpoint.CapabilitySpecification.Capability)
}

::google::protobuf::uint8* CapabilitySpecification_Capability::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:agrirouter.request.payload.endpoint.CapabilitySpecification.Capability)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string technical_message_type = 1;
  if (this->technical_message_type().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->technical_message_type().data(), static_cast<int>(this->technical_message_type().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "agrirouter.request.payload.endpoint.CapabilitySpecification.Capability.technical_message_type");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->technical_message_type(), target);
  }

  // .agrirouter.request.payload.endpoint.CapabilitySpecification.Direction direction = 2;
  if (this->direction() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      2, this->direction(), target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:agrirouter.request.payload.endpoint.CapabilitySpecification.Capability)
  return target;
}

size_t CapabilitySpecification_Capability::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:agrirouter.request.payload.endpoint.CapabilitySpecification.Capability)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // string technical_message_type = 1;
  if (this->technical_message_type().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->technical_message_type());
  }

  // .agrirouter.request.payload.endpoint.CapabilitySpecification.Direction direction = 2;
  if (this->direction() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::EnumSize(this->direction());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void CapabilitySpecification_Capability::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:agrirouter.request.payload.endpoint.CapabilitySpecification.Capability)
  GOOGLE_DCHECK_NE(&from, this);
  const CapabilitySpecification_Capability* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const CapabilitySpecification_Capability>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:agrirouter.request.payload.endpoint.CapabilitySpecification.Capability)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:agrirouter.request.payload.endpoint.CapabilitySpecification.Capability)
    MergeFrom(*source);
  }
}

void CapabilitySpecification_Capability::MergeFrom(const CapabilitySpecification_Capability& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:agrirouter.request.payload.endpoint.CapabilitySpecification.Capability)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.technical_message_type().size() > 0) {

    technical_message_type_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.technical_message_type_);
  }
  if (from.direction() != 0) {
    set_direction(from.direction());
  }
}

void CapabilitySpecification_Capability::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:agrirouter.request.payload.endpoint.CapabilitySpecification.Capability)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void CapabilitySpecification_Capability::CopyFrom(const CapabilitySpecification_Capability& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:agrirouter.request.payload.endpoint.CapabilitySpecification.Capability)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool CapabilitySpecification_Capability::IsInitialized() const {
  return true;
}

void CapabilitySpecification_Capability::Swap(CapabilitySpecification_Capability* other) {
  if (other == this) return;
  InternalSwap(other);
}
void CapabilitySpecification_Capability::InternalSwap(CapabilitySpecification_Capability* other) {
  using std::swap;
  technical_message_type_.Swap(&other->technical_message_type_);
  swap(direction_, other->direction_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata CapabilitySpecification_Capability::GetMetadata() const {
  protobuf_messaging_2frequest_2fpayload_2fendpoint_2fcapabilities_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_messaging_2frequest_2fpayload_2fendpoint_2fcapabilities_2eproto::file_level_metadata[kIndexInFileMessages];
}


// ===================================================================

void CapabilitySpecification::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int CapabilitySpecification::kCapabilitiesFieldNumber;
const int CapabilitySpecification::kAppCertificationIdFieldNumber;
const int CapabilitySpecification::kAppCertificationVersionIdFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

CapabilitySpecification::CapabilitySpecification()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    ::protobuf_messaging_2frequest_2fpayload_2fendpoint_2fcapabilities_2eproto::InitDefaultsCapabilitySpecification();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:agrirouter.request.payload.endpoint.CapabilitySpecification)
}
CapabilitySpecification::CapabilitySpecification(const CapabilitySpecification& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      capabilities_(from.capabilities_),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  app_certification_id_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.app_certification_id().size() > 0) {
    app_certification_id_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.app_certification_id_);
  }
  app_certification_version_id_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.app_certification_version_id().size() > 0) {
    app_certification_version_id_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.app_certification_version_id_);
  }
  // @@protoc_insertion_point(copy_constructor:agrirouter.request.payload.endpoint.CapabilitySpecification)
}

void CapabilitySpecification::SharedCtor() {
  app_certification_id_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  app_certification_version_id_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  _cached_size_ = 0;
}

CapabilitySpecification::~CapabilitySpecification() {
  // @@protoc_insertion_point(destructor:agrirouter.request.payload.endpoint.CapabilitySpecification)
  SharedDtor();
}

void CapabilitySpecification::SharedDtor() {
  app_certification_id_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  app_certification_version_id_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void CapabilitySpecification::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* CapabilitySpecification::descriptor() {
  ::protobuf_messaging_2frequest_2fpayload_2fendpoint_2fcapabilities_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_messaging_2frequest_2fpayload_2fendpoint_2fcapabilities_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const CapabilitySpecification& CapabilitySpecification::default_instance() {
  ::protobuf_messaging_2frequest_2fpayload_2fendpoint_2fcapabilities_2eproto::InitDefaultsCapabilitySpecification();
  return *internal_default_instance();
}

CapabilitySpecification* CapabilitySpecification::New(::google::protobuf::Arena* arena) const {
  CapabilitySpecification* n = new CapabilitySpecification;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void CapabilitySpecification::Clear() {
// @@protoc_insertion_point(message_clear_start:agrirouter.request.payload.endpoint.CapabilitySpecification)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  capabilities_.Clear();
  app_certification_id_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  app_certification_version_id_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  _internal_metadata_.Clear();
}

bool CapabilitySpecification::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:agrirouter.request.payload.endpoint.CapabilitySpecification)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .agrirouter.request.payload.endpoint.CapabilitySpecification.Capability capabilities = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u /* 10 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessage(input, add_capabilities()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // string app_certification_id = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(18u /* 18 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_app_certification_id()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->app_certification_id().data(), static_cast<int>(this->app_certification_id().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "agrirouter.request.payload.endpoint.CapabilitySpecification.app_certification_id"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // string app_certification_version_id = 3;
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(26u /* 26 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_app_certification_version_id()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->app_certification_version_id().data(), static_cast<int>(this->app_certification_version_id().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "agrirouter.request.payload.endpoint.CapabilitySpecification.app_certification_version_id"));
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
  // @@protoc_insertion_point(parse_success:agrirouter.request.payload.endpoint.CapabilitySpecification)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:agrirouter.request.payload.endpoint.CapabilitySpecification)
  return false;
#undef DO_
}

void CapabilitySpecification::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:agrirouter.request.payload.endpoint.CapabilitySpecification)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .agrirouter.request.payload.endpoint.CapabilitySpecification.Capability capabilities = 1;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->capabilities_size()); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->capabilities(static_cast<int>(i)), output);
  }

  // string app_certification_id = 2;
  if (this->app_certification_id().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->app_certification_id().data(), static_cast<int>(this->app_certification_id().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "agrirouter.request.payload.endpoint.CapabilitySpecification.app_certification_id");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->app_certification_id(), output);
  }

  // string app_certification_version_id = 3;
  if (this->app_certification_version_id().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->app_certification_version_id().data(), static_cast<int>(this->app_certification_version_id().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "agrirouter.request.payload.endpoint.CapabilitySpecification.app_certification_version_id");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      3, this->app_certification_version_id(), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:agrirouter.request.payload.endpoint.CapabilitySpecification)
}

::google::protobuf::uint8* CapabilitySpecification::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:agrirouter.request.payload.endpoint.CapabilitySpecification)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .agrirouter.request.payload.endpoint.CapabilitySpecification.Capability capabilities = 1;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->capabilities_size()); i < n; i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageToArray(
        1, this->capabilities(static_cast<int>(i)), deterministic, target);
  }

  // string app_certification_id = 2;
  if (this->app_certification_id().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->app_certification_id().data(), static_cast<int>(this->app_certification_id().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "agrirouter.request.payload.endpoint.CapabilitySpecification.app_certification_id");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->app_certification_id(), target);
  }

  // string app_certification_version_id = 3;
  if (this->app_certification_version_id().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->app_certification_version_id().data(), static_cast<int>(this->app_certification_version_id().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "agrirouter.request.payload.endpoint.CapabilitySpecification.app_certification_version_id");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->app_certification_version_id(), target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:agrirouter.request.payload.endpoint.CapabilitySpecification)
  return target;
}

size_t CapabilitySpecification::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:agrirouter.request.payload.endpoint.CapabilitySpecification)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // repeated .agrirouter.request.payload.endpoint.CapabilitySpecification.Capability capabilities = 1;
  {
    unsigned int count = static_cast<unsigned int>(this->capabilities_size());
    total_size += 1UL * count;
    for (unsigned int i = 0; i < count; i++) {
      total_size +=
        ::google::protobuf::internal::WireFormatLite::MessageSize(
          this->capabilities(static_cast<int>(i)));
    }
  }

  // string app_certification_id = 2;
  if (this->app_certification_id().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->app_certification_id());
  }

  // string app_certification_version_id = 3;
  if (this->app_certification_version_id().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->app_certification_version_id());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void CapabilitySpecification::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:agrirouter.request.payload.endpoint.CapabilitySpecification)
  GOOGLE_DCHECK_NE(&from, this);
  const CapabilitySpecification* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const CapabilitySpecification>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:agrirouter.request.payload.endpoint.CapabilitySpecification)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:agrirouter.request.payload.endpoint.CapabilitySpecification)
    MergeFrom(*source);
  }
}

void CapabilitySpecification::MergeFrom(const CapabilitySpecification& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:agrirouter.request.payload.endpoint.CapabilitySpecification)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  capabilities_.MergeFrom(from.capabilities_);
  if (from.app_certification_id().size() > 0) {

    app_certification_id_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.app_certification_id_);
  }
  if (from.app_certification_version_id().size() > 0) {

    app_certification_version_id_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.app_certification_version_id_);
  }
}

void CapabilitySpecification::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:agrirouter.request.payload.endpoint.CapabilitySpecification)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void CapabilitySpecification::CopyFrom(const CapabilitySpecification& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:agrirouter.request.payload.endpoint.CapabilitySpecification)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool CapabilitySpecification::IsInitialized() const {
  return true;
}

void CapabilitySpecification::Swap(CapabilitySpecification* other) {
  if (other == this) return;
  InternalSwap(other);
}
void CapabilitySpecification::InternalSwap(CapabilitySpecification* other) {
  using std::swap;
  capabilities_.InternalSwap(&other->capabilities_);
  app_certification_id_.Swap(&other->app_certification_id_);
  app_certification_version_id_.Swap(&other->app_certification_version_id_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata CapabilitySpecification::GetMetadata() const {
  protobuf_messaging_2frequest_2fpayload_2fendpoint_2fcapabilities_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_messaging_2frequest_2fpayload_2fendpoint_2fcapabilities_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace endpoint
}  // namespace payload
}  // namespace request
}  // namespace agrirouter

// @@protoc_insertion_point(global_scope)
