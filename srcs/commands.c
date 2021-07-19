/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 11:03:43 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/07/19 11:12:56 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **stack1, t_stack **stack2_head, t_stack **stack2_end)
{
	int	num;

	num = (*stack1)->data;
	if (*stack2_head == NULL)
	{
		*stack2_head = add_to_empty(*stack2_head, num);
		*stack2_end = *stack2_head;
	}
	else
		*stack2_head = insert_at_beginning(*stack2_head, num);
	*stack1 = delete_first_node(*stack1);
}

void	swap(t_stack	**stack)
{
	int		num;
	t_stack	*tmp;

	num = (*stack)->data;
	tmp = *stack;
	tmp->data = tmp->next->data;
	tmp->next->data = num;
}

void	rotate(t_stack **head, t_stack **end)
{
	int		num;
	t_stack	*tmp_head;
	t_stack	*tmp_end;

	tmp_head = *head;
	tmp_end = *end;
	num = tmp_head->data;
	while (tmp_head->data != tmp_end->data)
	{
		tmp_head->data = tmp_head->next->data;
		tmp_head = tmp_head->next;
	}
	tmp_end->data = num;
}

void	reverse_rotate(t_stack **head, t_stack **end)
{
	int		num;
	t_stack	*tmp_head;
	t_stack	*tmp_end;

	tmp_head = *head;
	tmp_end = *end;
	num = tmp_end->data;
	while (tmp_end->data != tmp_head->data)
	{
		tmp_end->data = tmp_end->prev->data;
		tmp_end = tmp_end->prev;
	}
	tmp_head->data = num;
}

t_node	*add_command_to_end_of_operation_list(t_node **list, t_command command)
{
	t_node	*new;
	t_node	*current;

	new = (t_node *)malloc(sizeof(t_node) * 1);
	if (!new)
		return (NULL);
	new->data = command;
	new->next = NULL;
	if (*list == NULL)
		return (new);
	current = *list;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
	return (*list);
}
