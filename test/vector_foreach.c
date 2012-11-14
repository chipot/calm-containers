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

#define VECTOR_TYPE int
#define VECTOR_PREFIX i
#define VECTOR_TYPE_SCALAR
#include "vector.h"

#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

int gl_sum = 0;

static void
_each(int i)
{
    gl_sum += i;
}

int    main(int argc, const char *argv[])
{
    struct vector_i *vi;

    vi =v_i_new();
    for (int i = 0; i < 50; ++i)
    {
        v_i_push(vi, i);
    }
    v_i_foreach(vi, _each);
    if (gl_sum != 1225)
        return 1;
    return 0;
}
