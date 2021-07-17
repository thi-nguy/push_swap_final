#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	int		l;
	char	*dest;

	l = ft_strlen(src);
	dest = (char*)malloc(sizeof(char) * l + 1);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
