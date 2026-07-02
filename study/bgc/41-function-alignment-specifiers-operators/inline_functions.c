/*
 * inline allows to embedd the whole function
 * in place of the caller to avoid the 
 * overhead of setting it up and tearing it down 
 * where the call was made
 */
static inline int add(int x, int y) {
    return x + y;
}
