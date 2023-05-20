//
// Created by Willow Bracker on 19/05/2023.
//

#include "object.h"

#include "Memory/memnew.h"

Object* generic_memnew(TypeObject* type) {
  runtime_verify(type != NULL);
  Object* obj = NULL;

  obj = memnew(type->object_size);
  runtime_verify(obj != NULL);
}

void generic_memdelete(Object* object) {
  memdelete(object);
}

bool generic_initialize(Object* object, Object* args) {
  runtime_verify(args == NULL); // TODO(Right now we haven't made any object types, so no args should be passed).
  return true;
}

bool generic_finalize(Object* object) {
  runtime_verify(object != NULL);
}
