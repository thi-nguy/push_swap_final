/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 18:52:47 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/07/18 14:06:18 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_error(int ac, char **av, int *nbr)
{
	if (ac == 1)
		return (0);
	if (check_isdigit(ac, av) == -1)
		return (-1);
	if (check_int(ac, av) == -1)
		return (-1);
	get_array(ac, av, nbr);
	if (check_duplicate(nbr, ac - 1) == -1)
		return (-1);
	return (1);
}

int	main(int ac, char **av)
{
	int			status;
	int			*input;
	t_push_swap	info;

	input = (int *)malloc(sizeof(int) * (ac - 1));
	if (!input)
		return (0);
	status = check_error(ac, av, input);
	if (status == 0 || check_ascending(input, ac - 1) == 1)
		return (0);
	else if (status == -1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	else
	{
		ft_bzero(&info, sizeof(info));
		parse_info(&info, input, ac - 1);
		sort_algorithm(&info);
		print_operation_list(info.operation_list);
	}
	return (0);
}
