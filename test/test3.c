#define VECTOR_TYPE int
#define VECTOR_PREFIX foo
#include "vector.h"
#undef VECTOR_TYPE
#undef VECTOR_PREFIX

#define VECTOR_TYPE char
#define VECTOR_PREFIX bar
#include "vector.h"
#undef VECTOR_TYPE
#undef VECTOR_PREFIX

int    main(int argc, const char *argv[])
{
  return (0);
}
