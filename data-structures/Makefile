CC = gcc

CPPFLAGS = -Iinclude
CFLAGS = -std=c23 -Wall -Wextra -Wpedantic -g 
SANFLAGS = -fsanitize=address,undefined

.PHONY: vector clean

VECTOR = build/vector
VECTOR_SRC = tests/test_vector.c src/vector.c
VECTOR_HDR = include/vector.h

vector: $(VECTOR)
	./$(VECTOR)

$(VECTOR): $(VECTOR_SRC) $(VECTOR_HDR)
	mkdir -p build
	$(CC) $(CPPFLAGS) $(CFLAGS) $(SANFLAGS) $(VECTOR_SRC) -o $(VECTOR)

clean:
	rm -rf build/*
