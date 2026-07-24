CC = gcc

CPPFLAGS = -Iinclude
CFLAGS = -std=c23 -Wall -Wextra -Wpedantic -g 
SANFLAGS = -fsanitize=address,undefined

.PHONY: vector clean

VECTOR = build/vector
VECTOR_SRC = tests/test_vector.c src/vector.c
VECTOR_HDR = include/vector.h

STACK = build/stack
STACK_SRC = tests/test_stack.c src/vector.c src/stack.c
STACK_HDR = include/stack.h

QUEUE = build/queue
QUEUE_SRC = tests/test_queue.c src/queue.c
QUEUE_HDR = include/queue.h

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

clean:
	rm -rf build/*
