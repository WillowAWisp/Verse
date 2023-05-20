//
// Created by Willow Bracker on 20/05/2023.
//

#pragma once

#include "api.h"

api_function(void_ptr) memnew(size_type size);
api_function(void) memdelete(void_ptr memory);
