/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 18:52:47 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/07/21 16:32:26 by thi-nguy         ###   ########.fr       */
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

void	get_argument_array(int ac, char **av, t_array *argument)
{
	int		i;
	char	**array;

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
		argument->size = ac - 1;
		return ;
	}
}

void	push_swap(t_push_swap *info, int *input, t_array *argument)
{
	parse_info(info, input, argument->size);
	sort_algorithm(info);
	print_operation_list(info->operation_list);
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
	status = check_error(argument.size, argument.tab, input);
	if (status == 0 || check_ascending(input, argument.size) == 1
		|| status == -1 || !input)
	{
		if (status == -1)
			write(1, "Error\n", 6);
		free_memory(&input, info.operation_list, &argument);
		return (0);
	}
	else
	{
		push_swap(&info, input, &argument);
		free_memory(&input, info.operation_list, &argument);
	}
	return (0);
}
