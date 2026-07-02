_Atomic int x;
_Atomic int *p; // p is a pointer to an atomic int

p = &x; // OK
 
int x1;
int * _Atomic p1; // p1 is an atomic pointer to an int

p1 = &x1; // OK

_Atomic int x2;
_Atomic int * _Atomic p2; // p2 is an atomic poiner to an atomic int

p2 = &x2; // OK
