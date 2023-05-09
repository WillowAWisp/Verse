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

void dump_parse_tree(ParseTree* tree, int indent) {
  if (!tree) {
    return;
  }

  if (indent > 0) {
    char space[indent + 1];
    memset(space, ' ', indent * sizeof(char));
    memset(space+indent, '\0', sizeof(char));
  }
  print_token(*tree->data);

  dump_parse_tree(tree->child, indent + 2);
  dump_parse_tree(tree->sibling, indent);
}
