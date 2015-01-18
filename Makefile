
CFLAGS = --std=c99

OBJ = main.o
BIN = lisk

LIB = ds/ds.a

lisk: $(LIB) $(OBJ)
	$(CC) $(CFLAGS) -o $(BIN) $(OBJ) $(LIB)

main.o: ds/chan.h

$(LIB):
	$(MAKE) INCLUDE=. -C $(dir $(LIB))

clean:
	rm -rf $(OBJ) $(BIN) # remove obj & bins
	$(MAKE) INCLUDE=. -C $(dir $(LIB)) clean # clean libs
