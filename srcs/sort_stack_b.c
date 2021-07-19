/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 18:53:50 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/07/17 18:53:52 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    find_big_values_and_push_into_a(t_push_swap *info)
{
    int max_of_range;
    int max_position;

    max_of_range = get_max_of_search_range(info);
    if (is_big_enough(info->b_head, max_of_range, info->size_b) == 1 )
    {
        while ((max_position = find_position(info->b_head, max_of_range, info->size_b)) > 0)
            move_up_bigger_number(info, max_position);
        final_push(info);
    }
    else
        move_up_bigger_number(info, max_position);

}

void    final_push(t_push_swap *info)
{
    int a1;
    int b1;
    int count;
    t_stack *tmp;

    tmp = info->a_head;
    a1 = tmp->data;
    b1 = info->b_head->data;
    count = 0;
    while (a1 < b1)
    {
        execute_command(info, RA);
        a1 = tmp->data;
        count++;
    }
    execute_command(info, PA);
    while (count > 0)
    {
        execute_command(info, RRA);
        count--;
    }
}

void    move_up_bigger_number(t_push_swap *info, int position)
{
    if (position == 1)
        execute_command(info, SB);
    else if (position == 2)
        execute_command(info, RB);
    else
        execute_command(info, RRB);
}

int     is_big_enough(t_stack *stack, int num, int size)
{
    int less_than_num;
    int more_than_num;

    less_than_num = 0;
    more_than_num = 0;
    while (stack)
    {
        if (stack->data >= num)
            more_than_num++;
        else
            less_than_num++;
        stack = stack->next;
    }
    if (size > 300)
    {
        if (more_than_num > (size / 20) +1)
            return (0);
        return (1);
    }
    if (more_than_num > (size / 10) + 1)
        return (0);
    return (1);

}
