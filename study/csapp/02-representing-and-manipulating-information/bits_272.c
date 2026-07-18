#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "bytes.h"

/*
 * You are given the task of writing a function that will copy an integer val into a
 * buffer buf, but it should do so only if enough space is available in the buffer.
 * Here is the code you write:
 */

/* Copy integer into buffer if space is available */
/* WARNING: The following code is buggy */
void bad_copy_int(int val, void *buf, int maxbytes) {
    if (maxbytes-sizeof(val) >= 0)
        memcpy(buf, (void *) &val, sizeof(val));
}

/*
 * This code makes use of the library function memcpy. Although its use is a bit
 * artificial here, where we simply want to copy an int, it illustrates an approach
 * commonly used to copy larger data structures.
 * You carefully test the code and discover that it always copies the value to the
 * buffer, even when maxbytes is too small.
 */

/*
 * A. Explain why the conditional test in the code always succeeds. Hint: The
 *
 * Answer: evaluation of maxbytes - sizeof(val) will always be >= 0.
 * When performing int and unsigned operations (of same ranks),
 * evaluating to value < 0, int is converted to unsigned (UINT_MAX + maxbytes), 
 * and as the final value we be >= 0. in case when maxbytes - sizeof(val) >= 0
 * initially, no misleading conversions are made, thus making the condition
 * non-functional, always evaluating to truth
  */

/*
 * B. Show how you can rewrite the conditional test to make it work properly.
 */
void copy_int(int val, void *buf, int maxbytes) {
    if (maxbytes - (int)sizeof(val) >= 0)
        memcpy(buf, (void *) &val, sizeof(val));
    else puts("not enough space");
}

int main(void) {
    char buf[4];
    copy_int(300, buf, 4);
    show_bytes((byte_pointer) buf, sizeof(buf));
    printf("%zu\n", sizeof(buf));
}
