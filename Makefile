
CFLAGS = --std=c99

SRC = list.c chan.c main.c
OBJ = $(SRC:.c=.o)

BIN = lisk

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) -o $(BIN) $(OBJ)

$(OBJ): $(HDR)
