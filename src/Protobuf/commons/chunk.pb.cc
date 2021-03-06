// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: commons/chunk.proto

#include "commons/chunk.pb.h"

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
namespace commons {
class ChunkComponentDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<ChunkComponent>
      _instance;
} _ChunkComponent_default_instance_;
}  // namespace commons
}  // namespace agrirouter
namespace protobuf_commons_2fchunk_2eproto {
void InitDefaultsChunkComponentImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  ::google::protobuf::internal::InitProtobufDefaultsForceUnique();
#else
  ::google::protobuf::internal::InitProtobufDefaults();
#endif  // GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  {
    void* ptr = &::agrirouter::commons::_ChunkComponent_default_instance_;
    new (ptr) ::agrirouter::commons::ChunkComponent();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::agrirouter::commons::ChunkComponent::InitAsDefaultInstance();
}

void InitDefaultsChunkComponent() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &InitDefaultsChunkComponentImpl);
}

::google::protobuf::Metadata file_level_metadata[1];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::agrirouter::commons::ChunkComponent, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::agrirouter::commons::ChunkComponent, context_id_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::agrirouter::commons::ChunkComponent, current_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::agrirouter::commons::ChunkComponent, total_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::agrirouter::commons::ChunkComponent, total_size_),
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::agrirouter::commons::ChunkComponent)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::agrirouter::commons::_ChunkComponent_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  ::google::protobuf::MessageFactory* factory = NULL;
  AssignDescriptors(
      "commons/chunk.proto", schemas, file_default_instances, TableStruct::offsets, factory,
      file_level_metadata, NULL, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_PROTOBUF_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 1);
}

void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\023commons/chunk.proto\022\022agrirouter.common"
      "s\"X\n\016ChunkComponent\022\022\n\ncontext_id\030\001 \001(\t\022"
      "\017\n\007current\030\002 \001(\003\022\r\n\005total\030\003 \001(\003\022\022\n\ntotal"
      "_size\030\004 \001(\003b\006proto3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 139);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "commons/chunk.proto", &protobuf_RegisterTypes);
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
}  // namespace protobuf_commons_2fchunk_2eproto
namespace agrirouter {
namespace commons {

// ===================================================================

void ChunkComponent::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int ChunkComponent::kContextIdFieldNumber;
const int ChunkComponent::kCurrentFieldNumber;
const int ChunkComponent::kTotalFieldNumber;
const int ChunkComponent::kTotalSizeFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

ChunkComponent::ChunkComponent()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    ::protobuf_commons_2fchunk_2eproto::InitDefaultsChunkComponent();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:agrirouter.commons.ChunkComponent)
}
ChunkComponent::ChunkComponent(const ChunkComponent& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  context_id_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.context_id().size() > 0) {
    context_id_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.context_id_);
  }
  ::memcpy(&current_, &from.current_,
    static_cast<size_t>(reinterpret_cast<char*>(&total_size_) -
    reinterpret_cast<char*>(&current_)) + sizeof(total_size_));
  // @@protoc_insertion_point(copy_constructor:agrirouter.commons.ChunkComponent)
}

void ChunkComponent::SharedCtor() {
  context_id_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(&current_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&total_size_) -
      reinterpret_cast<char*>(&current_)) + sizeof(total_size_));
  _cached_size_ = 0;
}

ChunkComponent::~ChunkComponent() {
  // @@protoc_insertion_point(destructor:agrirouter.commons.ChunkComponent)
  SharedDtor();
}

