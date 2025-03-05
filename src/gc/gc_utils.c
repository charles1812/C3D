/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgerbaul <jgerbaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 00:13:56 by jgerbaul          #+#    #+#             */
/*   Updated: 2025/02/19 22:31:58 by jgerbaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

char	*ft_strdup_gc(const char *s, int imp)
{
	size_t	len;
	int		i;
	char	*dst;

	len = ft_strlen((char *)s);
	i = 0;
	dst = (char *)gc_alloc(sizeof(char) * (len + 1), imp);
	if (!dst)
		return (0);
	while (s[i])
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin_gc(char const *s1, char const *s2, int imp)
{
	char	*str;
	int		i;

	i = 0;
	str = NULL;
	str = gc_alloc(sizeof(char *) * (ft_strlen((char *)s1) + \
		ft_strlen((char *)s2) + 1), imp);
	if (str)
	{
		while (s1 && *s1 != '\0')
		{
			str[i] = *s1;
			i++;
			s1++;
		}
		while (s2 && *s2 != '\0')
		{
			str[i] = *s2;
			i++;
			s2++;
		}
		str[i] = '\0';
	}
	return (str);
}

void	*ft_calloc_gc(size_t nmemb, size_t size, int imp)
{
	void	*ptr;

	ptr = gc_alloc(nmemb * size, imp);
	if (ptr != NULL)
		ft_bzero(ptr, size * nmemb);
	return (ptr);
}
