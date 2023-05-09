//
// Created by Willow Bracker on 5/8/2023.
//

#include "ast.h"
#include <stdlib.h>
#include <memory.h>

bool initialize_parse_tree(ParseTree* tree) {
  tree->data = NULL;
  tree->child = NULL;
  tree->sibling = NULL;
  return true;
}

bool finalize_parse_tree(ParseTree* tree) {
  return initialize_parse_tree(tree);
}
