typedef __int128 int128_t;

/*
x = 2^64 * xh + xl
y = 2^64 * yh + yl

Product:
x * y = xl*yl + 2^64 * (xh*yl + xl*yh) + 2^128 * xh*yh

The 2^128 term is outside the stored 128-bit result, so:

pl = low_64(xl * yl)

ph = high_64(xl * yl) + xh*yl + xl*yh
*/

void store_prod(int128_t *dest, int64_t x, int64_t y)
{
    *dest = x * (int128_t)y;
}

/*
%rdi = dest
%rsi = x = xl
%rdx = y = yl
*/

store_prod:
    movq %rdx, %rax
    /* %rax = yl */

    cqto
    /* %rdx:%rax = sign-extended y
       %rdx = yh
       %rax = yl */

    movq %rsi, %rcx
    /* %rcx = xl */

    sarq $63, %rcx
    /* %rcx = xh */

    imulq %rax, %rcx
    /* %rcx = xh * yl
       Keep only low 64 bits */

    imulq %rsi, %rdx
    /* %rdx = xl * yh
       Keep only low 64 bits */

    addq %rdx, %rcx
    /* %rcx = xh*yl + xl*yh */

    mulq %rsi
    /* Unsigned multiply:
       %rdx:%rax = yl * xl

       %rax = low_64(yl * xl)  = pl
       %rdx = high_64(yl * xl) */

    addq %rcx, %rdx
    /* %rdx = high_64(xl*yl) + xh*yl + xl*yh
       %rdx = ph */

    movq %rax, (%rdi)
    /* Store pl: low 64 bits of product */

    movq %rdx, 8(%rdi)
    /* Store ph: high 64 bits of product */

    ret
