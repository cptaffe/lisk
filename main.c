
// Copyright 2015 Connor Taffe <cpaynetaffe@gmail.com>
// This program is free software licensed under the MIT license.

#include <stdio.h>

#include "chan.h"

int main() {
	chan *ch = make_chan();
	if (!ch) { return 1; }

	int arr[100];
	for (int i = 0; i < 100; i++) {
		arr[i] = i + 1;
		chan_put(ch, &arr[i]);
	}

	void *i;
	while ((i = chan_get(ch))) {
		printf("got: %d\n", *((int *) i));
	}

	free_chan(ch);
}
