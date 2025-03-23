/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap_symbols.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgerbaul <jgerbaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 00:16:44 by jgerbaul          #+#    #+#             */
/*   Updated: 2025/03/19 18:52:00 by jgerbaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	check_symbols(t_cube *cube)
{
	int	x;
	int	y;

	y = cube->start_map;
	while (cube->worldmap[y] != NULL)
	{
		x = 0;
		while (cube->worldmap[y][x])
		{
			if (cube->worldmap[y][x] != 'E' && cube->worldmap[y][x] != 'W'
			&& cube->worldmap[y][x] != 'S' && cube->worldmap[y][x] != 'N'
			&& cube->worldmap[y][x] != '1' && cube->worldmap[y][x] != '0'
			&& cube->worldmap[y][x] != ' ')
			{
				printf("Error symbol [%c]\n", cube->worldmap[y][x]);
				return (ERROR);
			}
			x++;
		}
		y++;
	}
	return (VALID);
}

int	check_space(t_cube *cube, int y, int x)
{
	if (cube->worldmap[y][x] == ' ')
	{
		if (cube->worldmap[y][x + 1] != ' ' && cube->worldmap[y][x + 1] != '1')
			return (1);
		else if (x != 0 && cube->worldmap[y][x - 1] != ' '
				&& cube->worldmap[y][x - 1] != '1')
			return (2);
		else if (cube->worldmap[y + 1] && cube->worldmap[y + 1][x] != ' '
				&& cube->worldmap[y + 1][x] != '1')
			return (3);
		else if (y != cube->start_map && cube->worldmap[y - 1][x] != ' '
				&& cube->worldmap[y - 1][x] != '1')
			return (4);
	}
	return (VALID);
}

int	check_zero(t_cube *cube, int y, int x, int tab_len)
{
	if (cube->worldmap[y][x] == '0')
	{
		if (!cube->worldmap[y][x + 1])
			return (ERROR);
		else if (x == 0)
			return (ERROR);
		else if (!cube->worldmap[y + 1])
			return (ERROR);
		else if (cube->worldmap[y][x] == '0' && y == cube->start_map)
			return (ERROR);
		else if (cube->worldmap[y][x] == '0' && y == tab_len - 1)
			return (ERROR);
		return (VALID);
	}
	return (VALID);
}

int	checkmap(t_cube *cube)
{
	int	x;
	int	y;
	int	tab_len;

	tab_len = map_len(cube->worldmap);
	y = cube->start_map;
	if (check_tab(cube, y) != VALID)
		return (ERROR);
	while (cube->worldmap[y])
	{
		x = 0;
		while (cube->worldmap[y] && cube->worldmap[y][x])
		{
			if (check_zero(cube, y, x, tab_len) != VALID)
				return (ERROR);
			else if (check_space(cube, y, x) != VALID)
				return (ERROR);
			x++;
		}
		y++;
	}
	return (VALID);
}
