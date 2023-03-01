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

void gd_putnbr(int nb_put)
{
    int quotient = nb_put;
    int remainder = 0;
    int size = 1;
    int i = 0;

    char value;
    char *tmp;
    char *ret;

    ret = (char *)malloc(sizeof(char) * 1);
    ret[0] = '\0';
    while (quotient > 0)
    {
        remainder = quotient % 10;
        quotient = quotient / 10;

        value = '0' + remainder;
        tmp = ret;
        free(ret);
        tmp = gd_join_two_string(&value, tmp);
        ret = tmp;
        size++;
    }

    write(1, ret, size);
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
    int nb_put = gd_putstr("Coucou, comment tu t'appelles ?");
    gd_putnbr(nb_put);

    // gd_putnbr_rec(50000);
}