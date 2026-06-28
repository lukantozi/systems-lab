struct foo; // incomplete type
            
struct foo *p; // pointer, no prblm

// struct foo f; // erro: incomplete type

struct foo {
    int x, y, z;
}; // now struct foo is complete

struct foo f; // success
              
void *p; // ok: pointer to incomplete type
         
void v; // error: declare variable of incomplete type

printf("%d\n", *p); // error: dereference incomplete type
