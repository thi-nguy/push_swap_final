#include "push_swap.h"

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

int     is_small_enough(t_stack *stack, int num, int size)
{
    int less_than_num;
    int more_than_num;

    less_than_num = 0;
    more_than_num = 0;
    while (stack)
    {
        if (stack->data > num)
            more_than_num++;
        else
            less_than_num++;
        stack = stack->next;
    }
    if (size > 300)
    {
        if (less_than_num > (size / 20) +1)
            return (0);
        return (1);
    }
    if (less_than_num > (size / 10) + 1)
        return (0);
    return (1);
}


int     get_min_of_search_range(t_push_swap *info)
{
    int min;
    int i;
    t_stack *current;

    current = info->a_head;
    min = current->data;
    i = 0;
    while (current->next != NULL && i < info->search_range - 1)
    {
        if (min > current->next->data)
            min = current->next->data;
        current = current->next;
        i++;
    }
    current = info->a_end;
    i = 0;
    while (current->prev != NULL && i < info->search_range - 1)
    {
        if (min > current->data)
            min = current->data;
        current = current->prev;
        i++;
    }
    return (min);
}


int     find_position(t_stack *stack, int min, int size)
{
    int position;

    position = 0;
    while (stack)
    {
        if (stack->data == min)
            break ;
        position++;
        stack = stack->next;
    }
    return (position);
}

