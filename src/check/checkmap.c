/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgerbaul <jgerbaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 00:16:48 by jgerbaul          #+#    #+#             */
/*   Updated: 2025/02/22 01:07:04 by jgerbaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	check_ext(char *s, int len)
{
	int		i;
	int		j;
	char	*ext;

	ext = ".cub";
	i = len - 4;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ext[j])
		{
			i++;
			j++;
		}
		else
		{
			printf("Map error ./Cube3d *.cub\n");
			return (ERROR);
		}
	}
	return (VALID);
}

int	check_tab(t_cube *cube, int y)
{
	int	i;

	while (cube->worldmap[y])
	{
		i = 0;
		while (cube->worldmap[y][i])
		{
			if (cube->worldmap[y][i] == '\t')
				return (ERROR);
			i++;
		}
		y++;
	}
	return (VALID);
}

int	check_no_so(t_cube *cube)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (i < map_len(cube->worldmap))
	{
		if (ft_strncmp(cube->worldmap[i], "NO", 2) == 0)
		{
			if (check_north(cube, cube->worldmap[i]) != true)
				return (ERROR);
			count++;
		}
		else if (ft_strncmp(cube->worldmap[i], "SO", 2) == 0)
		{
			if (check_south(cube, cube->worldmap[i]) != true)
				return (ERROR);
			count++;
		}
		i++;
	}
	if (count != 2)
		return (ERROR);
	return (VALID);
}

int	check_ea_we(t_cube *cube)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (i < map_len(cube->worldmap))
	{
		if (ft_strncmp(cube->worldmap[i], "EA", 2) == 0)
		{
			if (check_east(cube, cube->worldmap[i]) != true)
				return (ERROR);
			count++;
		}
		else if (ft_strncmp(cube->worldmap[i], "WE", 2) == 0)
		{
			if (check_west(cube, cube->worldmap[i]) != true)
				return (ERROR);
			count++;
		}
		i++;
	}
	if (count != 2)
		return (ERROR);
	return (VALID);
}

int	check_textures(t_cube *cube)
{
	if (check_no_so(cube) == ERROR)
		return (ERROR);
	if (check_ea_we(cube) == ERROR)
		return (ERROR);
	return (VALID);
}
