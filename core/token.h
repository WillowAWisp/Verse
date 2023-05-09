//
// Created by Willow Bracker on 5/9/2023.
//

#pragma once

#include <stdbool.h>

typedef enum TokenType_T {
  // Basic Syntax

  TOK_NEWLINE, // newline
  TOK_IDENT, // variable identifiers.
  TOK_EQUAL, // equals sign
  TOK_LEFT_BRACE, // {
  TOK_RIGHT_BRACE, // }
  TOK_LEFT_BRACKET, // [
  TOK_RIGHT_BRACKET, // ]

  // Numerics.

  TOK_INTEGER, // int
  TOK_FLOAT, // 64 bit double floating point number

  // Strings.

  TOK_QUOTE, // quotes
  TOK_FORMAT, // ${}

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

} TokenType;

typedef struct Token_T {
  char* text;
  TokenType type;
} Token;

typedef struct TokenList_T {
  Token* token;
  struct TokenList_T* next;
} TokenList;

bool initialize_token(Token* token, char* string);
bool finalize_token(Token* token);

void print_token(Token* token);
