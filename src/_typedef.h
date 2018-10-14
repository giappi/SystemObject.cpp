#ifndef _TYPEDEFH
#define _TYPEDEFH

#include <cstdint>

typedef bool                  boolean;
typedef std::int8_t           int8;
typedef unsigned char         byte;
typedef std::int32_t          int32;
typedef std::int64_t          int64;
typedef std::size_t           usize;
typedef std::uint8_t          uint8;
typedef std::uint32_t         uint32;
typedef std::uint64_t         uint64;


const   std::nullptr_t        null = nullptr;

#if 0
#include "utils/SharedPointer.h"
#define MAKE_TYPE(CLASS_NAME) SharedPointer<class##CLASS_NAME>
#define DEFINE_POINTER(CLASS_NAME) typedef MAKE_TYPE(CLASS_NAME) CLASS_NAME
#define NEW(CLASS_NAME, __VA_ARGS) MAKE_TYPE(CLASS_NAME)(new class##CLASS_NAME(__VA_ARGS))
#endif

//class Object;
//class String;

//DEFINE_POINTER(Object);
//DEFINE_POINTER(String);

#endif /* _TYPEDEFH */