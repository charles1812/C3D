#include "libft.h"
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		s++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}
