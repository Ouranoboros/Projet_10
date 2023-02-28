#include <unistd.h>

void gd_putnbr(int nb_put)
{
    int unit, ten, tens_unit;
    unit = nb_put;

    if (nb_put <= 9)
    {
        unit = nb_put + '0';

        write(1, "\n", 1);
        write(1, &unit, 1);
        write(1, "\n", 1);
    }

    else if (nb_put <= 99)
    {
        ten = nb_put / 10;
        unit = nb_put % 10;

        ten = '0' + ten;
        unit = '0' + unit;

        write(1, "\n", 1);
        write(1, &ten, 1);
        write(1, &unit, 1);
        write(1, "\n", 1);
    }

    else if (nb_put <= 999)
    {
        ten = nb_put / 100;
        tens_unit = (nb_put % 100) / 10;
        unit = nb_put % 10;

        ten = '0' + ten;
        tens_unit = '0' + tens_unit;
        unit = '0' + unit;

        write(1, "\n", 1);
        write(1, &ten, 1);
        write(1, &tens_unit, 1);
        write(1, &unit, 1);
        write(1, "\n", 1);
    }

    else
    {
        write(1, "\n", 1);
        write(1, "Le texte est supérieur à 1000 caractères!", 41);
    }
}

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

int main(void)
{
    int nb_put = gd_putstr("Coucou, comment tu t'appelles ?");
    gd_putnbr(nb_put);
}