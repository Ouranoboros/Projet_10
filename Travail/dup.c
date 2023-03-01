#include <stdlib.h>
#include <stdio.h>

int gd_strlen(char const *str)
{
    int i;
    i = 0;
    while (str[i])
        i++;
    return (i);
}

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

int main(void)
{
    char *str;
    str = "Hello World";
    char *dup;

    dup = gd_strdup(str);
    printf("%s\n", dup);
    if (dup)
        free(dup);
}