//
// Created by Willow Bracker on 19/05/2023.
//

#pragma once

#include "api.h"

#define class_decl() typedef struct // Start a new declaration of a class.

#define class_add_base() Object* base_object // Add the base object into the struct, necessary for an object to work

#define class_end(class_name) } (class_name) // End the declaration of a new class

#define class_init(class) { 1 }, (class) // This is used when creating the static TypeObject

#define get_type(object) (object)->object_type

struct _object_flags {
  bool flag_static;
  bool flag_native;
  bool flag_phold0; // Placeholder 0
  bool flag_phold1; // Placeholder 1
  bool flag_phold2; // Placeholder 2
  bool flag_phold3; // Placeholder 3
  bool flag_phold4; // Placeholder 4
  bool flag_phold5; // Placeholder 5
};

// TODO(Include all needed methods, this is just a starter).

struct _TypeObject {
  size_type object_size;

  Object* (*memnew_object)(TypeObject*); // Allocate a new object, returns the object;
  void (*memdelete_object)(Object*); // Deallocate an object returns nothing

  bool (*initialize_object)(Object*, Object* args); // initialize an object, returns true on success false on failure.
  bool (*finalize_object)(Object*); // Finalize an object, returns true on success false on failure.
};

struct _Object {
  TypeObject* object_type;
  struct _object_flags flags;
  size_type ref_count;


  // Traces for all live heap objects
  #if defined(BASE_MEM_TRACE)
    Object* _dbg_next;
    Object* _dbg_prv;
  #endif
};

api_function(Object*) generic_memnew(TypeObject* type);
api_function(void) generic_memdelete(Object* object);

api_function(bool) generic_initialize(Object* object, Object* args);
api_function(bool) generic_finalize(Object* object);
