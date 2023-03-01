#include <stdlib.h>
#include <unistd.h>

int gd_strlen(char const *str)
{
    int i;
    i = 0;
    while (str[i])
        i++;
    return (i);
}

char *gd_join_two_string(char const *s1, char const *s2)
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

    write(1, ret, size2);
    return ret;
}

int main(void)
{
    char *s1, *s2, *joined;
    s1 = "Bonjour, com";
    s2 = "ment tu t'appeles ?";
    joined = gd_join_two_string(s1, s2);
    if (joined)
        free(joined);
}