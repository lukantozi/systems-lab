#include <limits.h>

// You are given the task of writing a procedure int_size_is_32() that yields 1
// when run on a machine for which an int is 32 bits, and yields 0 otherwise. You are
// not allowed to use the sizeof operator. Here is a first attempt:


/* The following code does not run properly on some machines */
int bad_int_size_is_32() {
    /* Set most significant bit (msb) of 32-bit machine */
    int set_msb = 1 << 31;
    /* Shift past msb of 32-bit word */
    int beyond_msb = 1 << 32;

    /* set_msb is nonzero when word size >= 32
       beyond_msb is zero when word size <= 32 */
    return set_msb && !beyond_msb;
} // On a 32-bit SUN SPARC: warning: left shift count >= width of type


// A. In what way does our code fail to comply with the C standard?
// A: On a 32-bit or smaller bit size architectures, shifting bits 32 times
// to left is UB


/* 
 * B. Modify the code to run properly on any machine 
 * for which data type int is at least 32 bits. */
int int_size_is_32_on_at_least_32() {
    // derive one
    int msb = -1 & (1 << 31);

    return msb == INT_MIN;
}

/*
 * C. Modify the code to run properly on any machine
 * for which data type int is at least 16 bits. */
int int_size_is_32_on_at_least_16() {
    // derive msb by shifting bits
    // in safe chunks
    int msb = 1 << 15;
    msb <<= 15;
    msb <<= 1;
    int beyond_msb = msb << 1;
    return msb && !beyond_msb;
}
