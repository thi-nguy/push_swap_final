#include "push_swap.h"

int     sort_stack_a(t_push_swap *info)
{
    while (is_stack_increasing(info->a_head) == 0 && info->size_a > 3)
        find_small_values_and_push_into_b(info);
    if (info->size_a == 3)
        sort_three_numbers(info);
    else if (is_stack_increasing(info->a_head) == 0 && info->size_a == 2)
        execute_command(info, SA);
    if (!info->b_head && is_stack_increasing(info->a_head) == 1)
        return (1);
    return (0);
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
