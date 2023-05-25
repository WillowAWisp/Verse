//
// Created by Willow Bracker on 25/05/2023.
//

#include <stddef.h>

#pragma once

#if defined(__WIN32__) || defined(__WIN64__)

  #define fn_export(return_type) __declspec(dllexport) return_type
  #define fn_import(return_type) __declspec(dllimport) return_type

#else

  #define fn_export(return_type)
  #define fn_import(return_type)

#endif


