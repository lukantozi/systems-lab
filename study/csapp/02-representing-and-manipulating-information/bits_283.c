/*
 * Consider numbers having a binary representation consisting of an infinite string
 * of the form 0.y y y y y y . . . , where y is a k-bit sequence. For example, the binary
 * representation of 1/3 is 0.01010101 . . . (y = 01), while the representation of 1/5
 * is 0.001100110011 . . . (y = 0011).
 */

/*
 * A. Let Y = B2U k(y), that is, the number having binary representation y. Give
 * a formula in terms of Y and k for the value represented by the infinite string.
 * Hint: Consider the effect of shifting the binary point k positions to the right.
 */

/* Answer(A): x = Y / (2^k - 1) */

/*
 * B. What is the numeric value of the string for the following values of y?
 * (a) 101    = 5/7
 * (b) 0110   = 2/5
 * (c) 010011 = 19/63
 */
