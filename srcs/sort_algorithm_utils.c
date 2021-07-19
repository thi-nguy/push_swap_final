/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 18:53:41 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/07/17 18:53:43 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack  *delete_first_node(t_stack *head)
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


