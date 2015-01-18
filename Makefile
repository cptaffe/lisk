
# Copyright 2015 Connor Taffe <cpaynetaffe@gmail.com>
# This program is free software licensed under the MIT license.

CFLAGS = -g --std=c99

OBJ = main.o
BIN = lisk

LIB = chan/chan.a lex/lex.a

lisk: $(LIB) $(OBJ)
	$(CC) $(CFLAGS) -o $(BIN) $(OBJ) $(LIB)

main.o: chan/chan.h

$(LIB):
	# making library submodules
	$(foreach lib,$(dir $(LIB)), $(MAKE) --directory=$(lib);)

clean:
	$(RM) $(OBJ) $(BIN) # remove obj & bins
	$(foreach lib,$(dir $(LIB)), $(MAKE) --directory=$(lib) clean;)
