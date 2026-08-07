#include "hashmap.h"
#include <assert.h>
#include <stdlib.h>

int main(void) {
    hashmap *hm = hashmap_init(10);
    int ret = hashmap_put(hm, "monia", 3);
    assert(ret == 1);

    hashmap_put(hm, "luka", 5);

    int val;
    hashmap_get(hm, "monia", &val);
    assert(val == 3);

    hashmap_get(hm, "luka", &val);
    assert(val == 5);

    hashmap_free(hm);
    return 0;
}
