#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <unistd.h>

long int					ft_atoi(const char *str);
int                 ft_isdigit(char c);
void	ft_bzero(void *str, size_t n);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *src);

#endif

