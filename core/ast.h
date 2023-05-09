//
// Created by Willow Bracker on 5/8/2023.
//

#pragma once

#include <stdbool.h>
#include "token.h"

typedef struct ParseTree_T {
  Token* data;
  struct ParseTree_T* child;
  struct ParseTree_T* sibling;
} ParseTree;

bool initialize_parse_tree(ParseTree* tree);
bool finalize_parse_tree(ParseTree* tree);

