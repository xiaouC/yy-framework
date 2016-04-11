// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: files.proto

#ifndef PROTOBUF_files_2eproto__INCLUDED
#define PROTOBUF_files_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2004000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2004001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
// @@protoc_insertion_point(includes)

namespace framework {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_files_2eproto();
void protobuf_AssignDesc_files_2eproto();
void protobuf_ShutdownFile_files_2eproto();

class FileItem;
class FileList;

enum FileStorage {
  PACKAGE = 1,
  INTERNAL = 2,
  EXTERNAL = 3
};
bool FileStorage_IsValid(int value);
const FileStorage FileStorage_MIN = PACKAGE;
const FileStorage FileStorage_MAX = EXTERNAL;
const int FileStorage_ARRAYSIZE = FileStorage_MAX + 1;

// ===================================================================

class FileItem : public ::google::protobuf::MessageLite {
 public:
  FileItem();
  virtual ~FileItem();
  
  FileItem(const FileItem& from);
  
  inline FileItem& operator=(const FileItem& from) {
    CopyFrom(from);
    return *this;
  }
  
  static const FileItem& default_instance();
  
  void Swap(FileItem* other);
  
  // implements Message ----------------------------------------------
  
  FileItem* New() const;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from);
  void CopyFrom(const FileItem& from);
  void MergeFrom(const FileItem& from);
  void Clear();
  bool IsInitialized() const;
  
  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  
  ::std::string GetTypeName() const;
  
  // nested types ----------------------------------------------------
  
  // accessors -------------------------------------------------------
  
  // required string url = 1;
  inline bool has_url() const;
  inline void clear_url();
  static const int kUrlFieldNumber = 1;
  inline const ::std::string& url() const;
  inline void set_url(const ::std::string& value);
  inline void set_url(const char* value);
  inline void set_url(const char* value, size_t size);
  inline ::std::string* mutable_url();
  inline ::std::string* release_url();
  
  // required string md5 = 2;
  inline bool has_md5() const;
  inline void clear_md5();
  static const int kMd5FieldNumber = 2;
  inline const ::std::string& md5() const;
  inline void set_md5(const ::std::string& value);
  inline void set_md5(const char* value);
  inline void set_md5(const char* value, size_t size);
  inline ::std::string* mutable_md5();
  inline ::std::string* release_md5();
  
  // required int32 size = 3;
  inline bool has_size() const;
  inline void clear_size();
  static const int kSizeFieldNumber = 3;
  inline ::google::protobuf::int32 size() const;
  inline void set_size(::google::protobuf::int32 value);
  
  // required .framework.FileStorage where = 4;
  inline bool has_where() const;
  inline void clear_where();
  static const int kWhereFieldNumber = 4;
  inline framework::FileStorage where() const;
  inline void set_where(framework::FileStorage value);
  
  // @@protoc_insertion_point(class_scope:framework.FileItem)
 private:
  inline void set_has_url();
  inline void clear_has_url();
  inline void set_has_md5();
  inline void clear_has_md5();
  inline void set_has_size();
  inline void clear_has_size();
  inline void set_has_where();
  inline void clear_has_where();
  
  ::std::string* url_;
  ::std::string* md5_;
  ::google::protobuf::int32 size_;
  int where_;
  
  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(4 + 31) / 32];
  
  friend void  protobuf_AddDesc_files_2eproto();
  friend void protobuf_AssignDesc_files_2eproto();
  friend void protobuf_ShutdownFile_files_2eproto();
  
  void InitAsDefaultInstance();
  static FileItem* default_instance_;
};
// -------------------------------------------------------------------

class FileList : public ::google::protobuf::MessageLite {
 public:
  FileList();
  virtual ~FileList();
  
  FileList(const FileList& from);
  
  inline FileList& operator=(const FileList& from) {
    CopyFrom(from);
    return *this;
  }
  
  static const FileList& default_instance();
  
  void Swap(FileList* other);
  
  // implements Message ----------------------------------------------
  
