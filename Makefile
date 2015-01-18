
CFLAGS = --std=c99

LIB = ds/ds.a

lisk: $(LIB) main.o
	$(CC) $(CFLAGS) -o lisk main.o $(LIB)

main.o: ds/chan.h

$(LIB):
	$(MAKE) -C $(dir $(LIB))
