#include "includes.h"

int gd_strlen(char const *str)
{
    int i = 0;
    while (str[i])
        i++;
    return (i);
}