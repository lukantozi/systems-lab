/* a in %rdi, b in %rsi */
short loop_while(short a, short b)
{
    short result = 0;
    while (a > b) {
        result += a * b;
        a = a - 1;
    }
    return result;
}
