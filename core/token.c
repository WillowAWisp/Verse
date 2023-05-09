//
// Created by Willow Bracker on 5/9/2023.
//

#include "token.h"

#include <stdio.h>

void print_token(Token* token) {
  switch (token->type) {
    case TOK_NEWLINE:
      printf("TOK_NEWLINE: (\\n)");
      break;
    case TOK_IDENT:
      printf("TOK_IDENT: (%s)", token->text);
      break;
    case TOK_EQUAL:
      printf("TOK_EQUAL: (%s)", token->text);
      break;
    case TOK_LEFT_BRACE:
      printf("TOK_LEFT_BRACE: (%s)", token->text);
      break;
    case TOK_RIGHT_BRACE:
      printf("TOK_RIGHT_BRACKET: (%s)", token->text);
      break;
    case TOK_LEFT_BRACKET:
      printf("TOK_LEFT_BRACKET: (%s)", token->text);
      break;
    case TOK_RIGHT_BRACKET:
      printf("TOK_RIGHT_BRACKET: (%s)", token->text);
      break;
    case TOK_INTEGER:
      printf("TOK_INTEGER: (%s)", token->text);
      break;
    case TOK_FLOAT:
      printf("TOK_FLOAT (%s)", token->text);
      break;
    case TOK_QUOTE:
      printf("TOK_QUOTE (\")");
      break;
    case TOK_FORMAT:
      printf("TOK_FORMAT (%s)", token->text);
      break;
    case TOK_CLASS:
      printf("TOK_CLASS (%s)", token->text);
      break;
    case TOK_FUNCTION:
      printf("TOK_FUNCTION (%s)", token->text);
      break;
  }
  printf("\n");
}

// Overlap list between tokens:
// \n: no overlap
// ident: no overlap
// {: no overlap
// }: no overlap
// [: no overlap
// ]: no overlap
// int: 1-9: float overlap, check for decimals.
// float: 1-9+.: int overlap, check for decimals.
// quotes: "" format overlap
// format: ${} inside strings, if this sequence appears within a string without an escape, check
// class: no overlap
// function: no overlap

