#include "../Fonction_en_C/includes.h"

int intComparator(const void *first, const void *second)
{
    int firstInt = *(const int *)first;
    int secondInt = *(const int *)second;
    return firstInt - secondInt;
}

type_lst *gd_lstcreator(int *array_int, int i)
{
    type_lst *lst;
    lst = (type_lst *)malloc(sizeof(lst));
    lst->nbr = array_int[i];
    lst->next = NULL;
    return lst;
}

void gd_lstadd(type_lst *lst, int *array_int, int i)
{
    type_lst *lst_new;

    while (lst->next)
    {
        lst = lst->next;
    }
    lst_new = gd_lstcreator(array_int, i);
    lst->next = lst_new;
}

int main(void)
{
    type_lst *lst;
    type_lst *lst_remain;
    int i = 0;

    int array_int[5] = {5, 6, 4, 2, 1};
    qsort(array_int, 5, sizeof(int), intComparator);

    lst = gd_lstcreator(array_int, i);
    i++;

    while (i < 5)
    {
        gd_lstadd(lst, array_int, i);
        i++;
    }
    while (lst)
    {
        printf("lst = %i\n", lst->nbr);
        lst_remain = lst->next;
        free(lst);
        lst = lst_remain;
    }
    free(lst);
}