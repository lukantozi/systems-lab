void psum1_opt(float a[], float p[], long n)
{
    p[0] = a[0];
    float prev = p[0];
    float sum;
    for (long i = 1; i < n; i++) {
        // p[i] = p[i-1] + a[i];
        sum = prev + a[i];
        p[i] = sum;
        prev = sum;
    } 
}
