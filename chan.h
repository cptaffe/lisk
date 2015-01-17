
// Copyright 2012 Connor Taffe <cpaynetaffe@gmail.com>
// This program is free software licensed under the MIT license.

#ifndef CHAN_H_
#define CHAN_H_

#include "list.h"

// list struct
typedef struct {
	list *ls;
	list *end;
} chan;

// make & free
chan *make_chan();
void free_chan(chan *ch);

// list operations
void *chan_get(chan *ch); // remove next node
int chan_put(chan *ch, void *data); // inserts as next node

#endif // CHAN_H_
