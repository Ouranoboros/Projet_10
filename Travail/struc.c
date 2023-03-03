#include "../Fonction_en_C/includes.h"

int main(void)
{
    type_lst *lst;
    type_lst *lst2;

    lst = (type_lst *)malloc(sizeof(lst));
    lst2 = (type_lst *)malloc(sizeof(lst2));

    lst->nbr = 1;
    lst->next = lst2;

    lst2->nbr = 2;
    lst2->next = lst;

    lst->prev = lst2;
    lst2->prev = lst;

    while (lst)
    {
        printf("Le nbr = %i\n", lst->nbr);
        printf("Le nbr = %i\n", lst->prev->nbr);

        lst = lst->next;

        if (lst2->next == lst)
            break;
    }

    free(lst);
    free(lst2);
}