/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 18:50:54 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/07/18 12:59:19 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>

# include "../libft/libft.h"

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_node
{
	int				data;
	struct s_node	*next;
}	t_node;

typedef struct s_push_swap
{
	t_stack		*a_head;
	t_stack		*b_head;
	t_stack		*a_end;
	t_stack		*b_end;
	t_node		*operation_list;
	int			size_a;
	int			size_b;
	int			search_range;
}	t_push_swap;

typedef enum e_command
{
	SA = 1,
	SB = 2,
	SS = 3,
	PA = 4,
	PB = 5,
	RA = 6,
	RB = 7,
	RR = 8,
	RRA = 9,
	RRB = 10,
	RRR = 11,
	Undefined = -1,
}	t_command;

// ! main_util.c
int			check_error(int ac, char **av, int *nbr);
void		get_array(int ac, char **av, int *nbr);
int			check_int(int ac, char **av);
int			check_isdigit(int ac, char **av);
int			check_duplicate(int *nbr, int len);
int			check_ascending(int *stack_a, int len);
int    execute_one_command(t_push_swap *info);
void    execute_two_command(t_push_swap *info);


// ! parse_info.c
void		parse_info(t_push_swap *info, int *input_array, int array_size);
t_stack		*add_to_empty(t_stack *head, int data);
t_stack		*insert_at_beginning(t_stack *head, int data);

// ! sort_algorithm.c
int			sort_stack_a(t_push_swap *info);
void		sort_algorithm(t_push_swap *info);
void		sort_three_numbers(t_push_swap *info);
t_push_swap	*execute_command(t_push_swap *info, t_command command);
void execute_swap(t_push_swap *info, t_command command);
void execute_rotate(t_push_swap *info, t_command command);
void execute_reverse_rotate(t_push_swap *info, t_command command);


// ! sort_algorithm_utils.c
int			is_stack_increasing(t_stack *stack);
t_node		*add_command_to_list(t_node **list, t_command command);
void		swap(t_stack **stack);
void		rotate(t_stack **head, t_stack **end);
void		reverse_rotate(t_stack **head, t_stack **end);
void		push(t_stack **stack1, t_stack **stack2_head, t_stack **stack2_end);

// ! print_operation_list.c
void		print_operation_list(t_node *head);
const char	*get_command_name(t_command command);

// ! find_small_values_and_push_into_b.c
void		find_small_values_and_push_into_b(t_push_swap *info);
int			get_min_of_search_range(t_push_swap *info);
int			is_small_enough(t_stack *stack, int num, int size);
void		move_up_smaller_number(t_push_swap *info, int position);
int			find_position(t_stack *stack, int min, int size);
void    	move_when_size_b_is_small(t_push_swap *info, int position);
void    	move_when_size_b_is_big(t_push_swap *info, int position);

// ! sort_stack_b.c
void		sort_stack_b(t_push_swap *info);
void		find_big_values_and_push_into_a(t_push_swap *info);
void		move_up_bigger_number(t_push_swap *info, int position);
int			is_big_enough(t_stack *stack, int num, int size);
int			get_max_of_search_range(t_push_swap *info);
int			is_stack_decreasing(t_stack *stack);
void		final_push(t_push_swap *info);
t_stack		*delete_first_node(t_stack *head);

#endif
