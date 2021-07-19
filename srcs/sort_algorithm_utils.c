/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 18:53:41 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/07/19 11:21:46 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*delete_first_node(t_stack *head)
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

void	execute_swap(t_push_swap *info, t_command command)
{
	if (command == SA)
		swap(&info->a_head);
	else if (command == SB)
		swap(&info->b_head);
	else if (command == SS)
	{
		swap(&info->a_head);
		swap(&info->b_head);
	}
}

void	execute_rotate(t_push_swap *info, t_command command)
{
	if (command == RA)
		rotate(&info->a_head, &info->a_end);
	else if (command == RB)
		rotate(&info->b_head, &info->b_end);
	else if (command == RR)
	{
		rotate(&info->a_head, &info->a_end);
		rotate(&info->b_head, &info->b_end);
	}
}

void	execute_reverse_rotate(t_push_swap *info, t_command command)
{
	if (command == RRA)
		reverse_rotate(&info->a_head, &info->a_end);
	else if (command == RRB)
		reverse_rotate(&info->b_head, &info->b_end);
	else if (command == RRR)
	{
		reverse_rotate(&info->a_head, &info->a_end);
		reverse_rotate(&info->b_head, &info->b_end);
	}
}

t_push_swap	*execute_command(t_push_swap *info, t_command command)
{
	if (command == SA || command == SB || command == SS)
		execute_swap(info, command);
	else if (command == RA || command == RB || command == RR)
		execute_rotate(info, command);
	else if (command == RRA || command == RRB || command == RRR)
		execute_reverse_rotate(info, command);
	else if (command == PA)
	{
		push(&info->b_head, &info->a_head, &info->a_end);
		info->size_a++;
		info->size_b--;
	}
	else if (command == PB)
	{
		push(&info->a_head, &info->b_head, &info->b_end);
		info->size_a--;
		info->size_b++;
	}
	info->operation_list = add_command_to_list(&info->operation_list, command);
	return (info);
}
