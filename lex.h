
// Copyright 2015 Connor Taffe <cpaynetaffe@gmail.com>
// This program is free software licensed under the MIT license.

#ifndef LISK_LEX_H_
#define LISK_LEX_H_

#include "chan/chan.h"
#include "lex/lex.h"
#include "tok.h"

typedef struct {
	lex *lex;
	int paren_depth;
} lexer;

lexer *make_lexer();
void free_lexer(lexer *l);

// starts lex thread.
int lexer_run(lexer *l);
int lexer_join(lexer *l);

// takes a lex pointer, returns lexed token (blocking).
// Must run lex_run to start lexing before calling lex_get or
// lex_get will block forever.
tok *lexer_get(lexer *l);

#endif // LISK_LEX_H_
