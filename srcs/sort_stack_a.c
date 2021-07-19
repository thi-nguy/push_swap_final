/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_small_values_and_push_into_b.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 18:52:36 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/07/19 12:11:37 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	execute_one_command(t_push_swap *info)
{
	int	num1;
	int	num2;
	int	num3;

	num1 = info->a_head->data;
	num2 = info->a_head->next->data;
	num3 = info->a_end->data;
	if (num1 > num2 && num3 > num2 && num1 < num3)
	{
		execute_command(info, SA);
		return (1);
	}
	else if (num1 > num2 && num3 > num2 && num1 > num3)
	{
		execute_command(info, RA);
		return (1);
	}
	else if (num1 < num2 && num3 < num2 && num1 > num3)
	{
		execute_command(info, RRA);
		return (1);
	}
	return (0);
}

void	execute_two_command(t_push_swap *info)
{
	int	num1;
	int	num2;
	int	num3;

	num1 = info->a_head->data;
	num2 = info->a_head->next->data;
	num3 = info->a_end->data;
	if (num1 < num2 && num3 < num2 && num1 < num3)
	{
		execute_command(info, RRA);
		execute_command(info, SA);
	}
	else if (num1 > num2 && num2 > num3)
	{
		execute_command(info, RA);
		execute_command(info, SA);
	}
}

void	sort_three_numbers(t_push_swap *info)
{
	int		num1;
	int		num2;
	int		num3;
	t_stack	*tmp;

	tmp = info->a_head;
	num1 = info->a_head->data;
	num2 = info->a_head->next->data;
	num3 = info->a_end->data;
	if (is_stack_increasing(info->a_head) == 1)
		return ;
	if (execute_one_command(info))
		return ;
	execute_two_command(info);
}

void	find_small_values_and_push_into_b(t_push_swap *info)
{
	int	min_of_range;
	int	min_position;

	min_of_range = get_min_of_search_range(info);
	if (is_small_enough(info->a_head, min_of_range, info->size_a) == 1)
	{
		min_position = find_position(info->a_head, min_of_range, info->size_a);
		while (min_position > 0)
		{
			move_up_smaller_number(info, min_position);
			min_position = find_position(info->a_head, min_of_range,
					info->size_a);
		}
		execute_command(info, PB);
	}
	else
		move_up_smaller_number(info, min_position);
}

void	move_when_size_b_is_small(t_push_swap *info, int position)
{
	int	b1;
	int	b2;

	if (info->size_b < 2)
	{
		if (position == 1)
			execute_command(info, SA);
		else if (position == 2)
			execute_command(info, RA);
	}
	else if (info->size_b == 2)
	{
		b1 = info->b_head->data;
		b2 = info->b_head->next->data;
		if (position == 1 && b1 < b2)
			execute_command(info, SS);
		else if (position == 1)
			execute_command(info, SA);
		else if (position == 2)
			execute_command(info, RA);
	}
	execute_command(info, RRA);
}

void	move_when_size_b_is_big(t_push_swap *info, int position)
{
	int	b1;
	int	b2;
	int	b_end;

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

void	move_up_smaller_number(t_push_swap *info, int position)
{
	int	b1;
	int	b2;
	int	b_end;

	if (info->size_b < 2)
		move_when_size_b_is_small(info, position);
	else
		move_when_size_b_is_big(info, position);
}
