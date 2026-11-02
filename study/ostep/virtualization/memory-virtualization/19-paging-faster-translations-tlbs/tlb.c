#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/prctl.h>
#include <time.h>
#include <unistd.h>

#define SEC_TO_NSEC(x) ((x) * (1000 * 1000 * 1000))
#define ITER 200

int acc(int num)
{
    if (num == 0) {
        fprintf(stderr, "atoi: not an integer\n");
        exit(1);
    }
    if (num < 0) {
        fprintf(stderr, "atoi: accepting only non-zero values\n");
        exit(1);
    }
    return num;
}

void cgcc(int code)
{
    if (code == -1) {
        perror("clock_gettime");
        exit(1);
    }
}

void *mcc(void *mc)
{
    if (mc == NULL) {
        perror("malloc");
        exit(1);
    }
    return mc;
}

int scc(int psize)
{
    if (psize == -1) {
        perror("scc");
        exit(1);
    }
    return psize;
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: ./tlb NUMPAGES\n");
        return 1;
    }

    struct timespec st;
    struct timespec en;
    int numpages = acc(atoi(argv[1]));
    int pagesize = scc(sysconf(_SC_PAGESIZE));
    int jump = pagesize / sizeof(int);
    int *a = mcc(malloc(numpages * jump * sizeof(int)));
    int i;
    int j;
    for (i = 0; i < numpages * jump; i++) {
        a[i] = 0;
    }
        
    printf("pages: %d - ", numpages);
    cgcc(clock_gettime(CLOCK_REALTIME, &st));
    for (j = 0; j < ITER; j++) {
        for (i = 0; i < numpages * jump; i += jump) {
            a[i] += 1;
        }
    }
    cgcc(clock_gettime(CLOCK_REALTIME, &en));
    double cost_total_ns = SEC_TO_NSEC((en.tv_sec - st.tv_sec)) + (en.tv_nsec - st.tv_nsec);
    printf("cost %.3f ns\n", cost_total_ns / ITER / numpages);

    free(a);
}
