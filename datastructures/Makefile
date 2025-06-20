
CC = gcc
CFLAGS = -Wall -Iinclude
SRC = src
OBJ = $(SRC)/stack.c $(SRC)/queue.c $(SRC)/linked_list.c \
      $(SRC)/doubly_linked_list.c $(SRC)/tree.c $(SRC)/hashmap.c $(SRC)/utils.c

all: example

example: $(OBJ) examples/main.c
	$(CC) $(CFLAGS) $^ -o example

clean:
	rm -f example
