//
// Created by Willow Bracker on 06/06/2023.
//

#pragma once

#define comptime_verify(expr, msg) typedef char verify_##msg[(expr)?1:-1]

typedef __INT8_TYPE__ i8;
typedef __INT16_TYPE__ i16;
typedef __INT32_TYPE__ i32;
typedef __INT64_TYPE__ i64;

typedef __UINT8_TYPE__ u8;
typedef __UINT16_TYPE__ u16;
typedef __UINT32_TYPE__ u32;
typedef __UINT64_TYPE__ u64;

#if __SIZEOF_SIZE_T__ == 8

  typedef u64 size_t;
  typedef i64 ssize_t;

#elif __SIZEOF_SIZE_T__ == 4

  typedef u32 size_t;
  typedef i32 size_t;

#else

  #error Unknown size for size_t (what arch is this?)

#endif

typedef _Bool bool;

#define false 0
#define true 1

#define null ((void*)0)

#if !defined(ck_header)

  #include "type/type.h"

#endif
