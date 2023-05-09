//
// Created by Willow Bracker on 5/8/2023.
//

#include "mem.h"
#include <stdlib.h>

#define array_calculate_new_capacity(capacity) ((capacity) < 8 ? 8 : (capacity) * 2)

bool initialize_array(DynArray* array) {
  array->mem = NULL;
  array->count = 0;
  array->capacity = 0;

  return true;
}

bool finalize_array(DynArray* array) {
  free(array->mem);
  initialize_array(array);

  return true;
}

void* array_get(DynArray* array, int idx) {
  if (array->capacity < idx || !array->mem) { return NULL; }
  return &array->mem[idx];
}

// Returns index that the variable was set in.

int array_set(DynArray* array, void* value) {
  if (array->capacity < array->count + 1) {
    array->capacity = array_calculate_new_capacity(array->capacity);
    void* result = realloc(array->mem, array->capacity);
    if (result == NULL) {
      // TODO(Crash when this happens)
      return 0;
    }
    array->mem = result;
  }

  array->mem[array->count == 0 ? 0 : array->count++] = value;
  return array->count;
}
