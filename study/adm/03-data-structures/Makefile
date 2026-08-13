CC = gcc
DS_DIR = $(HOME)/code/systems-lab/data-structures
CPPFLAGS = -I$(DS_DIR)/include

.PHONY: paren-match clean

PAREN = build/paren-match
SRC = $(DS_DIR)/src/stack.c $(DS_DIR)/src/vector.c paren_match.c
HDR = $(DS_DIR)/include/stack.h

paren-match: $(PAREN)
	./$(PAREN)

$(PAREN): $(SRC) $(HDR)
	mkdir -p build
	$(CC) $(CPPFLAGS) $(SRC) -o $(PAREN)

clean:
	rm -rf build/*
