void cp_array(long *src, long *dest, long n)
{
    long i;
    for (i = 0; i < n; i++)
        dest[i] = src[i];
}

/*
 * a, an array of length 1,000; a[i] equals i
 *
 * 1. copy_array(a+1,a,999)
 * It would have CPE 1.2, dropping to 1.0 if loops are unrolled
 *
 * 2. copy_array(a,a+1,999)
 * It would slow down the process since what we have in src[i], depends on
 * previous dest[i] = src[i] operation.
 *
 * 3. 1 vs 2
 * Critical path in 2 is data dependendy and due to that, we get higher cpe
 *
 * 4. copy_array(a,a,999) performance:
 * similar to A
*/
