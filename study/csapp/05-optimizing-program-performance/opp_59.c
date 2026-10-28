void merge_opt(long src1[], long src2[], long dest[], long n)
{
    long i1 = 0;
    long i2 = 0;
    long id = 0;
    long v1 = 0;
    long v2 = 0;
    int pick1 = 0;
    while (i1 < n && i2 < n) {
        v1 = src1[i1];
        v2 = src2[i2];
        pick1 = v1 < v2;
        dst[id++] = pick1 ? v1 : v2;
        i1 += pick1;
        i2 += (1 - pick1);
    }
}
