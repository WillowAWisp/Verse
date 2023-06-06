//
// Created by Willow Bracker on 06/06/2023.
//

#include "memory.h"

#include <stdlib.h>

// Malloc is the only supported backend right now

void* memalloc_impl(size_t size, bool aligned) {
  if (size == 0) {
    runtime_verify(false, "Tried to allocate memory of size 0?");
  }

  // Check if size is a power of 2, if not align it.

  if (((size & (size - 1)) == 0)) {
    size--;
    size |= size >> 1;
    size |= size >> 2;
    size |= size >> 4;
    size |= size >> 8;
    size |= size >> 16;
    #if __SIZEOF_SIZE_T__ == 8 // if 64-bit
      size |= size >> 32;
    #endif
    size++;
  }

  return malloc(size);
}

void memfree(void* memory) {
  free(memory);
}
