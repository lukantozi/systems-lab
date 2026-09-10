# Data Structures in C

C implementations of fundamental data structures, built from scratch with
concrete `int` payloads.

## Implemented structures

- **Dynamic vector**
  - Heap-allocated contiguous storage
  - Append, indexed insert/remove, pop, get, swap
  - Automatic growth and shrink
  - Size and capacity queries

- **Stack**
  - Built on the dynamic vector
  - Push, pop, peek, size
  - Constant-time minimum lookup through an auxiliary minimum vector

- **Circular queue**
  - Fixed-capacity circular buffer
  - Enqueue, dequeue, peek
  - Full and empty checks

- **Singly linked list**
  - Insert at the front, back, or a specific index
  - Remove from the front, back, or a specific index

- **Doubly linked list**
  - Head and tail pointers
  - Insert at the head, tail, before a node, or after a node
  - Remove from the head or tail

- **Hash map**
  - Separate chaining for collisions
  - String keys and `int` values
  - Insert/update, lookup, removal, and size query

- **Binary min-heap**
  - Built on the dynamic vector
  - Push, peek, pop, removal by value
  - Heapify-up and heapify-down operations

- **Binary search tree**
  - Parent, left-child, and right-child links
  - Search, insertion, in-order traversal, removal, and cleanup

## Layout

```text
include/    Public headers
src/        Data-structure implementations
tests/      Test programs
build/      Generated test binaries
Makefile    Build and test targets
```

## Build and test

The test builds use:

- C23
- `-Wall -Wextra -Wpedantic`
- AddressSanitizer
- UndefinedBehaviorSanitizer

Run an individual test suite from this directory:

```sh
make vector
make stack
make queue
make list
make dlist
make hashmap
make heap
make bst
```

Each target builds its test executable in `build/` and runs it.

For example:

```sh
make heap
```

To remove generated build artifacts:

```sh
make clean
```

## Error conventions

Most operations return a status code:

- `1`: success
- `0`: expected non-success result where applicable, such as a missing key
- `-1`: invalid argument, allocation failure, empty structure, invalid index,
  or another operation failure

Operations that return an element use an output parameter, so stored values
such as `0` or `-1` remain valid payloads.
