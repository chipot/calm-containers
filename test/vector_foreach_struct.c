/**
 * Copyright (c) 2012, PICHOT Fabien Paul Leonard <pichot.fabien@gmail.com>
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR
 * IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
**/

struct test{
    int a;
    int b;
};

#define VECTOR_TYPE struct test
#define VECTOR_PREFIX test
#include "vector.h"

int gl_sum = 0;

static void
_each(struct test const *t)
{
    gl_sum += t->a + t->b;
}

int  main(int argc, const char *argv[])
{
    struct vector_test *vt;

    vt = v_test_new();
    for (int i = 0; i < 200; i += 2)
    {
        struct test tmp;

        tmp.a = i;
        tmp.b = i + 1;
        v_test_push(vt, &tmp);
    }
    v_test_foreach(vt, _each);
    if (gl_sum != 19900)
        return 1;
    return 0;
}
