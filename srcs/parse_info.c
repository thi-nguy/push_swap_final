/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 18:53:08 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/07/17 18:53:10 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack  *add_to_empty(t_stack *head, int data)
{
    t_stack  *tmp;

    tmp = (t_stack*)malloc(sizeof(t_stack) * 1);
    if (!tmp)
        return (NULL);
    tmp->data = data;
    tmp->next = NULL;
    tmp->prev = NULL;
    head = tmp;
    return (head);
}

t_stack  *insert_at_beginning(t_stack *head, int data)
{
    t_stack  *tmp;

    tmp = (t_stack*)malloc(sizeof(t_stack) *1);
    if (!tmp)
        return (NULL);
    tmp->data = data;
    tmp->next = head;
    tmp->prev = NULL;
    head->prev = tmp;
    head = tmp;
    return (head);
}

void    parse_info(t_push_swap *info, int *input_array, int array_size)
{
    int     i;

    i = array_size - 1;
    info->a_head = add_to_empty(info->a_head, input_array[i]);
    info->a_end = info->a_head;
    i--;
    while (i >= 0)
    {
        info->a_head = insert_at_beginning(info->a_head, input_array[i]);
        i--;
    }
    info->size_a = array_size;
}
