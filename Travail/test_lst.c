#include "../Fonction_en_C/includes.h"

int intComparator(const void *first, const void *second)
{
    int firstInt = *(const int *)first;
    int secondInt = *(const int *)second;
    return firstInt - secondInt;
}

int main(void)
{
    int array_int[5] = {5, 6, 4, 2, 1};
    int i = 0;
    qsort(array_int, 5, sizeof(int), intComparator);

    while (i < 5)
    {
        printf("%i\n", array_int[i]);
        i++;
    }

    type_lst *lst;
    type_lst *lst2;
    type_lst *lst3;
    type_lst *lst4;
    type_lst *lst5;

    lst = (type_lst *)malloc(sizeof(lst));
    lst2 = (type_lst *)malloc(sizeof(lst2));
    lst3 = (type_lst *)malloc(sizeof(lst3));
    lst4 = (type_lst *)malloc(sizeof(lst4));
    lst5 = (type_lst *)malloc(sizeof(lst5));

    lst->nbr = array_int[0];
    lst2->nbr = array_int[1];
    lst3->nbr = array_int[2];
    lst4->nbr = array_int[3];
    lst5->nbr = array_int[4];

    lst->next = lst2;
    lst2->next = lst3;
    lst3->next = lst4;
    lst4->next = lst5;
    lst5->next = lst;

    lst->prev = lst5;
    lst2->prev = lst;
    lst3->prev = lst2;
    lst4->prev = lst3;
    lst5->prev = lst4;

    while (lst)
    {
        printf("le nbr = %i\n", lst->nbr);
        printf("Le nbr précédent = %i\n", lst->prev->nbr);
        lst = lst->next;

        if (lst5->next == lst)
        {
            break;
        }
    }

    free(lst);
    free(lst2);
    free(lst3);
    free(lst4);
    free(lst5);
}