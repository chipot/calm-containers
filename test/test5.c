#define MAP_KEY_TYPE double
#define MAP_VALUE_TYPE int
#define MAP_PREFIX di
#include "map.h"
#undef MAP_PREFIX
#undef MAP_KEY_TYPE
#undef MAP_VALUE_TYPE

#include <stdio.h>


int    main(int argc, const char *argv[])
{
    struct map_di m;
    int const *it;

    m_di_init(&m);
    m_di_insert(&m, 0.4, 1);
    m_di_insert(&m, 2.5, 1);
    m_di_insert(&m, 0.4, 1);
    it = m_di_access(&m, 2.5);
    if (it == NULL)
        return 1;
    else
    {
        m_di_remove(&m, 2.5);
        it = m_di_access(&m, 2.5);
        if (it != NULL)
            return 1;
    }
    m_di_delete(&m);
    return (0);
}
