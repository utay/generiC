CC=gcc

CFLAGS= -Wall -Wextra -std=c99 -O3

SRC_TEST_ARRAY= test/test_array.c src/array.c test/test.c
OBJ_TEST_ARRAY= ${SRC_TEST_ARRAY:.c=.o}

all: test/test_array

test/test_array: $(OBJ_TEST_ARRAY)
	$(CC) $(CFLAGS) $(OBJ_TEST_ARRAY) -o test_array
