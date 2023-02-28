#include <unistd.h>

int gd_atoi(char *str)
{
    int i, neg, ret;
    i = 0;

    while (str[i])
    {
        if ((str[i] >= 43 && str[i] <= 59) || (str[i] == 43 || str[i] == 45))
            break;
    }
    if (str[i] == 43 || str[i] == 45)
    {
        if (str[i] == 45)
            neg = -1;
    }
    i++;
    int value = str[i] - 48;
    return (ret * neg);
}

int main(void)
{
    gd_atoi("-5000");
}