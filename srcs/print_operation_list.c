/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_operation_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 18:53:17 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/07/17 18:53:19 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

const char* get_command_name(t_command command)
{
   switch (command)
   {
      case SA: return "SA";
      case SB: return "SB";
      case SS: return "SS";
      case RA: return "RA";
      case RB: return "RB";
      case RR: return "RR";
      case RRA: return "RRA";
      case RRB: return "RRB";
      case RRR: return "RRR";
      case PA: return "PA";
      case PB: return "PB";
      case Undefined: break;
   }
   return (NULL);
}

void    print_operation_list(t_node *head)
{
    const char *command;
    while (head != NULL)
    {
        command = ft_strdup(get_command_name(head->data));
        write(1, command, ft_strlen(command));
        write(1, "\n", 1);
        head = head->next;
    }
}
