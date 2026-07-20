#include <stdio.h>
#include <limits.h>
/*
 * We are running programs where values of type int are 32 bits. They are repre-
 * sented in two’s complement, and they are right shifted arithmetically. Values of
 * type unsigned are also 32 bits.
 *
 * We generate arbitrary values x and y, and convert them to unsigned values as
 * follows: */

#if 0
/* Create some arbitrary values */
int x = random();
int y = random();

/* Convert to unsigned */
unsigned ux = (unsigned) x;
unsigned uy = (unsigned) y;

/*
 * For each of the following C expressions, you are to indicate whether or
 * not the expression always yields 1. If it always yields 1, describe the underlying
 * mathematical principles. Otherwise, give an example of arguments that make it
 * yield 0.
 */

int a = (x<y) == (-x>-y);
/* does not always yield 1;
 * say, we had x = INT_MIN, and y = -50, in
 * this case, x < y would be true, but -x would
 * evaluate to INT_MIN because of integer overflow
 * and would give INT_MIN, and y would become 50
 * which would lead for the expression `a` to evaluate
 * to 0 */

int b = ((x+y)<<4) + y-x == 17*y+15*x;
/* I believe the expression would always evalate to 1
 * since both sides of the equation represent
 * the same mathematical expressions, just with
 * utilizing commutativeness while multiplication;
 * if the product overflows, both of them would overflow
 * same, if the product stays within the boundaries,
 * obviously also the result would be the same */

int c = ~x+~y+1 == ~(x+y);
/* it always yields 1; after using two's
 * complement general identity in variables
 * ~x = -x - 1, and ~y = -y - 1 in the both
 * sides of the equation, we get -x - y - 1
 * proving that they will always be equal */

int d = (ux-uy) == -(unsigned)(y-x);
/* it always evaluate to 1 due to reasons below:
 * ux - uy is same bitwise as x - y;
 * (y - x) as int has same bit pattern as (x - y) negated
 * at the bit level and negation mod 2^32 is same as
 * ~(y - x) + 1 which (two's complement general identity)
 * equals -(y - x) mod 2^32 = (x - y) mod 2^32
 * so both sides of the equation after wrapping become
 * x - y mod 2^32 */


int e = ((x >> 2) << 2) <= x;
/* it will always evaluate to 1, since
 * performing shifts to right, can lose 1's
 * on the right side, shifting << 2 would only bring
 * 0's, giving either same (in case last two bits were 0's),
 * value of less (if first at least one of two bits were 1's) */
#endif

int main(void) {
#if 0
    printf("%d\n", -INT_MIN);
#endif /* test a */
    
#if 0
    int x = INT_MAX / 2;
    int y = INT_MAX / 3;
    int b = ((x+y)<<4) + y-x == 17*y+15*x;
    printf("%d\n", b);
    printf("%d\n", ((x + y) << 4) + y-x);
    printf("%d\n", 17*y+15*x);

    x = 5;
    y = 10;
    b = ((x+y)<<4) + y-x == 17*y+15*x;
    printf("%d\n", b);
    printf("%d\n", ((x + y) << 4) + y-x);
    printf("%d\n", 17*y+15*x);
#endif /* test b */

#if 0
    int x = 1;
    int y = INT_MAX;
    int c = ~x+~y+1 == ~(x+y);
    printf("%d\n", c);
#endif /* test c */

#if 0
    int x = INT_MIN;
    int y = 1;
    unsigned ux = (unsigned)x;
    unsigned uy = (unsigned)y;
    unsigned d = -(unsigned)(y - x);
    printf("%d\n", ux - uy == d);
#endif /* test d */
}
