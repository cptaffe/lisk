
// Copyright 2015 Connor Taffe <cpaynetaffe@gmail.com>
// This program is free software licensed under the MIT license.

#ifndef LISK_TOK_H_
#define LISK_TOK_H_

enum tok_type {
	// list
	TOK_LIST_BEGIN,
	TOK_LIST_END,

	// identifier
	TOK_ID,

	// data types
	TOK_INT,
	TOK_FLOAT
}

typedef struct {
	enum tok_type;
	char *str;
} tok;

#endif // LISK_TOK_H_
