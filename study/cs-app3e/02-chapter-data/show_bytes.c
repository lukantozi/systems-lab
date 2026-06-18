#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    size_t i;
    for (i = 0; i < len; i++)
        printf(" %.2x", start[i]);
    printf("\n");
}

void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x) {
    show_bytes((byte_pointer) &x, sizeof(void *));
}

void show_short(short x) {
    show_bytes((byte_pointer) &x, sizeof(short));
}

void show_long(long x) {
    show_bytes((byte_pointer) &x, sizeof(long));
}

void show_double(double x) {
    show_bytes((byte_pointer) &x, sizeof(double));
}

void test_show_bytes(int val) {
    int ival = val;
    float fval = (float) ival;
    int *pval = &ival;
    short sval = (short) ival;
    long lval = (long) ival;
    double dval = (double) ival;
    show_int(ival);
    show_float(fval);
    show_short(sval);
    show_long(lval);
    show_double(dval);
    show_pointer(pval);
}

void simple_show_a() {
    int val = 0x87654321;
    byte_pointer valp = (byte_pointer) &val;
    show_bytes(valp, 1);
    show_bytes(valp, 2);
    show_bytes(valp, 3);
}

void simple_show_b() {
    int val = 0x12345678;
    byte_pointer valp = (byte_pointer) &val;
    show_bytes(valp, 1);
    show_bytes(valp, 2);
    show_bytes(valp, 3);
}

void float_eg() {
    int x = 3490593;
    float f = (float) x;
    printf("For x = %d\n", x);
    show_int(x);
    show_float(f);

    x = 3510593;
    f = (float) x;
    printf("For x = %d\n", x);
    show_int(x);
    show_float(f);

}

void string_ueg() {
    const char *s = "ABCDEF";
    show_bytes((byte_pointer) s, strlen(s)); 
}

void string_leg() {
    const char *s = "abcdef";
    show_bytes((byte_pointer) s, strlen(s)); 
}

void show_twocomp() {
    short x = 12345; 
    short mx = -x; 

    show_bytes((byte_pointer) &x, sizeof(short)); 
    show_bytes((byte_pointer) &mx, sizeof(short)); 
}

int is_little_endian() {
    int x = 1;
    byte_pointer bp = (byte_pointer) &x;
    return *bp == 1; 
}

int least_and_rest() {
    int x = 0x89ABCDEF;
    int y = 0x76543210;
    size_t len = sizeof(int);

    byte_pointer bpx = (byte_pointer) &x;
    byte_pointer bpy = (byte_pointer) &y;

    show_bytes(bpx, len);
    show_bytes(bpy, len);

    if (is_little_endian()) {
        *bpy = *bpx;
        show_bytes(bpy, len);
    } else {
        bpy += len - 1;
        bpx += len - 1;
        *bpy = *bpx;
        show_bytes(bpy - (len - 1), len);
    }

    return y;
}

int main(int argc, char *argv[])
{
    int val = 12345;

    if (argc > 1) {
        val = strtol(argv[1], NULL, 0);
        printf("calling test_show_bytes\n");
        test_show_bytes(val);
        printf("%s\n", is_little_endian()? "Little endian": "Big endian");
    } else {
        printf("calling show_twocomp\n");
        show_twocomp();
        printf("Calling simple_show_a\n");
        simple_show_a();
        printf("Calling simple_show_b\n");
        simple_show_b();
        printf("Calling float_eg\n");
        float_eg();
        printf("Calling string_ueg\n");
        string_ueg();
        printf("Calling string_leg\n");
        string_leg();
        printf("%s\n", is_little_endian()? "Little endian": "Big endian");
    }
    least_and_rest();
    return 0;
}
