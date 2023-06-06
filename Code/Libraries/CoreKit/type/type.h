//
// Created by Willow Bracker on 06/06/2023.
//

#pragma once

#define ck_header // No circular dependencies.

#include "corekit.h"

// TypeRecord API:
// ---------------
// memnew(), Allocate for the value the type represents, only for use on type records not values.
// memdel(), Delete memory of the type passed in, only for use on type records not values.
// initialize(), Initialize the object, _only_ for use on values, _not_ type records.
// finalize(), Finalize the object, _only_ for use on values, _not_ type records.
// ref(), add to the value's ref count.
// unref(), remove one from the value's ref count.

typedef struct _TypeRecord TypeRecord;

typedef struct _Value {
  TypeRecord* type;
  ssize_t refcount;
} Value;

typedef struct _TypeRecord  {

  // Memory Functions

  _Bool (*memnew)(void* mem_ptr);
  _Bool (*memdel)(void* mem_ptr);

  // Initialize/Finalize

  _Bool (*initialize)(Value* self);
  _Bool (*finalize)(Value* self);

  // Reference Counting

  ssize_t (*ref)();
  ssize_t (*unref)();

  // Metadata

  char* type_name;

} TypeRecord;
