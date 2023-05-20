//
// Created by Willow Bracker on 20/05/2023.
//

#include "memnew.h"

#include <memory.h>
#include <malloc.h>

void_ptr memnew(size_type size) {
  return malloc(size); // TODO(Right now this is just a malloc wrapper, add more allocators?)
}

void memdelete(void_ptr memory) {
  return free(memory); // TODO(See memnew)
}
