/**
 * Copyright (c) 2012, PICHOT Fabien Paul Leonard <pichot.fabien@gmail.com>
 * Permission to use, copy, modify, and/or distribute this software for any purpose
 * with or without fee is hereby granted, provided that the above copyright notice
 * and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
 * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
 * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS
 * OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF
 * THIS SOFTWARE.
 **/

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

#define VECTOR_TYPE size_t
#define VECTOR_PREFIX size
#define VECTOR_TYPE_SCALAR
#include "vector.h"

int pred(size_t const *a, void *ctx)
{
    size_t const *b = (size_t *)ctx;
    return (*a >= *b);
}

/**
 *
 * This test will insert random value in the vector at a not so random place and
 * erase them all in a random order. This kind of test is performance critical
 * as there is a lot of memory move and memory streaming for searching the right
 * insert point and insert the value.
 *
 * Basically this test is the same that test1, but in this one, we look for the
 * right order of the elements.
 **/

int
make_test(struct vector_size *vs, size_t num)
{
    size_t i;
    size_t *it;
    size_t *ite;
    size_t last_val;

    for (i = 0; i < num; ++i)
    {
        size_t val = random() % num;
        size_t *it = v_size_find_if(vs, pred, &val);
        v_size_insert_at(vs, it, &val);
    }
    for (it = v_size_begin(vs),
         ite = v_size_end(vs),
         last_val = *it;
         it != ite;
         it = v_size_next(it))
    {
        /*fprintf(stderr, "%lu %lu\n", last_val, *it);*/
        if (last_val > *it)
        {
            /*fprintf(stderr, "at (%p) %lu is higher than %lu\n", it, last_val,
             *it);*/
            return 1;
        }
        last_val = *it;
    }
    for (i = 0; i < num; ++i)
    {
        size_t val = random() % vs->size;
        v_size_erase(vs, v_size_atref(vs, val));
    }
    if (vs->size != 0)
        return 1;
    return 0;
}

int	main(int argc, char *argv[])
{
    size_t num;
    int err;
    struct vector_size *vs;

    vs = v_size_new();
    srandom(time(NULL) * getpid());
    if (argc > 1)
        num = strtol(argv[1], 0, 10);
    else
        num = 5000;
    err = make_test(vs, num);
    v_size_delete(vs);
    return err;
}
