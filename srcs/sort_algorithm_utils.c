#include "push_swap.h"

int     get_search_range(int size)
{
    return (3);
}

int     is_stack_increasing(t_stack *stack)
{
    int tmp;

    tmp = stack->data;
    stack = stack->next;
    while (stack != NULL)
    {

        if (tmp < stack->data)
        {
            tmp = stack->data;
            stack = stack->next;
        }
        else
            return (0);
    }
    return (1);

}

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


