
// Copyright 2015 Connor Taffe <cpaynetaffe@gmail.com>
// This program is free software licensed under the MIT license.

#ifndef LISK_PARSE_H_
#define LISK_PARSE_H_

#include "lex.h"

// parser structure
typedef struct {
	chan *chan;
	tree *tree;
	lexer *lex;
} parser;

parser *make_parser();
void free_parser(parser *p);

tree *parser_get();

#endif // LISK_PARSE_H_
