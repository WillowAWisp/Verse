//
// Created by Willow Bracker on 5/8/2023.
//

#pragma once

#include <stdbool.h>

// Dynamic Array tools

#define get_array(array, idx, type) *(type*)array_get(&array, idx)
#define set_array(array, value) array_set(&array, (void*)value)

// returns false upon failure

typedef struct DynArray_T {
  void** mem;

  int count;
  int capacity;
} DynArray;

bool initialize_array(DynArray* array);
bool finalize_array(DynArray* array);

void* array_get(DynArray* array, int idx);
int array_set(DynArray* array, void* value);
