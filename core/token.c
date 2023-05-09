//
// Created by Willow Bracker on 5/9/2023.
//

#include "token.h"

#include <stdio.h>
#include <string.h>

void print_token(Token* token) {
  switch (token->type) {
    case TOK_NEWLINE:
      printf("TOK_NEWLINE: (\\n)");
      break;
    case TOK_IDENT:
      printf("TOK_IDENT: (%.*s)", token->length, token->start);
      break;
    case TOK_EQUAL:
      printf("TOK_EQUAL: (%.*s)", token->length, token->start);
      break;
    case TOK_LEFT_BRACE:
      printf("TOK_LEFT_BRACE: (%.*s)", token->length, token->start);
      break;
    case TOK_RIGHT_BRACE:
      printf("TOK_RIGHT_BRACKET: (%.*s)", token->length, token->start);
      break;
    case TOK_LEFT_BRACKET:
      printf("TOK_LEFT_BRACKET: (%.*s)", token->length, token->start);
      break;
    case TOK_RIGHT_BRACKET:
      printf("TOK_RIGHT_BRACKET: (%.*s)", token->length, token->start);
      break;
    case TOK_INTEGER:
      printf("TOK_INTEGER: (%.*s)", token->length, token->start);
      break;
    case TOK_FLOAT:
      printf("TOK_FLOAT: (%.*s)", token->length, token->start);
      break;
    case TOK_QUOTE:
      printf("TOK_QUOTE: (\")");
      break;
    case TOK_FORMAT:
      printf("TOK_FORMAT: (%.*s)", token->length, token->start);
      break;
    case TOK_CLASS:
      printf("TOK_CLASS: (%.*s)", token->length, token->start);
      break;
    case TOK_FUNCTION:
      printf("TOK_FUNCTION: (%.*s)", token->length, token->start);
      break;
    case TOK_ADD:
      printf("TOK_ADD: (%.*s)", token->length, token->start);
      break;
    case TOK_SUB:
      printf("TOK_SUB: (%.*s)", token->length, token->start);
      break;
    case TOK_MUL:
      printf("TOK_MUL: (%.*s)", token->length, token->start);
      break;
    case TOK_DIV:
      printf("TOK_DIV: (%.*s)", token->length, token->start);
      break;
    case TOK_PWR:
      printf("TOK_PWR: (%.*s)", token->length, token->start);
      break;
    case TOK_SQR:
      printf("TOK_SQR: (%.*s)", token->length, token->start);
      break;
    case TOK_AND:
      printf("TOK_AND: (%.*s)", token->length, token->start);
      break;
    case TOK_OR:
      printf("TOK_OR: (%.*s)", token->length, token->start);
      break;
    case TOK_XOR:
      printf("TOK_XOR: (%.*s)", token->length, token->start);
      break;
    case TOK_NOT:
      printf("TOK_NOT: (%.*s)", token->length, token->start);
      break;
    case TOK_LSH:
      printf("TOK_LSH: (%.*s)", token->length, token->start);
      break;
    case TOK_RSH:
      printf("TOK_RSH: (%.*s)", token->length, token->start);
      break;
    case TOK_TRUE:
      printf("TOK_TRUE: (%.*s)", token->length, token->start);
      break;
    case TOK_FALSE:
      printf("TOK_FALSE: (%.*s)", token->length, token->start);
      break;
    case TOK_SELF:
      printf("TOK_SELF: (%.*s)", token->length, token->start);
      break;
    case TOK_BASE:
      printf("TOK_BASE: (%.*s)", token->length, token->start);
      break;
    case TOK_VOID:
      printf("TOK_VOID: (%.*s)", token->length, token->start);
      break;
    case TOK_FOR_EACH:
      printf("TOK_FOR_EACH: (%.*s)", token->length, token->start);
      break;
    case TOK_RETURN:
      printf("TOK_RETURN: (%.*s)", token->length, token->start);
      break;
    case TOK_TRA:
      printf("TOK_TRA: (%.*s)", token->length, token->start);
      break;
    case TOK_ERR:
      printf("TOK_ERR: (%.*s)", token->length, token->start);
      break;
    case TOK_EOF:
      printf("TOK_EOF: (\\0)");
      break;
  }
  printf("\n");
}

// Internal Tokenizer Functions & Structures.

typedef struct Scanner_T {
  const char* start;
  const char* current;
  int line;
} Scanner;

// [subsection] token helpers.

static Token _make_token(TokenType type, Scanner* scanner) {
  Token token;

  token.type = type;
  token.start = scanner->start;
  token.length = (int)(scanner->current - scanner->start);
  token.line = scanner->line;

  return token;
}

static Token _make_error_token(Scanner* scanner, const char* message) {
  Token token;

  token.type = TOK_ERR;
  token.start = message;
  token.length = (int)strlen(message);
  token.line = scanner->line;

  return token;
}

// [subsection] Internal Scanner Functions & Structs.

static bool _is_eof(Scanner* scanner) {
  return *scanner->current == '\0';
}

static char advance(Scanner* scanner) {
  scanner->current++;
  return scanner->current[-1];
}

static Token _scan_token(const char* source_text) {
  // Build the scanner.
  Scanner scanner;
  scanner.current = source_text;
  scanner.line = 1;

  // Next, we check if we are at eof.
  if (_is_eof(&scanner)) {
    return _make_token(TOK_EOF, &scanner);
  }

  char c = advance(&scanner);

  switch (c) {
    case '\n': return _make_token(TOK_NEWLINE, &scanner);
    case '=': return _make_token(TOK_EQUAL, &scanner);
    case '{': return _make_token(TOK_LEFT_BRACE, &scanner);
    case '}': return _make_token(TOK_RIGHT_BRACE, &scanner);
    case '[': return _make_token(TOK_LEFT_BRACKET, &scanner);
    case ']': return _make_token(TOK_RIGHT_BRACKET, &scanner);
    case ',': return _make_token(TOK_COMMA, &scanner);
  }

  return _make_error_token(&scanner, "TODO(Implement)");
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
// format: $() inside strings, if this sequence appears within a string without an escape, check
// class: no overlap
// function: no overlap
// tra: := no overlap
// TODO(Add others, this is where im going to write the initial tokenizer)

bool build_token_list(DynArray* array, char* text) {
  Token token = _scan_token(text);
  print_token(&token);
  return true;
}
