#include <unistd.h>
#include <stdio.h>

void gd_putchar(char c)
{
    write(1, &c, 1);
}

int gd_putstr(char *str)
{
    int i;
    char c;
    i = 0;

    while (str[i] != '\0')
    {
        c = str[i];
        gd_putchar(c);
        i++;
    }
    return (i);
}

int main(void)
{
    int nb_put = gd_putstr("Coucou");
    printf("\n%i\n", nb_put);
}