/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspreafi <cspreafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 22:36:51 by jgerbaul          #+#    #+#             */
/*   Updated: 2025/03/23 01:18:28 by cspreafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	rotation_right(t_cube *cube, double olddirx, double oldplanex)
{
	cube->player->dirx = cube->player->dirx * cos(-cube->player->rotspeed)
		- cube->player->diry * sin(-cube->player->rotspeed);
	cube->player->diry = olddirx * sin(-cube->player->rotspeed)
		+ cube->player->diry * cos(-cube->player->rotspeed);
	cube->player->planex = cube->player->planex * cos(-cube->player->rotspeed)
		- cube->player->planey * sin(-cube->player->rotspeed);
	cube->player->planey = oldplanex * sin(-cube->player->rotspeed)
		+ cube->player->planey * cos(-cube->player->rotspeed);
}

void	rotation_left(t_cube *cube, double olddirx, double oldplanex)
{
	cube->player->dirx = cube->player->dirx * cos(cube->player->rotspeed)
		- cube->player->diry * sin(cube->player->rotspeed);
	cube->player->diry = olddirx * sin(cube->player->rotspeed)
		+ cube->player->diry * cos(cube->player->rotspeed);
	cube->player->planex = cube->player->planex * cos(cube->player->rotspeed)
		- cube->player->planey * sin(cube->player->rotspeed);
	cube->player->planey = oldplanex * sin(cube->player->rotspeed)
		+ cube->player->planey * cos(cube->player->rotspeed);
}

int	check_around_player(int x, int y, t_cube *cube)
{
	if (!cube->worldmap[y][x + 1] || cube->worldmap[y][x + 1] == ' ')
		return (ERROR);
	if (!cube->worldmap[y][x - 1] || cube->worldmap[y][x - 1] == ' ')
		return (ERROR);
	if (!cube->worldmap[y + 1][x] || cube->worldmap[y + 1][x] == ' ')
		return (ERROR);
	if (!cube->worldmap[y - 1][x] || cube->worldmap[y - 1][x] == ' ')
		return (ERROR);
	return (VALID);
}

int	get_player_pos(t_cube *cube)
{
	int		x;
	int		y;
	bool	flag;

	flag = false;
	y = get_start_map(cube);
	while (++y < map_len(cube->worldmap))
	{
		x = -1;
		while (cube->worldmap[y][++x] && x < (int)ft_strlen(cube->worldmap[y]))
		{
			if (cube->worldmap[y][x] == 'N' || cube->worldmap[y][x] == 'S'
				|| cube->worldmap[y][x] == 'E' || cube->worldmap[y][x] == 'W')
			{
				if (flag == false)
					flag = set_player_pos(x, y, cube);
				else if (flag == true || check_around_player(x,
						y, cube) != VALID)
					return (ERROR);
			}
		}
	}
	if (!flag)
		return (ERROR);
	return (VALID);
}
