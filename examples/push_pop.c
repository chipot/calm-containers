#include <stdlib.h>
#include <stdio.h>

struct contact
{
    char const *name;
    int age;
};

#define VECTOR_TYPE  struct contact
#define VECTOR_PREFIX contacts
#include "vector.h"

int	main(int argc, const char *argv[])
{
    struct vector_contacts *c;
    struct contact *it;

    c = v_contacts_new();
    /* Don't do that at home !*/
    v_contacts_push(c, (struct contact[]){{"Bob", 10}});
    it = v_contacts_begin(c);
    printf("Hello, My name is %s, I'm %d\n", it->name, it->age);
    v_contacts_delete(c);
    return (0);
}
