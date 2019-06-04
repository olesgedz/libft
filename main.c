#include <stdio.h>
#include <stdlib.h>
#include "libft.h"


int main(void)
{
    int i;
    t_vector v;
    vector_init(&v);
    v.add(&v,"Bonjour");
    v.add(&v, "tout");
    v.add(&v, "le");
    v.add(&v, "monde");

    for (i = 0; i < v.length(&v); i++)
        printf("%s ", (char *) v.get(&v, i));
    printf("\n");

    v.del(&v, 3);
    v.del(&v, 2);  
    v.del(&v, 1);

    v.set(&v, 0, "Hello");
    v.add(&v, "World");

    for (i = 0; i < v.length(&v); i++)
        printf("%s ", v.get(&v, i));
    printf("\n");

    v.free(&v);
}