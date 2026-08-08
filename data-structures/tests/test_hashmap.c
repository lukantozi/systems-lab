#include "hashmap.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int main(void) {
    int val;

    hashmap *hm = hashmap_init(10);
    assert(hm != NULL);

    hashmap_put(hm, "monia", 3);
    hashmap_put(hm, "luka", 5);
    hashmap_put(hm, "malwinka", 10);

    hashmap_get(hm, "monia", &val);
    assert(val == 3);

    hashmap_get(hm, "luka", &val);
    assert(val == 5);

    hashmap_get(hm, "malwinka", &val);
    assert(val == 10);
    assert(0 == hashmap_get(hm, "oliwer", &val));
    assert(3 == hashmap_size(hm));

    hashmap_put(hm, "malwinka", 20);
    hashmap_get(hm, "malwinka", &val);
    assert(20 == val);
    assert(3 == hashmap_size(hm));

    hashmap_put(hm, "luka", 55);
    hashmap_get(hm, "luka", &val);
    assert(55 == val);
    assert(3 == hashmap_size(hm));

    hashmap_put(hm, "oliwer", 3);
    hashmap_get(hm, "oliwer", &val);
    assert(3 == val);
    assert(4 == hashmap_size(hm));

    hashmap_remove(hm, "monia", &val);
    assert(3 == val);
    assert(3 == hashmap_size(hm));

    hashmap_remove(hm, "luka", &val);
    assert(55 == val);
    assert(2 == hashmap_size(hm));

    assert(1 == hashmap_remove(hm, "oliwer", &val));
    assert(3 == val);

    assert(0 == hashmap_get(hm, "oliwer", &val));
    assert(1 == hashmap_size(hm));

    assert(1 == hashmap_remove(hm, "malwinka", &val));
    assert(20 == val);

    assert(0 == hashmap_size(hm));

    hashmap_free(hm);

    hashmap *hm1 = hashmap_init(1);
    assert(hm1 != NULL);

    assert(1 == hashmap_put(hm1, "monia", 3));
    assert(1 == hashmap_put(hm1, "luka", 5));
    assert(1 == hashmap_put(hm1, "malwinka", 10));

    assert(1 == hashmap_remove(hm1, "luka", &val));
    assert(val == 5);

    assert(2 == hashmap_size(hm1));

    assert(1 == hashmap_remove(hm1, "monia", &val));
    assert(val == 3);
    assert(1 == hashmap_size(hm1));

    assert(1 == hashmap_get(hm1, "malwinka", &val));
    assert(val == 10);

    assert(0 == hashmap_get(hm1, "luka", &val));

    hashmap_free(hm1);

    return 0;
}
