#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

#define VECTOR_TYPE size_t
#define VECTOR_PREFIX size
#define VECTOR_TYPE_SCALAR
#include "vector.h"
#undef VECTOR_TYPE
#undef VECTOR_PREFIX
#undef VECTOR_TYPE_SCALAR

int pred(size_t const *a, size_t const *b)
{
    return !(*a >= *b);
}

int	main(int argc, char *argv[])
{
    struct vector_size vs;

    v_size_init(&vs);
    srandom(time(NULL) * getpid());
    if (argc > 1)
    {
	size_t num = strtol(argv[1], 0, 10);
	for (size_t i = 0; i < num; ++i)
	{
	    size_t val = random() % num;
	    size_t *it = v_size_find_if(&vs, &val, pred);
	    v_size_insert(&vs, it, &val);
	}
	for (size_t i = 0; i < num; ++i)
	{
	    size_t *it = v_size_begin(&vs);
	    for (size_t val = random() % vs.size;
		 val != 0;
		 --val, it = v_size_next(it));
	    {
		v_size_erase(&vs, it);
	    }
	}
	if (vs.size != 0)
	    return 1;
    }
    v_size_delete(&vs);
    return (0);
}
