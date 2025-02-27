/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgerbaul <jgerbaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 22:36:48 by jgerbaul          #+#    #+#             */
/*   Updated: 2025/02/26 22:47:29 by jgerbaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	side_minus_wall2(t_cube *cube)
{
	if (cube->worldmap[(int)cube->player->posx][(int)(cube->player->posy
		+ cube->player->dirx * cube->player->movespeed * 4)] == '0'
		|| cube->worldmap[(int)cube->player->posx][(int)(cube->player->posy
		+ cube->player->dirx * cube->player->movespeed * 4)] == 'N'
		|| cube->worldmap[(int)cube->player->posx][(int)(cube->player->posy
		+ cube->player->dirx * cube->player->movespeed * 4)] == 'E'
		|| cube->worldmap[(int)cube->player->posx][(int)(cube->player->posy
		+ cube->player->dirx * cube->player->movespeed * 4)] == 'S'
		|| cube->worldmap[(int)cube->player->posx][(int)(cube->player->posy
		+ cube->player->dirx * cube->player->movespeed * 4)] == 'W')
		cube->player->posy += cube->player->dirx * cube->player->movespeed * 4;
}

void	side_minus_wall(t_cube *cube)
{
	if (cube->worldmap[(int)(cube->player->posx - cube->player->diry
			* cube->player->movespeed * 4)][(int)cube->player->posy] == '0'
		|| cube->worldmap[(int)(cube->player->posx - cube->player->diry
		* cube->player->movespeed * 4)][(int)cube->player->posy] == 'N'
		|| cube->worldmap[(int)(cube->player->posx - cube->player->diry
		* cube->player->movespeed * 4)][(int)cube->player->posy] == 'E'
		|| cube->worldmap[(int)(cube->player->posx - cube->player->diry
		* cube->player->movespeed * 4)][(int)cube->player->posy] == 'S'
		|| cube->worldmap[(int)(cube->player->posx - cube->player->diry
		* cube->player->movespeed * 4)][(int)cube->player->posy] == 'W')
		cube->player->posx -= cube->player->diry * cube->player->movespeed * 4;
	side_minus_wall2(cube);
}


void	backward_wall2(t_cube *cube)
{
	if (cube->worldmap[(int)cube->player->posx][(int)(cube->player->posy
		- cube->player->diry * cube->player->movespeed * 4)] == '0'
		|| cube->worldmap[(int)cube->player->posx][(int)(cube->player->posy
		- cube->player->diry * cube->player->movespeed * 4)] == 'N'
		|| cube->worldmap[(int)cube->player->posx][(int)(cube->player->posy
		- cube->player->diry * cube->player->movespeed * 4)] == 'E'
		|| cube->worldmap[(int)cube->player->posx][(int)(cube->player->posy
		- cube->player->diry * cube->player->movespeed * 4)] == 'S'
		|| cube->worldmap[(int)cube->player->posx][(int)(cube->player->posy
		- cube->player->diry * cube->player->movespeed * 4)] == 'W')
		cube->player->posy -= cube->player->diry * cube->player->movespeed * 4;
}

void	backward_wall(t_cube *cube)
{
	if (cube->worldmap[(int)(cube->player->posx - cube->player->dirx
			* cube->player->movespeed * 4)][(int)cube->player->posy] == '0'
		|| cube->worldmap[(int)(cube->player->posx - cube->player->dirx
		* cube->player->movespeed * 4)][(int)cube->player->posy] == 'N'
		|| cube->worldmap[(int)(cube->player->posx - cube->player->dirx
		* cube->player->movespeed * 4)][(int)cube->player->posy] == 'E'
		|| cube->worldmap[(int)(cube->player->posx - cube->player->dirx
		* cube->player->movespeed * 4)][(int)cube->player->posy] == 'S'
		|| cube->worldmap[(int)(cube->player->posx - cube->player->dirx
		* cube->player->movespeed * 4)][(int)cube->player->posy] == 'W')
		cube->player->posx -= cube->player->dirx * cube->player->movespeed * 4;
	backward_wall2(cube);
}

bool	set_player_pos(int x, int y, t_cube *cube)
{
	check_direction_player(cube->worldmap[y][x], cube);
	cube->player->posx = y + 0.5;
	cube->player->posy = x + 0.5;
	return (true);
}
