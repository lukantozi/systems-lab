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

clean:
	rm -rf build/*
