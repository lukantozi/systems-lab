#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbit.h>

void* copy_elements(void *ele_src[], int ele_cnt, size_t ele_size) {
    /*
     * Allocate buffer for ele_cnt objects, each of ele_size bytes
     * and copy from locations designated by ele_src
     */
    uint64_t asize = ele_cnt * (uint64_t) ele_size;
    if (asize != (size_t) asize) 
        /* can't pass in such number; would break */
        return NULL;
    /* asize will only reach malloc if it's not going to
     * overflow conversion to size_t */
    void *result = malloc(asize); //line:data:overflow
    if (result == NULL)
        /* malloc failed */
        return NULL;
    void *next = result;
    int i;
    for (i = 0; i < ele_cnt; i++) { //line:data:copyloop
        /* Copy object i to destination */
        memcpy(next, ele_src[i], ele_size);
        /* Move pointer to next memory region */
        next += ele_size;
    }
    return result;
}

int main(void) {
    printf("vulnerability patched\n");
}