void ChunkComponent::SharedDtor() {
  context_id_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void ChunkComponent::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ChunkComponent::descriptor() {
  ::protobuf_commons_2fchunk_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_commons_2fchunk_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const ChunkComponent& ChunkComponent::default_instance() {
  ::protobuf_commons_2fchunk_2eproto::InitDefaultsChunkComponent();
  return *internal_default_instance();
}

ChunkComponent* ChunkComponent::New(::google::protobuf::Arena* arena) const {
  ChunkComponent* n = new ChunkComponent;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void ChunkComponent::Clear() {
// @@protoc_insertion_point(message_clear_start:agrirouter.commons.ChunkComponent)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  context_id_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(&current_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&total_size_) -
      reinterpret_cast<char*>(&current_)) + sizeof(total_size_));
  _internal_metadata_.Clear();
}

bool ChunkComponent::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:agrirouter.commons.ChunkComponent)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // string context_id = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u /* 10 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_context_id()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->context_id().data(), static_cast<int>(this->context_id().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "agrirouter.commons.ChunkComponent.context_id"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // int64 current = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(16u /* 16 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &current_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // int64 total = 3;
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(24u /* 24 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &total_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // int64 total_size = 4;
      case 4: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(32u /* 32 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &total_size_)));
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
  // @@protoc_insertion_point(parse_success:agrirouter.commons.ChunkComponent)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:agrirouter.commons.ChunkComponent)
  return false;
#undef DO_
}

void ChunkComponent::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:agrirouter.commons.ChunkComponent)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string context_id = 1;
  if (this->context_id().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->context_id().data(), static_cast<int>(this->context_id().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "agrirouter.commons.ChunkComponent.context_id");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->context_id(), output);
  }

  // int64 current = 2;
  if (this->current() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(2, this->current(), output);
  }

  // int64 total = 3;
  if (this->total() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(3, this->total(), output);
  }

  // int64 total_size = 4;
  if (this->total_size() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(4, this->total_size(), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:agrirouter.commons.ChunkComponent)
}

::google::protobuf::uint8* ChunkComponent::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:agrirouter.commons.ChunkComponent)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string context_id = 1;
  if (this->context_id().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->context_id().data(), static_cast<int>(this->context_id().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "agrirouter.commons.ChunkComponent.context_id");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->context_id(), target);
  }

  // int64 current = 2;
  if (this->current() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(2, this->current(), target);
  }

  // int64 total = 3;
  if (this->total() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(3, this->total(), target);
  }

  // int64 total_size = 4;
  if (this->total_size() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(4, this->total_size(), target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:agrirouter.commons.ChunkComponent)
  return target;
}

size_t ChunkComponent::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:agrirouter.commons.ChunkComponent)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // string context_id = 1;
  if (this->context_id().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->context_id());
  }

  // int64 current = 2;
  if (this->current() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int64Size(
        this->current());
  }

  // int64 total = 3;
  if (this->total() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int64Size(
        this->total());
  }

  // int64 total_size = 4;
  if (this->total_size() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int64Size(
        this->total_size());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void ChunkComponent::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:agrirouter.commons.ChunkComponent)
  GOOGLE_DCHECK_NE(&from, this);
  const ChunkComponent* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const ChunkComponent>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:agrirouter.commons.ChunkComponent)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:agrirouter.commons.ChunkComponent)
    MergeFrom(*source);
  }
}

void ChunkComponent::MergeFrom(const ChunkComponent& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:agrirouter.commons.ChunkComponent)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.context_id().size() > 0) {

    context_id_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.context_id_);
  }
  if (from.current() != 0) {
    set_current(from.current());
  }
  if (from.total() != 0) {
    set_total(from.total());
  }
  if (from.total_size() != 0) {
    set_total_size(from.total_size());
  }
}

void ChunkComponent::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:agrirouter.commons.ChunkComponent)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ChunkComponent::CopyFrom(const ChunkComponent& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:agrirouter.commons.ChunkComponent)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ChunkComponent::IsInitialized() const {
  return true;
}

void ChunkComponent::Swap(ChunkComponent* other) {
  if (other == this) return;
  InternalSwap(other);
}
void ChunkComponent::InternalSwap(ChunkComponent* other) {
  using std::swap;
  context_id_.Swap(&other->context_id_);
  swap(current_, other->current_);
  swap(total_, other->total_);
  swap(total_size_, other->total_size_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata ChunkComponent::GetMetadata() const {
  protobuf_commons_2fchunk_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_commons_2fchunk_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace commons
}  // namespace agrirouter

// @@protoc_insertion_point(global_scope)