  FileList* New() const;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from);
  void CopyFrom(const FileList& from);
  void MergeFrom(const FileList& from);
  void Clear();
  bool IsInitialized() const;
  
  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  
  ::std::string GetTypeName() const;
  
  // nested types ----------------------------------------------------
  
  // accessors -------------------------------------------------------
  
  // required int32 version = 1;
  inline bool has_version() const;
  inline void clear_version();
  static const int kVersionFieldNumber = 1;
  inline ::google::protobuf::int32 version() const;
  inline void set_version(::google::protobuf::int32 value);
  
  // required string version_name = 2;
  inline bool has_version_name() const;
  inline void clear_version_name();
  static const int kVersionNameFieldNumber = 2;
  inline const ::std::string& version_name() const;
  inline void set_version_name(const ::std::string& value);
  inline void set_version_name(const char* value);
  inline void set_version_name(const char* value, size_t size);
  inline ::std::string* mutable_version_name();
  inline ::std::string* release_version_name();
  
  // repeated .framework.FileItem files = 3;
  inline int files_size() const;
  inline void clear_files();
  static const int kFilesFieldNumber = 3;
  inline const ::framework::FileItem& files(int index) const;
  inline ::framework::FileItem* mutable_files(int index);
  inline ::framework::FileItem* add_files();
  inline const ::google::protobuf::RepeatedPtrField< ::framework::FileItem >&
      files() const;
  inline ::google::protobuf::RepeatedPtrField< ::framework::FileItem >*
      mutable_files();
  
  // optional int32 pkg_version = 4;
  inline bool has_pkg_version() const;
  inline void clear_pkg_version();
  static const int kPkgVersionFieldNumber = 4;
  inline ::google::protobuf::int32 pkg_version() const;
  inline void set_pkg_version(::google::protobuf::int32 value);
  
  // optional string platform = 5;
  inline bool has_platform() const;
  inline void clear_platform();
  static const int kPlatformFieldNumber = 5;
  inline const ::std::string& platform() const;
  inline void set_platform(const ::std::string& value);
  inline void set_platform(const char* value);
  inline void set_platform(const char* value, size_t size);
  inline ::std::string* mutable_platform();
  inline ::std::string* release_platform();
  
  // optional int32 config_version = 6;
  inline bool has_config_version() const;
  inline void clear_config_version();
  static const int kConfigVersionFieldNumber = 6;
  inline ::google::protobuf::int32 config_version() const;
  inline void set_config_version(::google::protobuf::int32 value);
  
  // repeated string extend_data = 7;
  inline int extend_data_size() const;
  inline void clear_extend_data();
  static const int kExtendDataFieldNumber = 7;
  inline const ::std::string& extend_data(int index) const;
  inline ::std::string* mutable_extend_data(int index);
  inline void set_extend_data(int index, const ::std::string& value);
  inline void set_extend_data(int index, const char* value);
  inline void set_extend_data(int index, const char* value, size_t size);
  inline ::std::string* add_extend_data();
  inline void add_extend_data(const ::std::string& value);
  inline void add_extend_data(const char* value);
  inline void add_extend_data(const char* value, size_t size);
  inline const ::google::protobuf::RepeatedPtrField< ::std::string>& extend_data() const;
  inline ::google::protobuf::RepeatedPtrField< ::std::string>* mutable_extend_data();
  
  // @@protoc_insertion_point(class_scope:framework.FileList)
 private:
  inline void set_has_version();
  inline void clear_has_version();
  inline void set_has_version_name();
  inline void clear_has_version_name();
  inline void set_has_pkg_version();
  inline void clear_has_pkg_version();
  inline void set_has_platform();
  inline void clear_has_platform();
  inline void set_has_config_version();
  inline void clear_has_config_version();
  
  ::std::string* version_name_;
  ::google::protobuf::int32 version_;
  ::google::protobuf::int32 pkg_version_;
  ::google::protobuf::RepeatedPtrField< ::framework::FileItem > files_;
  ::std::string* platform_;
  ::google::protobuf::RepeatedPtrField< ::std::string> extend_data_;
  ::google::protobuf::int32 config_version_;
  
  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(7 + 31) / 32];
  
  friend void  protobuf_AddDesc_files_2eproto();
  friend void protobuf_AssignDesc_files_2eproto();
  friend void protobuf_ShutdownFile_files_2eproto();
  
  void InitAsDefaultInstance();
  static FileList* default_instance_;
};
// ===================================================================


// ===================================================================

// FileItem

