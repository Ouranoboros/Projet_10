#include "includes.h"

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