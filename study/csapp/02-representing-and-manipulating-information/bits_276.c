/* The library function calloc has the following declaration: */
void *calloc(size_t nmemb, size_t size);

/*
 * According to the library documentation, “The calloc function allocates memory
 * for an array of nmemb elements of size bytes each. The memory is set to zero. If
 * nmemb or size is zero, then calloc returns NULL.”
 *
 * Write an implementation of calloc that performs the allocation by a call to
 * malloc and sets the memory to zero via memset. Your code should not have any
 * vulnerabilities due to arithmetic overflow, and it should work correctly regardless
 * of the number of bits used to represent data of type size_t.
 */

/* As a reference, functions malloc and memset have the following declarations: */
void *malloc(size_t size);
void *memset(void *s, int c, size_t n);

/* calloc implementation calling malloc and memset */
void *calloc(size_t nmemb, size_t size) {
    size_t memsize = nmemb * size;
    if (memsize == 0 || memsize / nmemb != size) return NULL;

    void *ptr = malloc(memsize);
    if (ptr == NULL) return NULL;

    memset(ptr, 0, memsize);
    return ptr;
}
