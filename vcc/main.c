//
// Created by Willow Bracker on 5/8/2023.
//

#include <stdio.h>

#include "token.h"

int main(int argc, char** argv) {
  printf("hello world!\n");

  DynArray token_array;
  initialize_array(&token_array);

  build_token_list(&token_array, "+");

  finalize_array(&token_array);

  return 0;
}
