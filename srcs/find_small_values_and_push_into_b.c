#include "push_swap.h"

void    find_small_values_and_push_into_b(t_push_swap *info)
{
    int min_of_a_range;
    int min_position;


    min_of_a_range = get_min_of_search_range(info);
    if (is_small_enough(info->a_head, min_of_a_range, info->size_a) == 1)
    {
        while ((min_position = find_position(info->a_head, min_of_a_range, info->size_a)) > 0)
            move_up_smaller_number(info, min_position);
        execute_command(info, PB);
    }
    else
        move_up_smaller_number(info, min_position);
}

void    move_up_smaller_number(t_push_swap *info, int position)
{
    int b1;
    int b2;
    int b_end;

    if (info->size_b < 2)
    {
        if (position == 1)
            execute_command(info, SA);
        else if(position == 2)
            execute_command(info, RA);
        else
            execute_command(info, RRA);
    }
    else if (info->size_b == 2)
    {
        b1 = info->b_head->data;
        b2 = info->b_head->next->data;
        if (position == 1 && b1 < b2)
            execute_command(info, SS);
        else if (position == 1)
            execute_command(info, SA);
        else if(position == 2)
            execute_command(info, RA);
        else
            execute_command(info, RRA);
    }
    else
    {
        b1 = info->b_head->data;
        b2 = info->b_head->next->data;
        b_end = info->b_end->data;
        if (position == 1 && b1 < b2)
            execute_command(info, SS);
        else if (position == 2 && b1 < b2 && b1 < b_end)
            execute_command(info, RR);
        else if (position == 1)
            execute_command(info, SA);
        else
            execute_command(info, RRA);
    }
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
