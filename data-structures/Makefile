CC = gcc

CPPFLAGS = -Iinclude
CFLAGS = -std=c23 -Wall -Wextra -Wpedantic -g 
SANFLAGS = -fsanitize=address,undefined

.PHONY: vector stack queue list dlist hashmap clean

VECTOR = build/vector
VECTOR_SRC = tests/test_vector.c src/vector.c
VECTOR_HDR = include/vector.h

STACK = build/stack
STACK_SRC = tests/test_stack.c src/vector.c src/stack.c
STACK_HDR = include/stack.h

QUEUE = build/queue
QUEUE_SRC = tests/test_queue.c src/queue.c
QUEUE_HDR = include/queue.h

LIST = build/list
LIST_SRC = tests/test_list.c src/list.c
LIST_HDR = include/list.h

DLIST = build/dlist
DLIST_SRC = tests/test_dlist.c src/dlist.c
DLIST_HDR = include/dlist.h

HASHMAP = build/hashmap
HASHMAP_SRC = tests/test_hashmap.c src/hashmap.c
HASHMAP_HDR = include/hashmap.h

vector: $(VECTOR)
	./$(VECTOR)

$(VECTOR): $(VECTOR_SRC) $(VECTOR_HDR)
	mkdir -p build
	$(CC) $(CPPFLAGS) $(CFLAGS) $(SANFLAGS) $(VECTOR_SRC) -o $(VECTOR)

stack: $(STACK)
	./$(STACK)

$(STACK): $(STACK_SRC) $(STACK_HDR)
	mkdir -p build
	$(CC) $(CPPFLAGS) $(CFLAGS) $(SANFLAGS) $(STACK_SRC) -o $(STACK)

queue: $(QUEUE)
	./$(QUEUE)

$(QUEUE): $(QUEUE_SRC) $(QUEUE_HDR)
	mkdir -p build
	$(CC) $(CPPFLAGS) $(CFLAGS) $(SANFLAGS) $(QUEUE_SRC) -o $(QUEUE)

list: $(LIST)
	./$(LIST)

$(LIST): $(LIST_SRC) $(LIST_HDR)
	mkdir -p build
	$(CC) $(CPPFLAGS) $(CFLAGS) $(SANFLAGS) $(LIST_SRC) -o $(LIST)

dlist: $(DLIST)
	./$(DLIST)

$(DLIST): $(DLIST_SRC) $(DLIST_HDR)
	mkdir -p build
	$(CC) $(CPPFLAGS) $(CFLAGS) $(SANFLAGS) $(DLIST_SRC) -o $(DLIST)

hashmap: $(HASHMAP)
	./$(HASHMAP)

$(HASHMAP): $(HASHMAP_SRC) $(HASHMAP_HDR)
	mkdir -p build
	$(CC) $(CPPFLAGS) $(CFLAGS) $(SANFLAGS) $(HASHMAP_SRC) -o $(HASHMAP)

clean:
	rm -rf build/*
