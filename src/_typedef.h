#include <stddef.h>

typedef bool                  boolean;
typedef char                  int8;
typedef int                   int32;
typedef size_t                usize;
typedef unsigned char         uint8;
typedef unsigned int          uint32;
typedef unsigned long long    uint64;
#define byte                  char
#define null                  nullptr

#include "utils/SharedPointer.h"
#define MAKE_TYPE(CLASS_NAME) SharedPointer<class##CLASS_NAME>
#define DEFINE_POINTER(CLASS_NAME) typedef MAKE_TYPE(CLASS_NAME) CLASS_NAME
#define NEW(CLASS_NAME, __VA_ARGS) MAKE_TYPE(CLASS_NAME)(new class##CLASS_NAME(__VA_ARGS))

//class Object;
//class String;

//DEFINE_POINTER(Object);
//DEFINE_POINTER(String);

