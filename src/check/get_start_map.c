/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_start_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgerbaul <jgerbaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 00:16:52 by jgerbaul          #+#    #+#             */
/*   Updated: 2025/03/22 00:30:25 by jgerbaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	get_start_map(t_cube *cube)
{
	int	i;

	i = 0;
	while (cube->worldmap[i])
	{
		if (ft_strncmp(cube->worldmap[i], "F", 1) == 0)
			i++;
		else if (ft_strncmp(cube->worldmap[i], "C", 1) == 0)
			i++;
		else if (ft_strncmp(cube->worldmap[i], "WE", 2) == 0)
			i++;
		else if (ft_strncmp(cube->worldmap[i], "EA", 2) == 0)
			i++;
		else if (ft_strncmp(cube->worldmap[i], "NO", 2) == 0)
			i++;
		else if (ft_strncmp(cube->worldmap[i], "SO", 2) == 0)
			i++;
		else
			return (i);
	}
	return (0);
}
