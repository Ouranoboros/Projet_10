#include <unistd.h>

/*
Print dans le terminal le caractère envoyé en paramètre
*/
void gd_putchar(char c)
{
    write(1, &c, 1);
}

/*
Renvoie la longueur d'une chaine de caractère
*/
int gd_strlen(char *str)
{
}

/*
Print dans le terminal la chaine de caractère
et renvoie le nombre de caractère imprimé
*/
int gd_putstr(char *str)
{
}

/*
Print l'entier donné en paramètre
*/
void gd_putnbr(int nbr)
{
}

int main(void)
{
    int nb_put = gd_putstr("Coucou");
    gd_putnbr(nb_put);
}