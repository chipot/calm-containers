#define MAP_KEY_TYPE double
#define MAP_VALUE_TYPE int
#define MAP_PREFIX di
#include "map.h"

#include <stdio.h>


int    main(int argc, const char *argv[])
{
    struct map_di *m;
    int const *it1;
    int const *it2;

    m = m_di_new();
    m_di_insert(m, 0.5, 1);
    m_di_insert(m, 1.5, 2);
    m_di_insert(m, 2.5, 3);
    it1 = m_di_access(m, 2.5);
    m_di_insert(m, 2.5, 4);
    it2 = m_di_access(m, 2.5);
    if (it1 != it2)
        return 1;
    m_di_delete(m);
    return (0);
}
