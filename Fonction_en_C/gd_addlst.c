#include "includes.h"

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