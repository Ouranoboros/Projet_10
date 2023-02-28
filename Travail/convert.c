#include <unistd.h>
#include <stdio.h>

int gd_atoi(char *str)
{
    int i, neg, result;
    i = 0;
    neg = 1;
    result = 0;

    while (str[i])
    {
        if ((str[i] >= 43 && str[i] <= 57) || (str[i] == 43 || str[i] == 45))
            break;
        i++;
    }
    if (str[i] == 43 || str[i] == 45)
    {
        if (str[i] == 45)
            neg = -1;
        i++;
    }
    while (str[i])
    {
        int value = str[i] - 48;
        result = result * 10 + value;
        i++;
    }
    return (result * neg);
}

int main(void)
{
    int nb_put = gd_atoi("nhhnrth-512154");
    printf("%i\n", nb_put);
}