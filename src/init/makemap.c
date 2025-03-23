/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makemap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgerbaul <jgerbaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 22:30:24 by jgerbaul          #+#    #+#             */
/*   Updated: 2025/03/13 20:46:55 by jgerbaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

char	**make_map(int fd)
{
	char	**ret;
	char	*tmp;
	char	*tmp2;

	tmp2 = gc_alloc(sizeof(char *) + 1, 2);
	tmp = NULL;
	tmp2[0] = '\0';
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		tmp2 = ft_strjoin_gc(tmp2, tmp, 3);
		free(tmp);
	}
	ret = ft_split_gc(tmp2, '\n', 7);
	if (tmp)
		free(tmp);
	return (ret);
}
