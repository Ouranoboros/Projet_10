#include "includes.h"

char *gd_join(char const *s1, char const *s2)
{
    int size1, size2, i, x;
    i = 0;
    x = 0;

    char *ret;

    size1 = gd_strlen(s1);
    size2 = size1 + gd_strlen(s2) + 1;

    ret = (char *)malloc(sizeof(char) * size2);

    if (ret == NULL)
        return NULL;

    while (i < size1)
    {
        ret[i] = s1[i];
        i++;
    }

    while (i < size2)
    {
        ret[i] = s2[x];
        i++;
        x++;
    }

    return ret;
}