#include "stack.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>

/*
 * Stores 1 in *ans and -1 in *pos if balanced.
 * Otherwise stores 0 in *ans.
 * *pos is either the first unmatched ')' encountered, or the
 * topmost unmatched '(' remaining after the scan
 */
void paren_match(const char *arr, size_t len, int *ans, int *pos) {
    stack *st = stack_init(len);
    assert(st != NULL);
    size_t i;
    int out, empty;

    for (i = 0; i < len; i++) {
        if (arr[i] == '(') {
            assert(stack_push(st, i) == 1);
        } else if (arr[i] == ')') {
            empty = stack_is_empty(st);
            assert(empty != -1);
            if (!empty) {
                assert(stack_pop(st, &out) == 1);
            } else {
                *ans = 0;
                *pos = i;
                stack_free(st);
                return;
            }
        }
    }

    empty = stack_is_empty(st);
    assert(empty != -1);

    if (empty) {
        *ans = 1;
        *pos = -1;
    } else {
        *ans = 0;
        assert(stack_peek(st, &out) == 1);
        *pos = out;
    }
    assert(stack_free(st) == 1);
}

int main(void) {
    const char *par1 = "()()";
    const char *par2 = "())";
    const char *par3 = "((()";
    const char *par4 = "(((()())))";
    const char *par5 = "))";
    int ans, pos;

    paren_match(par1, strlen(par1), &ans, &pos);
    assert(ans == 1);
    assert(pos == -1);

    paren_match(par2, strlen(par2), &ans, &pos);
    assert(ans == 0);
    assert(pos == 2);

    paren_match(par3, strlen(par3), &ans, &pos);
    assert(ans == 0);
    assert(pos == 1);

    paren_match(par4, strlen(par4), &ans, &pos);
    assert(ans == 1);
    assert(pos == -1);

    paren_match(par5, strlen(par5), &ans, &pos);
    assert(ans == 0);
    assert(pos == 0);
    puts("PASSED");
}
