#include <stdio.h>

struct test
{
    void *ptr;
};

#define VECTOR_TYPE struct test
#define VECTOR_PREFIX test
#include "vector.h"


static int
find_ptr(struct test const *t, void *ctx)
{
    printf("%p == %p\n", t->ptr, ctx);
    return t->ptr == ctx;
}

int
main(int argc, const char *argv[])
{
    struct test t;
    struct vector_test *v = v_test_new();
    struct test *it;

    t.ptr = (void *)0x42;
    v_test_push(v, &t);
    it = v_test_find_if(v, find_ptr, (void *)0x42);
    if (it == v_test_end(v))
    {
        printf("Wrong return value %p\n", it);
        return 1;
    }
    else
    {
        printf("Right return value %p, ptr is %p\n", it, it->ptr);
    }
    return (0);
}
