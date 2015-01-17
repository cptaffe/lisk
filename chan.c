
// Copyright 2012 Connor Taffe <cpaynetaffe@gmail.com>
// This program is free software licensed under the MIT license.

#include <stdlib.h>

#include "chan.h"

chan *make_chan() {
	chan *ch = calloc(sizeof(chan), 1); // initially zeroed
	return ch;
}

void free_chan(chan *ch) {
	free(ch);
}

void *chan_get(chan *ch) {
	if (ch->ls == NULL) {
		return NULL;
	} else {
		list *ls = ch->ls;
		ch->ls = ch->ls->next;
		if (!ch->ls) {
			ch->end = NULL;
		}
		void *data = ls->data;
		free_list(ls);
		return data;
	}
}

int chan_put(chan *ch, void *data) {
	if (ch->end == NULL) {
		ch->end = make_list();
		if (!ch->end) {
			return 1;
		} else {
			ch->end->data = data;
			ch->ls = ch->end;
			return 0;
		}
	} else {
		ch->end->next = make_list();
		if (!ch->end->next) {
			return 1;
		} else {
			ch->end->next->data = data;
			ch->end = ch->end->next;
			return 0;
		}
	}
}
