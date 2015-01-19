
// Copyright 2015 Connor Taffe <cpaynetaffe@gmail.com>
// This program is free software licensed under the MIT license.

#include <stdlib.h>

#include "lex.h"

lexer *make_lexer(FILE *file) {
	lexer *lex = calloc(sizeof(lexer), 1);
	if (!lex) { return NULL; }

	lex->chan = make_chan();
	if (!lex->chan) { return NULL; }

	lex->lex = lex_init(128, file, /* lex func */);
	if (!lex->lex) { return NULL; }

	return lex;
}

void free_lexer(lexer *l) {
	lex_free(l->lex);
	free_chan(l->chan);
	free(l);
}
