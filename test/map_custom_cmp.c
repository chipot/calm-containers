struct bite
{
    double d;
    int i;
};

int bite_cmp(struct bite const *a, void const *ctx)
{
    struct bite const *b = (struct bite *)ctx;
    return a->d == b->d && a->i == b->i;
}

#define MAP_KEY_TYPE struct bite
#define MAP_VALUE_TYPE int
#define MAP_PREFIX di
#define MAP_KEY_CMP bite_cmp
#include "map.h"
#include <stdio.h>


int    main(int argc, const char *argv[])
{
    struct map_di *m;
    int const *it;
    struct bite b = {
        .d = 0.5,
        .i = 1
    };

    m = m_di_new();
    m_di_insert(m, b, 5);
    b.d = 1.5;
    m_di_insert(m, b, 5);
    b.i = 5;
    m_di_insert(m, b, 15);
    it = m_di_access(m, b);
    printf("%p\n", it);
    if (it != NULL)
    printf("%d\n", *it);
    m_di_delete(m);
    return (0);
}
