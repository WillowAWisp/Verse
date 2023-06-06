//
// Created by Willow Bracker on 06/06/2023.
//

#pragma once

#include "corekit.h"

void* memalloc_impl(size_t size, bool aligned);
void memfree(void* memory);

#define memalloc_alligned(size) memalloc_impl(size, true);
#define memalloc(size) memalloc_impl(size, false);
