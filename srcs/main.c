/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 18:52:47 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/07/20 18:03:08 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_error(int ac, char **av, int *nbr)
{
	if (ac == 0)
		return (0);
	if (check_isdigit(ac, av) == -1)
		return (-1);
	if (check_int(ac, av) == -1)
		return (-1);
	get_array(ac, av, nbr);
	if (check_duplicate(nbr, ac) == -1)
		return (-1);
	return (1);
}

static void	free_memory(int **input, t_stack *list, t_array *argument)
{
	if (input)
	{
		free(*input);
		*input = NULL;
	}
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
	int i = 0;
	while (i < argument->size)
	{
		free(argument->tab[i]);
		argument->tab[i] = NULL;
		i++;
	}
	free(argument->tab);
	argument->tab = NULL;
}

void	get_argument_array(int ac, char **av, t_array *argument)
{
	int i;
	char **array;

	if (ac == 2)
	{
		argument->tab = ft_split(av[1], ' ');
		argument->size = ft_count_words(av[1], ' ');
		return ;
	}
	else
	{
		argument->tab = malloc(sizeof(char *) * (ac - 1));
		if (!argument->tab)
			return ;
		i = 0;
		while (i < ac - 1)
		{
			argument->tab[i] = ft_strdup(av[i + 1]);
			i++;
		}
		argument->tab[i] = NULL;
		argument->size = ac - 1;
		return ;
	}
}

int	main(int ac, char **av)
{
	int			status;
	int			*input;
	t_array		argument;
	t_push_swap	info;

	ft_bzero(&argument, sizeof(argument));
	ft_bzero(&info, sizeof(info));
	get_argument_array(ac, av, &argument);
	input = (int *)malloc(sizeof(int) * argument.size);
	if (!input)
		return (0);
	status = check_error(argument.size, argument.tab, input);
	if (status == 0 || check_ascending(input, argument.size) == 1 || status == -1)
	{
		if (status == -1)
			write(1, "Error\n", 6);
		free_memory(&input, info.operation_list, &argument);
		return (0);
	}
	else
	{
		parse_info(&info, input, argument.size);
		sort_algorithm(&info);
		print_operation_list(info.operation_list);
		free_memory(&input, info.operation_list, &argument);
	}
	return (0);
}
