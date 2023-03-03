#include "../Fonction_en_C/includes.h"

type_lst *gd_lstcreator(int *array_int, int i)
{
    type_lst *lst;
    lst = (type_lst *)malloc(sizeof(lst));
    lst->nbr = array_int[i];
    lst->next = NULL;
    return lst;
}