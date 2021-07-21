/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 18:51:57 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/07/20 16:35:23 by thi-nguy         ###   ########.fr       */
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
int			ft_count_words(char const *s, char c);
void		ft_bzero(void *str, size_t n);
char		*ft_strdup(const char *src);
char		**ft_split(char const *s, char c);
size_t		ft_strlen(const char *str);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);

#endif
