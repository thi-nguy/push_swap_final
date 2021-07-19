/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 18:52:58 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/07/18 14:47:37 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicate(int *nbr, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (nbr[i] == nbr[j])
				return (-1);
			else
				j++;
		}
		i++;
	}
	return (1);
}

int	check_isdigit(int ac, char **av)
{
	int	i;
	int	j;	

	i = 1;
	while (i < ac)
	{
		j = 0;
		if (av[i][j] == '-')
			j++;
		while (av[i][j] != '\0')
		{
			if (ft_isdigit(av[i][j]) == 1)
				j++;
			else
				return (-1);
		}
		i++;
	}
	return (1);
}

int	check_int(int ac, char **av)
{
	int			i;
	long int	num;

	i = 1;
	while (i < ac)
	{
		num = ft_atoi(av[i]);
		if (num < -2147483648 || num > 2147483647)
			return (-1);
		i++;
	}
	return (1);
}

int	check_ascending(int *stack_a, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (stack_a[i] < stack_a[i + 1])
			i++;
		else
			return (-1);
	}
	return (1);
}

void	get_array(int ac, char **av, int *nbr)
{
	int			i;
	long int	num;

	i = 1;
	while (i < ac)
	{
		num = ft_atoi(av[i]);
		nbr[i - 1] = num;
		i++;
	}
}
