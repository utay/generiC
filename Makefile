CC=gcc

CFLAGS= -Wall -g -Wextra -std=c99 -O3

SRC_TEST_ARRAY= test/test_array.c src/array.c test/test.c
OBJ_TEST_ARRAY= ${SRC_TEST_ARRAY:.c=.o}

SRC_TEST_BT= test/test_binary_tree.c src/binary_tree.c test/test.c src/array.c
OBJ_TEST_BT= ${SRC_TEST_BT:.c=.o}

all: test/test_array test/test_binary_tree

test/test_array: $(OBJ_TEST_ARRAY)
	$(CC) $(CFLAGS) $(OBJ_TEST_ARRAY) -o test/test_array

test/test_binary_tree: $(OBJ_TEST_BT)
	$(CC) $(CFLAGS) $(OBJ_TEST_BT) -o test/test_binary_tree

clean:
	find . -name \*~ -exec rm \-fv {} \;
	find . -name \*.o -exec rm \-fv {} \;
	find . -name \*.d -exec rm \-fv {} \;
	rm -f test/test_array test/test_binary_tree
