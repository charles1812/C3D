#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*d;

	i = 0;
	d = (unsigned char *)str;
	while (i < n)
	{
		d[i++] = (unsigned char)c;
	}
	str = (void *)d;
	return (d);
}
