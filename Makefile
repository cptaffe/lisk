
# Copyright 2015 Connor Taffe <cpaynetaffe@gmail.com>
# This program is free software licensed under the MIT license.

CFLAGS = -g --std=c99

OBJ = main.o
BIN = lisk

LIB = chan/chan.a

lisk: $(LIB) $(OBJ)
	$(CC) $(CFLAGS) -o $(BIN) $(OBJ) $(LIB)

main.o: chan/chan.h

$(LIB):
	$(MAKE) INCLUDE=. -C $(dir $(LIB))

clean:
	rm -rf $(OBJ) $(BIN) # remove obj & bins
	$(MAKE) -C $(dir $(LIB)) clean # clean libs
