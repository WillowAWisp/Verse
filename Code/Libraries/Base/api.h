//
// Created by Willow Bracker on 20/05/2023.
//

#pragma once

// helper macros

#define _paste_impl(s0,s1) s0##s1
#define _compile_assert_impl(expr, line, file) typedef char _paste_impl(assertion_failed_##file##_,line)[2*!!(expr)-1];

#define compile_verify(expr) _compile_assert_impl(expr, __LINE__, __FILE__)
#define runtime_verify(expr) __builtin_expect(!(expr), 0) ? __builtin_trap() : (void)0

// API Exports/Imports.

#if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)

  #define _import_symbol() __declspec(dllimport)
  #define _export_symbol() __declspec(dllexport)
  #define _local_symbol()

#else

  #define _import_symbol()
  #define _export_symbol()
  #define _local_symbol()

#endif

#define api_function(return_type) _export_symbol() return_type
#define api_data(data_type) _export_symbol() data_type

// C Types.

#include <inttypes.h>

typedef intptr_t int_ptr;
typedef uintptr_t uint_ptr;

typedef size_t size_type;

typedef void* void_ptr;
typedef _Bool bool;

#define true 1
#define false 0

#if defined(HAVE_SSIZE_T)

typedef ssize_t ssize_type;

#else // Check if size_t == void_ptr size.

compile_verify(sizeof(void_ptr) == sizeof(size_type)) // NOTE: If this is causing a compile error, No ssize_type Type!!
typedef int_ptr ssize_type;

#endif

// API Types.

typedef struct _Object Object;
typedef struct _TypeObject TypeObject;
