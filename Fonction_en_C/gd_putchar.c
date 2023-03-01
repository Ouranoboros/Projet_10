#include "includes.h"

void gd_putchar(char c)
{
    write(1, &c, 1);
}