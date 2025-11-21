#pragma once
#include <string>
#include <exception>
using namespace std;
class BaseException : public exception {
public:
    explicit BaseException(const string& message) : message_(message) {}
    const char* what() const noexcept override { return message_.c_str(); }
    
private:
    string message_;
};

class CopyrightException : public BaseException {
public:
    explicit CopyrightException(const string& message = "Copyright violation")
        : BaseException("CopyrightException: " + message) {}
};

class DeviceConnectionException : public BaseException {
public:
    explicit DeviceConnectionException(const string& message = "Device connection failed")
        : BaseException("DeviceConnectionException: " + message) {}
};

class DeviceNotSupportedException : public BaseException {
public:
    explicit DeviceNotSupportedException(const string& message = "Device not supported")
        : BaseException("DeviceNotSupportedException: " + message) {}
};

class DownloadLimitException : public BaseException {
public:
    explicit DownloadLimitException(const string& message = "Download limit exceeded")
        : BaseException("DownloadLimitException: " + message) {}
};

class FormatConversionException : public BaseException {
public:
    explicit FormatConversionException(const string& message = "Format conversion failed")
        : BaseException("FormatConversionException: " + message) {}
};

class InvalidFormatException : public BaseException {
public:
    explicit InvalidFormatException(const string& message = "Invalid format")
        : BaseException("InvalidFormatException: " + message) {}
};

class InvalidPasswordException : public BaseException {
public:
    explicit InvalidPasswordException(const string& message = "Invalid password")
        : BaseException("InvalidPasswordException: " + message) {}
};

class MetadataException : public BaseException {
public:
    explicit MetadataException(const string& message = "Metadata error")
        : BaseException("MetadataException: " + message) {}
};

class PhysicalMediaException : public BaseException {
public:
    explicit PhysicalMediaException(const string& message = "Physical media error")
        : BaseException("PhysicalMediaException: " + message) {}
};

class PlaybackException : public BaseException {
public:
    explicit PlaybackException(const string& message = "Playback error")
        : BaseException("PlaybackException: " + message) {}
};

class PlaylistFullException : public BaseException {
public:
    explicit PlaylistFullException(const string& message = "Playlist is full")
        : BaseException("PlaylistFullException: " + message) {}
};

class QualityException : public BaseException {
public:
    explicit QualityException(const string& message = "Audio quality error")
        : BaseException("QualityException: " + message) {}
};

class SongNotFoundException : public BaseException {
public:
    explicit SongNotFoundException(const string& message = "Song not found")
        : BaseException("SongNotFoundException: " + message) {}
};

class UserNotFoundException : public BaseException {
public:
    explicit UserNotFoundException(const string& message = "User not found")
        : BaseException("UserNotFoundException: " + message) {}
};