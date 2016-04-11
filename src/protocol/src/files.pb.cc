// Generated by the protocol buffer compiler.  DO NOT EDIT!

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "files.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
// @@protoc_insertion_point(includes)

namespace framework {

void protobuf_ShutdownFile_files_2eproto() {
  delete FileItem::default_instance_;
  delete FileList::default_instance_;
}

void protobuf_AddDesc_files_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  FileItem::default_instance_ = new FileItem();
  FileList::default_instance_ = new FileList();
  FileItem::default_instance_->InitAsDefaultInstance();
  FileList::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_files_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_files_2eproto {
  StaticDescriptorInitializer_files_2eproto() {
    protobuf_AddDesc_files_2eproto();
  }
} static_descriptor_initializer_files_2eproto_;

bool FileStorage_IsValid(int value) {
  switch(value) {
    case 1:
    case 2:
    case 3:
      return true;
    default:
      return false;
  }
}


// ===================================================================

#ifndef _MSC_VER
const int FileItem::kUrlFieldNumber;
const int FileItem::kMd5FieldNumber;
const int FileItem::kSizeFieldNumber;
const int FileItem::kWhereFieldNumber;
#endif  // !_MSC_VER

FileItem::FileItem()
  : ::google::protobuf::MessageLite() {
  SharedCtor();
}

void FileItem::InitAsDefaultInstance() {
}

FileItem::FileItem(const FileItem& from)
  : ::google::protobuf::MessageLite() {
  SharedCtor();
  MergeFrom(from);
}

void FileItem::SharedCtor() {
  _cached_size_ = 0;
  url_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  md5_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  size_ = 0;
  where_ = 1;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

FileItem::~FileItem() {
  SharedDtor();
}

void FileItem::SharedDtor() {
  if (url_ != &::google::protobuf::internal::kEmptyString) {
    delete url_;
  }
  if (md5_ != &::google::protobuf::internal::kEmptyString) {
    delete md5_;
  }
  if (this != default_instance_) {
  }
}

void FileItem::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const FileItem& FileItem::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_files_2eproto();  return *default_instance_;
}

FileItem* FileItem::default_instance_ = NULL;

FileItem* FileItem::New() const {
  return new FileItem;
}

void FileItem::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (has_url()) {
      if (url_ != &::google::protobuf::internal::kEmptyString) {
        url_->clear();
      }
    }
    if (has_md5()) {
      if (md5_ != &::google::protobuf::internal::kEmptyString) {
        md5_->clear();
      }
    }
    size_ = 0;
    where_ = 1;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

bool FileItem::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required string url = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_url()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_md5;
        break;
      }
      
      // required string md5 = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_md5:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_md5()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(24)) goto parse_size;
        break;
      }
      
      // required int32 size = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_size:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &size_)));
          set_has_size();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(32)) goto parse_where;
        break;
      }
      
      // required .framework.FileStorage where = 4;
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_where:
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (framework::FileStorage_IsValid(value)) {
            set_where(static_cast< framework::FileStorage >(value));
          }
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }
      
      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void FileItem::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required string url = 1;
  if (has_url()) {
    ::google::protobuf::internal::WireFormatLite::WriteString(
      1, this->url(), output);
  }
  
  // required string md5 = 2;
  if (has_md5()) {
    ::google::protobuf::internal::WireFormatLite::WriteString(
      2, this->md5(), output);
  }
  
  // required int32 size = 3;
  if (has_size()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(3, this->size(), output);
  }
  
  // required .framework.FileStorage where = 4;
  if (has_where()) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      4, this->where(), output);
  }
  
}

int FileItem::ByteSize() const {
  int total_size = 0;
  
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required string url = 1;
    if (has_url()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->url());
    }
    
    // required string md5 = 2;
    if (has_md5()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->md5());
    }
    
    // required int32 size = 3;
    if (has_size()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->size());
    }
    
    // required .framework.FileStorage where = 4;
    if (has_where()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->where());
    }
    
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void FileItem::CheckTypeAndMergeFrom(
    const ::google::protobuf::MessageLite& from) {
  MergeFrom(*::google::protobuf::down_cast<const FileItem*>(&from));
}

void FileItem::MergeFrom(const FileItem& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_url()) {
      set_url(from.url());
    }
    if (from.has_md5()) {
      set_md5(from.md5());
    }
    if (from.has_size()) {
      set_size(from.size());
    }
    if (from.has_where()) {
      set_where(from.where());
    }
  }
}

