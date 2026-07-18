#include <stdio.h>

/*
 * You just started working for a company that is implementing a set of procedures
 * to operate on a data structure where 4 signed bytes are packed into a 32-bit
 * unsigned. Bytes within the word are numbered from 0 (least significant) to 3
 * (most significant). You have been assigned the task of implementing a function
 * for a machine using two’s-complement arithmetic and arithmetic right shifts with
 * the following prototype:
 */

/* Declaration of data type where 4 bytes are packed
   into an unsigned */
typedef unsigned packed_t;

/* Extract byte from word. Return as signed integer */
int xbyte(packed_t word, int bytenum);

/* That is, the function will extract the designated 
 * byte and sign extend it to be
 * a 32-bit int. Your predecessor (who was fired for incompetence) 
 * wrote the following code: */

/* Failed attempt at xbyte */
int failed_xbyte(packed_t word, int bytenum) {
    printf("%08x\n", (word >> (bytenum << 3)) & 0xFF);
    return (word >> (bytenum << 3)) & 0xFF;
}

/*
 * A. What is wrong with this code?
 * Answer: this solution fails to extend the
 * sign bit for x byte, 0ing out all the bits
 * before the byte we are extracting, and if 
 * those bits are 1s, after sign propagation
 * we are misinterpreting the real value of the x byte
 */

/*
 * B. Give a correct implementation of the function that uses only left and right
 * shifts, along with one subtraction. 
 */
int xbyte(packed_t word, int bytenum) {
    int shift = (3 - bytenum) << 3;
    printf("%08x\n", ((int)(word << shift) >> 24));
    return (int)(word << shift) >> 24;
}

int main(void) {
    packed_t x = 0x00EE0000;
    printf("%08x\n", x);
    int res = xbyte(x, 2);
    printf("%d\n", res);
}
