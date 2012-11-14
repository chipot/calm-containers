#define VECTOR_TYPE int
#define VECTOR_PREFIX foo
#include "vector.h"

#define VECTOR_TYPE char
#define VECTOR_PREFIX bar
#include "vector.h"

int    main(int argc, const char *argv[])
{
    struct vector_foo *vf;
    struct vector_bar *vb;

    vf = v_foo_new();
    vb = v_bar_new();

    v_foo_delete(vf);
    v_bar_delete(vb);
    return (0);
}