// required string url = 1;
inline bool FileItem::has_url() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void FileItem::set_has_url() {
  _has_bits_[0] |= 0x00000001u;
}
inline void FileItem::clear_has_url() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void FileItem::clear_url() {
  if (url_ != &::google::protobuf::internal::kEmptyString) {
    url_->clear();
  }
  clear_has_url();
}
inline const ::std::string& FileItem::url() const {
  return *url_;
}
inline void FileItem::set_url(const ::std::string& value) {
  set_has_url();
  if (url_ == &::google::protobuf::internal::kEmptyString) {
    url_ = new ::std::string;
  }
  url_->assign(value);
}
inline void FileItem::set_url(const char* value) {
  set_has_url();
  if (url_ == &::google::protobuf::internal::kEmptyString) {
    url_ = new ::std::string;
  }
  url_->assign(value);
}
inline void FileItem::set_url(const char* value, size_t size) {
  set_has_url();
  if (url_ == &::google::protobuf::internal::kEmptyString) {
    url_ = new ::std::string;
  }
  url_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* FileItem::mutable_url() {
  set_has_url();
  if (url_ == &::google::protobuf::internal::kEmptyString) {
    url_ = new ::std::string;
  }
  return url_;
}
inline ::std::string* FileItem::release_url() {
  clear_has_url();
  if (url_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = url_;
    url_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// required string md5 = 2;
inline bool FileItem::has_md5() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void FileItem::set_has_md5() {
  _has_bits_[0] |= 0x00000002u;
}
inline void FileItem::clear_has_md5() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void FileItem::clear_md5() {
  if (md5_ != &::google::protobuf::internal::kEmptyString) {
    md5_->clear();
  }
  clear_has_md5();
}
inline const ::std::string& FileItem::md5() const {
  return *md5_;
}
inline void FileItem::set_md5(const ::std::string& value) {
  set_has_md5();
  if (md5_ == &::google::protobuf::internal::kEmptyString) {
    md5_ = new ::std::string;
  }
  md5_->assign(value);
}
inline void FileItem::set_md5(const char* value) {
  set_has_md5();
  if (md5_ == &::google::protobuf::internal::kEmptyString) {
    md5_ = new ::std::string;
  }
  md5_->assign(value);
}
inline void FileItem::set_md5(const char* value, size_t size) {
  set_has_md5();
  if (md5_ == &::google::protobuf::internal::kEmptyString) {
    md5_ = new ::std::string;
  }
  md5_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* FileItem::mutable_md5() {
  set_has_md5();
  if (md5_ == &::google::protobuf::internal::kEmptyString) {
    md5_ = new ::std::string;
  }
  return md5_;
}
inline ::std::string* FileItem::release_md5() {
  clear_has_md5();
  if (md5_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = md5_;
    md5_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// required int32 size = 3;
inline bool FileItem::has_size() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void FileItem::set_has_size() {
  _has_bits_[0] |= 0x00000004u;
}
inline void FileItem::clear_has_size() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void FileItem::clear_size() {
  size_ = 0;
  clear_has_size();
}
inline ::google::protobuf::int32 FileItem::size() const {
  return size_;
}
inline void FileItem::set_size(::google::protobuf::int32 value) {
  set_has_size();
  size_ = value;
}

// required .framework.FileStorage where = 4;
inline bool FileItem::has_where() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void FileItem::set_has_where() {
  _has_bits_[0] |= 0x00000008u;
}
inline void FileItem::clear_has_where() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void FileItem::clear_where() {
  where_ = 1;
  clear_has_where();
}
inline framework::FileStorage FileItem::where() const {
  return static_cast< framework::FileStorage >(where_);
}
inline void FileItem::set_where(framework::FileStorage value) {
  GOOGLE_DCHECK(framework::FileStorage_IsValid(value));
  set_has_where();
  where_ = value;
}

// -------------------------------------------------------------------

// FileList

// required int32 version = 1;
inline bool FileList::has_version() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void FileList::set_has_version() {
  _has_bits_[0] |= 0x00000001u;
}
inline void FileList::clear_has_version() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void FileList::clear_version() {
  version_ = 0;
  clear_has_version();
}
inline ::google::protobuf::int32 FileList::version() const {
  return version_;
}
inline void FileList::set_version(::google::protobuf::int32 value) {
  set_has_version();
  version_ = value;
}

// required string version_name = 2;
inline bool FileList::has_version_name() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void FileList::set_has_version_name() {
  _has_bits_[0] |= 0x00000002u;
}
inline void FileList::clear_has_version_name() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void FileList::clear_version_name() {
  if (version_name_ != &::google::protobuf::internal::kEmptyString) {
    version_name_->clear();
  }
  clear_has_version_name();
}
inline const ::std::string& FileList::version_name() const {
  return *version_name_;
}
inline void FileList::set_version_name(const ::std::string& value) {
  set_has_version_name();
  if (version_name_ == &::google::protobuf::internal::kEmptyString) {
    version_name_ = new ::std::string;
  }
  version_name_->assign(value);
}
inline void FileList::set_version_name(const char* value) {
  set_has_version_name();
  if (version_name_ == &::google::protobuf::internal::kEmptyString) {
    version_name_ = new ::std::string;
  }
  version_name_->assign(value);
}
inline void FileList::set_version_name(const char* value, size_t size) {
  set_has_version_name();
  if (version_name_ == &::google::protobuf::internal::kEmptyString) {
    version_name_ = new ::std::string;
  }
  version_name_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* FileList::mutable_version_name() {
  set_has_version_name();
  if (version_name_ == &::google::protobuf::internal::kEmptyString) {
    version_name_ = new ::std::string;
  }
  return version_name_;
}
inline ::std::string* FileList::release_version_name() {
  clear_has_version_name();
  if (version_name_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = version_name_;
    version_name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// repeated .framework.FileItem files = 3;
inline int FileList::files_size() const {
  return files_.size();
}
inline void FileList::clear_files() {
  files_.Clear();
}
inline const ::framework::FileItem& FileList::files(int index) const {
  return files_.Get(index);
}
inline ::framework::FileItem* FileList::mutable_files(int index) {
  return files_.Mutable(index);
}
inline ::framework::FileItem* FileList::add_files() {
  return files_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::framework::FileItem >&
FileList::files() const {
  return files_;
}
inline ::google::protobuf::RepeatedPtrField< ::framework::FileItem >*
FileList::mutable_files() {
  return &files_;
}

// optional int32 pkg_version = 4;
inline bool FileList::has_pkg_version() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void FileList::set_has_pkg_version() {
  _has_bits_[0] |= 0x00000008u;
}
inline void FileList::clear_has_pkg_version() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void FileList::clear_pkg_version() {
  pkg_version_ = 0;
  clear_has_pkg_version();
}
inline ::google::protobuf::int32 FileList::pkg_version() const {
  return pkg_version_;
}
inline void FileList::set_pkg_version(::google::protobuf::int32 value) {
  set_has_pkg_version();
  pkg_version_ = value;
}

// optional string platform = 5;
inline bool FileList::has_platform() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void FileList::set_has_platform() {
  _has_bits_[0] |= 0x00000010u;
}
inline void FileList::clear_has_platform() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void FileList::clear_platform() {
  if (platform_ != &::google::protobuf::internal::kEmptyString) {
    platform_->clear();
  }
  clear_has_platform();
}
inline const ::std::string& FileList::platform() const {
  return *platform_;
}
inline void FileList::set_platform(const ::std::string& value) {
  set_has_platform();
  if (platform_ == &::google::protobuf::internal::kEmptyString) {
    platform_ = new ::std::string;
  }
  platform_->assign(value);
}
inline void FileList::set_platform(const char* value) {
  set_has_platform();
  if (platform_ == &::google::protobuf::internal::kEmptyString) {
    platform_ = new ::std::string;
  }
  platform_->assign(value);
}
inline void FileList::set_platform(const char* value, size_t size) {
  set_has_platform();
  if (platform_ == &::google::protobuf::internal::kEmptyString) {
    platform_ = new ::std::string;
  }
  platform_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* FileList::mutable_platform() {
  set_has_platform();
  if (platform_ == &::google::protobuf::internal::kEmptyString) {
    platform_ = new ::std::string;
  }
  return platform_;
}
inline ::std::string* FileList::release_platform() {
  clear_has_platform();
  if (platform_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = platform_;
    platform_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// optional int32 config_version = 6;
inline bool FileList::has_config_version() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void FileList::set_has_config_version() {
  _has_bits_[0] |= 0x00000020u;
}
inline void FileList::clear_has_config_version() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void FileList::clear_config_version() {
  config_version_ = 0;
  clear_has_config_version();
}
inline ::google::protobuf::int32 FileList::config_version() const {
  return config_version_;
}
inline void FileList::set_config_version(::google::protobuf::int32 value) {
  set_has_config_version();
  config_version_ = value;
}

// repeated string extend_data = 7;
inline int FileList::extend_data_size() const {
  return extend_data_.size();
}
inline void FileList::clear_extend_data() {
  extend_data_.Clear();
}
inline const ::std::string& FileList::extend_data(int index) const {
  return extend_data_.Get(index);
}
inline ::std::string* FileList::mutable_extend_data(int index) {
  return extend_data_.Mutable(index);
}
inline void FileList::set_extend_data(int index, const ::std::string& value) {
  extend_data_.Mutable(index)->assign(value);
}
inline void FileList::set_extend_data(int index, const char* value) {
  extend_data_.Mutable(index)->assign(value);
}
inline void FileList::set_extend_data(int index, const char* value, size_t size) {
  extend_data_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
}
inline ::std::string* FileList::add_extend_data() {
  return extend_data_.Add();
}
inline void FileList::add_extend_data(const ::std::string& value) {
  extend_data_.Add()->assign(value);
}
inline void FileList::add_extend_data(const char* value) {
  extend_data_.Add()->assign(value);
}
inline void FileList::add_extend_data(const char* value, size_t size) {
  extend_data_.Add()->assign(reinterpret_cast<const char*>(value), size);
}
inline const ::google::protobuf::RepeatedPtrField< ::std::string>&
FileList::extend_data() const {
  return extend_data_;
}
inline ::google::protobuf::RepeatedPtrField< ::std::string>*
FileList::mutable_extend_data() {
  return &extend_data_;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace framework

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_files_2eproto__INCLUDED
