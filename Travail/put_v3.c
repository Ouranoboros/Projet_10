#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int gd_strlen(char *str)
{
    int i;
    i = 0;

    while (str[i] != '\0')
    {
        i++;
    }
    return (i);
}

int gd_putstr(char *str)
{
    int size = gd_strlen(str);
    write(1, str, size);
    return (size);
}

void gd_putchar(char c)
{
    write(1, &c, 1);
}

char *gd_join_two_string(char *s1, char *s2)
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

char *gd_putnbr(int nb_put)
{
    int quotient = nb_put;
    int remainder = 0;
    int size = 1;
    int i = 0;

    char value;
    char *tmp;
    char *ret;

    printf("%i", quotient);
    while (quotient > 0)
    {
        remainder = quotient % 10;
        quotient = quotient / 10;

        value = '0' + remainder;
        printf("%i", value);

        tmp = gd_join_two_string(tmp, &value);
        printf("%s", tmp);
        size++;
    }

    ret = (char *)malloc(sizeof(char) * size);
    if (ret == NULL)
        return NULL;

    while (tmp[i])
    {
        ret[i] = tmp[i];
        i++;
    }

    // printf("%s", ret);
    write(1, ret, size);

    return ret;
}

// application de la récursive, faire la gestion du moins
void gd_putnbr_rec(int nb_put)
{
    if (nb_put == 0)
        return;
    else
    {
        gd_putnbr_rec(nb_put / 10);
        gd_putchar(nb_put % 10 + '0');
    }
}

int main(void)
{
    char *str;
    int nb_put = gd_putstr("Coucou, comment tu t'appelles ?");
    str = gd_putnbr(nb_put);

    // gd_putnbr_rec(50000);

    if (str)
        free(str);
}