void FileItem::CopyFrom(const FileItem& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool FileItem::IsInitialized() const {
  if ((_has_bits_[0] & 0x0000000f) != 0x0000000f) return false;
  
  return true;
}

void FileItem::Swap(FileItem* other) {
  if (other != this) {
    std::swap(url_, other->url_);
    std::swap(md5_, other->md5_);
    std::swap(size_, other->size_);
    std::swap(where_, other->where_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::std::string FileItem::GetTypeName() const {
  return "framework.FileItem";
}


// ===================================================================

#ifndef _MSC_VER
const int FileList::kVersionFieldNumber;
const int FileList::kVersionNameFieldNumber;
const int FileList::kFilesFieldNumber;
const int FileList::kPkgVersionFieldNumber;
const int FileList::kPlatformFieldNumber;
const int FileList::kConfigVersionFieldNumber;
const int FileList::kExtendDataFieldNumber;
#endif  // !_MSC_VER

FileList::FileList()
  : ::google::protobuf::MessageLite() {
  SharedCtor();
}

void FileList::InitAsDefaultInstance() {
}

FileList::FileList(const FileList& from)
  : ::google::protobuf::MessageLite() {
  SharedCtor();
  MergeFrom(from);
}

void FileList::SharedCtor() {
  _cached_size_ = 0;
  version_ = 0;
  version_name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  pkg_version_ = 0;
  platform_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  config_version_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

FileList::~FileList() {
  SharedDtor();
}

void FileList::SharedDtor() {
  if (version_name_ != &::google::protobuf::internal::kEmptyString) {
    delete version_name_;
  }
  if (platform_ != &::google::protobuf::internal::kEmptyString) {
    delete platform_;
  }
  if (this != default_instance_) {
  }
}

void FileList::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const FileList& FileList::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_files_2eproto();  return *default_instance_;
}

FileList* FileList::default_instance_ = NULL;

FileList* FileList::New() const {
  return new FileList;
}

void FileList::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    version_ = 0;
    if (has_version_name()) {
      if (version_name_ != &::google::protobuf::internal::kEmptyString) {
        version_name_->clear();
      }
    }
    pkg_version_ = 0;
    if (has_platform()) {
      if (platform_ != &::google::protobuf::internal::kEmptyString) {
        platform_->clear();
      }
    }
    config_version_ = 0;
  }
  files_.Clear();
  extend_data_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

bool FileList::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required int32 version = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &version_)));
          set_has_version();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_version_name;
        break;
      }
      
      // required string version_name = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_version_name:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_version_name()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(26)) goto parse_files;
        break;
      }
      
      // repeated .framework.FileItem files = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_files:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_files()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(26)) goto parse_files;
        if (input->ExpectTag(32)) goto parse_pkg_version;
        break;
      }
      
      // optional int32 pkg_version = 4;
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_pkg_version:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &pkg_version_)));
          set_has_pkg_version();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(42)) goto parse_platform;
        break;
      }
      
      // optional string platform = 5;
      case 5: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_platform:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_platform()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(48)) goto parse_config_version;
        break;
      }
      
      // optional int32 config_version = 6;
      case 6: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_config_version:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &config_version_)));
          set_has_config_version();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(58)) goto parse_extend_data;
        break;
      }
      
      // repeated string extend_data = 7;
      case 7: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_extend_data:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->add_extend_data()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(58)) goto parse_extend_data;
        if (input->ExpectAtEnd()) return true;
        break;
      }
      
      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void FileList::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required int32 version = 1;
  if (has_version()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->version(), output);
  }
  
  // required string version_name = 2;
  if (has_version_name()) {
    ::google::protobuf::internal::WireFormatLite::WriteString(
      2, this->version_name(), output);
  }
  
  // repeated .framework.FileItem files = 3;
  for (int i = 0; i < this->files_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessage(
      3, this->files(i), output);
  }
  
  // optional int32 pkg_version = 4;
  if (has_pkg_version()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(4, this->pkg_version(), output);
  }
  
  // optional string platform = 5;
  if (has_platform()) {
    ::google::protobuf::internal::WireFormatLite::WriteString(
      5, this->platform(), output);
  }
  
  // optional int32 config_version = 6;
  if (has_config_version()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(6, this->config_version(), output);
  }
  
  // repeated string extend_data = 7;
  for (int i = 0; i < this->extend_data_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteString(
      7, this->extend_data(i), output);
  }
  
}

int FileList::ByteSize() const {
  int total_size = 0;
  
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required int32 version = 1;
    if (has_version()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->version());
    }
    
    // required string version_name = 2;
    if (has_version_name()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->version_name());
    }
    
    // optional int32 pkg_version = 4;
    if (has_pkg_version()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->pkg_version());
    }
    
    // optional string platform = 5;
    if (has_platform()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->platform());
    }
    
    // optional int32 config_version = 6;
    if (has_config_version()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->config_version());
    }
    
  }
  // repeated .framework.FileItem files = 3;
  total_size += 1 * this->files_size();
  for (int i = 0; i < this->files_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->files(i));
  }
  
  // repeated string extend_data = 7;
  total_size += 1 * this->extend_data_size();
  for (int i = 0; i < this->extend_data_size(); i++) {
    total_size += ::google::protobuf::internal::WireFormatLite::StringSize(
      this->extend_data(i));
  }
  
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void FileList::CheckTypeAndMergeFrom(
    const ::google::protobuf::MessageLite& from) {
  MergeFrom(*::google::protobuf::down_cast<const FileList*>(&from));
}

void FileList::MergeFrom(const FileList& from) {
  GOOGLE_CHECK_NE(&from, this);
  files_.MergeFrom(from.files_);
  extend_data_.MergeFrom(from.extend_data_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_version()) {
      set_version(from.version());
    }
    if (from.has_version_name()) {
      set_version_name(from.version_name());
    }
    if (from.has_pkg_version()) {
      set_pkg_version(from.pkg_version());
    }
    if (from.has_platform()) {
      set_platform(from.platform());
    }
    if (from.has_config_version()) {
      set_config_version(from.config_version());
    }
  }
}

void FileList::CopyFrom(const FileList& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool FileList::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;
  
  for (int i = 0; i < files_size(); i++) {
    if (!this->files(i).IsInitialized()) return false;
  }
  return true;
}

void FileList::Swap(FileList* other) {
  if (other != this) {
    std::swap(version_, other->version_);
    std::swap(version_name_, other->version_name_);
    files_.Swap(&other->files_);
    std::swap(pkg_version_, other->pkg_version_);
    std::swap(platform_, other->platform_);
    std::swap(config_version_, other->config_version_);
    extend_data_.Swap(&other->extend_data_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::std::string FileList::GetTypeName() const {
  return "framework.FileList";
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace framework

// @@protoc_insertion_point(global_scope)
