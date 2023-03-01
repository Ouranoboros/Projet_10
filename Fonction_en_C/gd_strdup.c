#include "includes.h"

char *gd_strdup(char const *src)
{
    char *ret;
    int size;

    size = gd_strlen(src) + 1;
    ret = (char *)malloc(sizeof(char) * size);

    if (ret == NULL)
        return NULL;

    size = 0;

    while (src[size])
    {
        ret[size] = src[size];
        size++;
    }

    return ret;
}