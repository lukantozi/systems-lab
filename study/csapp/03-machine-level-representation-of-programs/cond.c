void cond(short a, short *p)
{
        if (!a)
                goto false;
        if (a >= *p)
                goto false;
        *p = a;
false:
        return 
}
