/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 18:53:32 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/07/18 14:46:00 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_algorithm(t_push_swap *info)
{
    int result;

    info->search_range = 3;
    result = sort_stack_a(info);
    if (result == 1)
        return ;
    sort_stack_b(info);
}


void    sort_three_numbers(t_push_swap *info)
{
    int num1;
    int num2;
    int num3;
    t_stack *tmp;

    tmp = info->a_head;
    num1 = info->a_head->data;
    num2 = info->a_head->next->data;
    num3 = info->a_end->data;
    if (is_stack_increasing(info->a_head) == 1)
        return ;
    if (num1 > num2 && num3 > num2 && num1 < num3)
        execute_command(info, SA);
    else if (num1 > num2 && num3 > num2 && num1 > num3)
        execute_command(info, RA);
    else if (num1 < num2 && num3 < num2 && num1 > num3)
        execute_command(info, RRA);
    else if (num1 < num2 && num3 < num2 && num1 < num3)
    {
        execute_command(info, RRA);
        execute_command(info, SA);
    }
    else if (num1 > num2 && num2 > num3)
    {
        execute_command(info, RA);
        execute_command(info, SA);
    }
}


t_push_swap   *execute_command(t_push_swap *info, t_command command)
{
    if (command == SA)
        swap(&info->a_head);
    else if (command == RA)
        rotate(&info->a_head, &info->a_end);
    else if (command == RRA)
        reverse_rotate(&info->a_head, &info->a_end);
    else if (command == SB)
        swap(&info->b_head);
    else if (command == RB)
        rotate(&info->b_head, &info->b_end);
    else if (command == RRB)
        reverse_rotate(&info->b_head, &info->b_end);
    else if (command == RR)
    {
        rotate(&info->a_head, &info->a_end);
        rotate(&info->b_head, &info->b_end);
    }
    else if (command == RRR)
    {
        reverse_rotate(&info->a_head, &info->a_end);
        reverse_rotate(&info->b_head, &info->b_end);
    }
    else if (command == SS)
    {
        swap(&info->a_head);
        swap(&info->b_head);
    }
    else if (command == PA)
    {
        push(&info->b_head, &info->a_head, &info->a_end);
        info->size_a++;
        info->size_b--;
    }
    else if (command == PB)
    {
        push(&info->a_head, &info->b_head, &info->b_end);
        info->size_a--;
        info->size_b++;
    }
    info->operation_list = add_command_to_end_of_operation_list(&info->operation_list, command);
    return (info);
}

t_node    *add_command_to_end_of_operation_list(t_node **list, t_command command)
{
    t_node *new;
    t_node *current;

    new = (t_node*)malloc(sizeof(t_node)* 1);
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

void    push(t_stack **stack1, t_stack **stack2_head, t_stack **stack2_end)
{
    int num;

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

void    swap(t_stack    **stack)
{
    int num;
    t_stack *tmp;

    num = (*stack)->data;
    tmp = *stack;
    tmp->data = tmp->next->data;
    tmp->next->data = num;
}

void    rotate(t_stack **head, t_stack **end)
{
    int num;
    t_stack *tmp_head;
    t_stack *tmp_end;

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

void    reverse_rotate(t_stack **head, t_stack **end)
{
    int num;
    t_stack *tmp_head;
    t_stack *tmp_end;

    tmp_head = *head;
    tmp_end = *end;
    num = tmp_end->data;
    while(tmp_end->data != tmp_head->data)
    {
        tmp_end->data = tmp_end->prev->data;
        tmp_end = tmp_end->prev;
    }
    tmp_head->data = num;
}






