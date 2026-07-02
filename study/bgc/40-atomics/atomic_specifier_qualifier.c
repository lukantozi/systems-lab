// specifier
typedef _Atomic(double) atomic_double;

atomic_double f;
/*
 * Restrictions on the specifier: the type you’re making 
 * atomic can’t be of type array or function, nor can it be
 * atomic or otherwise qualified.
 */


// qualifier
_Atomic(int) i; // type specifier
_Atomic int  i; // type specifier

_Atomic volatile int k; // qualified atomic variable
/* 
 * Restrictions on qualifier: the type you're making
 * atomic can't be of type array or function
 */
