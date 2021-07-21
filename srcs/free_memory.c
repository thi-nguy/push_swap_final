/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 18:52:47 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/07/21 16:35:13 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_input_and_argument(int **input, t_array *argument)
{
	int	i;

	i = 0;
	if (input)
	{
		free(*input);
		*input = NULL;
	}
	while (i < argument->size)
	{
		free(argument->tab[i]);
		argument->tab[i] = NULL;
		i++;
	}
	free(argument->tab);
	argument->tab = NULL;
}

void	free_memory(int **input, t_stack *list, t_array *argument)
{
	free_input_and_argument(input, argument);
	while (list)
	{
		if (list->next != NULL)
		{
			list = list->next;
			free(list->prev);
			list->prev = NULL;
		}
		else
		{
			free(list);
			list = NULL;
		}
	}
}
