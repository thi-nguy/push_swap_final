/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 18:51:57 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/07/18 13:07:41 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <unistd.h>

long int	ft_atoi(const char *str);
int			ft_isdigit(char c);
void		ft_bzero(void *str, size_t n);
size_t		ft_strlen(const char *str);
char		*ft_strdup(const char *src);

#endif
