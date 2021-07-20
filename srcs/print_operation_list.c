/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_operation_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 18:53:17 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/07/20 13:46:06 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

const char	*get_command_name(t_command command)
{
	if (command == SA)
		return ("SA");
	else if (command == SB)
		return ("SB");
	else if (command == SS)
		return ("SS");
	else if (command == RA)
		return ("RA");
	else if (command == RB)
		return ("RB");
	else if (command == RR)
		return ("RR");
	else if (command == RRA)
		return ("RRA");
	else if (command == RRB)
		return ("RRB");
	else if (command == RRR)
		return ("RRR");
	else if (command == PA)
		return ("PA");
	else if (command == PB)
		return ("PB");
	else
		return (NULL);
}

void	print_operation_list(t_stack *head)
{
	char	*command;
	t_stack	*tmp;

	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	while (tmp != NULL)
	{
		command = ft_strdup(get_command_name(tmp->data));
		write(1, command, ft_strlen(command));
		write(1, "\n", 1);
		free(command);
		command = NULL;
		tmp = tmp->prev;
	}
}
