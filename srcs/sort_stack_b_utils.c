/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_b_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 13:43:20 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/07/19 13:45:23 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_of_search_range(t_push_swap *info)
{
	int		max;
	int		i;
	t_stack	*current;

	current = info->b_head;
	max = current->data;
	i = 0;
	while (current->next != NULL && i < info->search_range - 1)
	{
		if (max < current->next->data)
			max = current->next->data;
		current = current->next;
		i++;
	}
	current = info->b_end;
	i = 0;
	while (current->prev != NULL && i < info->search_range - 1)
	{
		if (max < current->data)
			max = current->data;
		current = current->prev;
		i++;
	}
	return (max);
}

int	is_stack_decreasing(t_stack *stack)
{
	int	tmp;

	tmp = stack->data;
	stack = stack->next;
	while (stack != NULL)
	{
		if (stack->data < tmp)
		{
			tmp = stack->data;
			stack = stack->next;
		}
		else
			return (0);
	}
	return (1);
}
