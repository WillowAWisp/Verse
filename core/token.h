//
// Created by Willow Bracker on 5/9/2023.
//

#pragma once

#include <stdbool.h>
#include "mem.h"

typedef enum TokenType_T {
  // Basic Syntax

  TOK_NEWLINE, // newline
  TOK_IDENT, // variable identifiers.
  TOK_EQUAL, // equals sign
  TOK_LEFT_BRACE, // {
  TOK_RIGHT_BRACE, // }
  TOK_LEFT_BRACKET, // [
  TOK_RIGHT_BRACKET, // ]
  TOK_COMMA, // ,

  // Numerics.

  TOK_INTEGER, // int
  TOK_FLOAT, // 64 bit double floating point number

  // Strings.

  TOK_QUOTE, // quotes
  TOK_FORMAT, // $()

  // Keywords.

  TOK_CLASS, // class
  TOK_FUNCTION, // function

  // Math

  TOK_ADD, // +
  TOK_SUB, // -
  TOK_MUL, // *
  TOK_DIV, // /

  TOK_PWR, // ** (power of)
  TOK_SQR, // // (square root)

  // Bitwise

  TOK_AND, // &
  TOK_OR,  // |
  TOK_XOR, // ^
  TOK_NOT, // ~
  TOK_LSH, // (left shift) <<
  TOK_RSH, // (right shift) >>

  // Literals:

  TOK_TRUE,
  TOK_FALSE,
  TOK_SELF,
  TOK_BASE,
  TOK_VOID,

  // Looping and Function things,

  TOK_FOR_EACH,
  TOK_RETURN,

  // Misc:

  TOK_TRA, // Type Re-assign :=
  TOK_EOF, // End of file.
  TOK_ERR, // Error.

} TokenType;

typedef struct Token_T {
  TokenType type;
  const char* start;
  int length;
  int line;
} Token;

bool build_token_list(DynArray* token_list, char* text);
bool finalize_token_list(DynArray* token_list);

void print_token(Token* token);
