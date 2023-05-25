//
// Created by Willow Bracker on 25/05/2023.
//

#pragma once

#include "api.h"

fn_export(void*) memalloc(size_t size);
fn_export(void) memfree(void* memory);
