// SubVectorException.h
#ifndef SUBVECTOR_EXCEPTION_H
#define SUBVECTOR_EXCEPTION_H

#include <exception>
#include <string>

class VectorException : public std::exception {
public:
    VectorException(const std::string& message) : msg("VectorException: " + message) {}
    const char* what() const noexcept override { return msg.c_str(); }

protected:
    std::string msg;
};

class MemoryAllocationException : public VectorException {
public:
    MemoryAllocationException(const std::string& message) : VectorException("MemoryAllocationException: " + message) {}
};

class EmptyVectorException : public VectorException {
public:
    EmptyVectorException(const std::string& message) : VectorException("EmptyVectorException: " + message) {}
};

#endif // SUBVECTOR_EXCEPTION_H
