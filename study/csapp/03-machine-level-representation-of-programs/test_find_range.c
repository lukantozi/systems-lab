#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

typedef enum {
    NEG,
    ZERO,
    POS,
    OTHER
} range_t;

extern range_t find_range_branch(float x);
extern range_t find_range_cmov(float x);

static range_t find_range_reference(float x)
{
    if (x < 0)
        return NEG;
    if (x == 0)
        return ZERO;
    if (x > 0)
        return POS;
    return OTHER;
}

static float float_from_bits(uint32_t bits)
{
    float x;

    assert(sizeof x == sizeof bits);
    memcpy(&x, &bits, sizeof x);
    return x;
}

static void test_one(uint32_t bits)
{
    float x = float_from_bits(bits);
    range_t expected = find_range_reference(x);
    range_t branch_result = find_range_branch(x);
    range_t cmov_result = find_range_cmov(x);

    if (branch_result != expected || cmov_result != expected) {
        fprintf(stderr,
                "failure: bits=0x%08x expected=%d branch=%d cmov=%d\n",
                bits, expected, branch_result, cmov_result);
        assert(0);
    }
}

int main(void)
{
    uint32_t cases[] = {
        0x00000000, /* +0.0 */
        0x80000000, /* -0.0 */
        0x3f800000, /* +1.0 */
        0xbf800000, /* -1.0 */
        0x7f800000, /* +infinity */
        0xff800000, /* -infinity */
        0x7fc00000, /* quiet NaN */
        0x7fc00001, /* another NaN */
        0xffc00000, /* negative quiet NaN */
        0x00000001, /* smallest positive subnormal */
        0x80000001, /* smallest negative subnormal */
    };

    for (size_t i = 0; i < sizeof(cases) / sizeof(cases[0]); i++)
        test_one(cases[i]);

    puts("representative tests passed");
    return 0;
}
