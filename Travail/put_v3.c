#include <unistd.h>

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

void gd_putnbr(int nb_put)
{
    int quotient = nb_put;
    int remainder = 0;
    int result = 0;
    int e = 0;
    char c;
    while (quotient > 0)
    {
        remainder = quotient % 10;
        quotient = quotient / 10;
        c = '0' + remainder;
        gd_putchar(c);
        // Pour remettre les chiffre dans l'ordre : regarder strjoin
        result = remainder * e + result;
        e = e + 10;
    }
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
    gd_putnbr_rec(500000);
}