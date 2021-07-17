#include "push_swap.h"


t_stack  *delete_first_node(t_stack *head)
{
    if (head->next != NULL)
    {
        head = head->next;
        free(head->prev);
        head->prev = NULL;
    }
    else
    {
        free(head);
        head = NULL;
    }
    return (head);
}

void    print_list(t_stack *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}


