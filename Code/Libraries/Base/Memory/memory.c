//
// Created by Willow Bracker on 25/05/2023.
//

#include "memory.h"
#include <stdlib.h>

void* memalloc(size_t size) {
  return malloc(size);
}

void memfree(void* memory) {
  free(memory);
}
