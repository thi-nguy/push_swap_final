/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 18:53:32 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/07/19 11:18:50 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_algorithm(t_push_swap *info)
{
	int	result;

	info->search_range = 3;
	result = sort_stack_a(info);
	if (result == 1)
		return ;
	sort_stack_b(info);
}

int	sort_stack_a(t_push_swap *info)
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

void	sort_stack_b(t_push_swap *info)
{
	while (is_stack_decreasing(info->b_head) == 0 && info->size_b > 2)
		find_big_values_and_push_into_a(info);
	if (is_stack_decreasing(info->b_head) == 0 && info->size_b == 2)
	{
		execute_command(info, SB);
		execute_command(info, PA);
		execute_command(info, PA);
	}
	else if (is_stack_decreasing(info->b_head) == 1 && info->size_b == 2)
	{
		execute_command(info, PA);
		execute_command(info, PA);
	}
	else
	{
		while (info->b_head)
			execute_command(info, PA);
	}
}
