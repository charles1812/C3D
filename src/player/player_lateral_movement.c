/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_lateral_movement.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspreafi <cspreafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 22:36:48 by jgerbaul          #+#    #+#             */
/*   Updated: 2025/03/23 04:24:25 by cspreafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	move_right2(t_cube *cube)
{
	double	pd;

	pd = 0.2;
	if (cube->worldmap[(int)cube->player->posx][(int)(cube->player->posy
		- cube->player->dirx * (cube->player->movespeed * 4 + pd))] == '0'
		|| cube->worldmap[(int)cube->player->posx][(int)(cube->player->posy
		- cube->player->dirx * (cube->player->movespeed * 4 + pd))] == 'N'
		|| cube->worldmap[(int)cube->player->posx][(int)(cube->player->posy
		- cube->player->dirx * (cube->player->movespeed * 4 + pd))] == 'E'
		|| cube->worldmap[(int)cube->player->posx][(int)(cube->player->posy
		- cube->player->dirx * (cube->player->movespeed * 4 + pd))] == 'S'
		|| cube->worldmap[(int)cube->player->posx][(int)(cube->player->posy
		- cube->player->dirx * (cube->player->movespeed * 4 + pd))] == 'W')
		cube->player->posy -= cube->player->dirx * cube->player->movespeed * 4;
}

void	move_right(t_cube *cube)
{
	double	pd;

	pd = 0.2;
	if (cube->worldmap[(int)(cube->player->posx + cube->player->diry
			* (cube->player->movespeed * 4 + pd))]
			[(int)cube->player->posy] == '0'
		|| cube->worldmap[(int)(cube->player->posx + cube->player->diry
		* (cube->player->movespeed * 4 + pd))][(int)cube->player->posy] == 'N'
		|| cube->worldmap[(int)(cube->player->posx + cube->player->diry
		* (cube->player->movespeed * 4 + pd))][(int)cube->player->posy] == 'E'
		|| cube->worldmap[(int)(cube->player->posx + cube->player->diry
		* (cube->player->movespeed * 4 + pd))][(int)cube->player->posy] == 'S'
		|| cube->worldmap[(int)(cube->player->posx + cube->player->diry
		* (cube->player->movespeed * 4 + pd))][(int)cube->player->posy] == 'W')
		cube->player->posx += cube->player->diry * cube->player->movespeed * 4;
	move_right2(cube);
}

void	move_left2(t_cube *cube)
{
	double	pd;

	pd = 0.2;
	if (cube->worldmap[(int)cube->player->posx][(int)(cube->player->posy
		+ cube->player->dirx * (cube->player->movespeed * 4 + pd))] == '0'
		|| cube->worldmap[(int)cube->player->posx][(int)(cube->player->posy
		+ cube->player->dirx * (cube->player->movespeed * 4 + pd))] == 'N'
		|| cube->worldmap[(int)cube->player->posx][(int)(cube->player->posy
		+ cube->player->dirx * (cube->player->movespeed * 4 + pd))] == 'E'
		|| cube->worldmap[(int)cube->player->posx][(int)(cube->player->posy
		+ cube->player->dirx * (cube->player->movespeed * 4 + pd))] == 'S'
		|| cube->worldmap[(int)cube->player->posx][(int)(cube->player->posy
		+ cube->player->dirx * (cube->player->movespeed * 4 + pd))] == 'W')
		cube->player->posy += cube->player->dirx * cube->player->movespeed * 4;
}

void	move_left(t_cube *cube)
{
	double	pd;

	pd = 0.2;
	if (cube->worldmap[(int)(cube->player->posx - cube->player->diry
			* (cube->player->movespeed * 4 + pd))]
			[(int)cube->player->posy] == '0'
		|| cube->worldmap[(int)(cube->player->posx - cube->player->diry
		* (cube->player->movespeed * 4 + pd))][(int)cube->player->posy] == 'N'
		|| cube->worldmap[(int)(cube->player->posx - cube->player->diry
		* (cube->player->movespeed * 4 + pd))][(int)cube->player->posy] == 'E'
		|| cube->worldmap[(int)(cube->player->posx - cube->player->diry
		* (cube->player->movespeed * 4 + pd))][(int)cube->player->posy] == 'S'
		|| cube->worldmap[(int)(cube->player->posx - cube->player->diry
		* (cube->player->movespeed * 4 + pd))][(int)cube->player->posy] == 'W')
		cube->player->posx -= cube->player->diry * cube->player->movespeed * 4;
	move_left2(cube);
}
