long lt_cnt = 0;
long ge_cnt = 0;

long absdiff_se(long x, long y)
{
    long result;
    if (x >= y) {
        ge_cnt++;
        result = x - y;
    } else {
        lt_cnt++;
        result = y - x;
    }
    return result;
}

long gotodiff_se_alt(long x, long y)
{
    long result;
    int test = x >= y;
    if (test)
        goto etrue;
    lt_cnt++;
    result = y - x;
    goto done;
etrue:
    ge_cnt++;
    result = x - y;
done:
    return result;
}
