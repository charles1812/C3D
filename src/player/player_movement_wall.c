/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement_wall.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgerbaul <jgerbaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 22:36:44 by jgerbaul          #+#    #+#             */
/*   Updated: 2025/02/26 22:47:43 by jgerbaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	forward_wall2(t_cube *cube)
{
	if (cube->worldmap[(int)cube->player->posx][(int)(cube->player->posy
		+ cube->player->diry * cube->player->movespeed * 4)] == '0'
		|| cube->worldmap[(int)cube->player->posx][(int)(cube->player->posy
		+ cube->player->diry * cube->player->movespeed * 4)] == 'N'
		|| cube->worldmap[(int)cube->player->posx][(int)(cube->player->posy
		+ cube->player->diry * cube->player->movespeed * 4)] == 'E'
		|| cube->worldmap[(int)cube->player->posx][(int)(cube->player->posy
		+ cube->player->diry * cube->player->movespeed * 4)] == 'S'
		|| cube->worldmap[(int)cube->player->posx][(int)(cube->player->posy
		+ cube->player->diry * cube->player->movespeed * 4)] == 'W')
		cube->player->posy += cube->player->diry * cube->player->movespeed * 4;
}

void	forward_wall(t_cube *cube)
{
	if (cube->worldmap[(int)(cube->player->posx + cube->player->dirx
			* cube->player->movespeed * 4)][(int)cube->player->posy] == '0'
		|| cube->worldmap[(int)(cube->player->posx + cube->player->dirx
		* cube->player->movespeed * 4)][(int)cube->player->posy] == 'N'
		|| cube->worldmap[(int)(cube->player->posx + cube->player->dirx
		* cube->player->movespeed * 4)][(int)cube->player->posy] == 'E'
		|| cube->worldmap[(int)(cube->player->posx + cube->player->dirx
		* cube->player->movespeed * 4)][(int)cube->player->posy] == 'S'
		|| cube->worldmap[(int)(cube->player->posx + cube->player->dirx
		* cube->player->movespeed * 4)][(int)cube->player->posy] == 'W')
		cube->player->posx += cube->player->dirx * cube->player->movespeed * 4;
	forward_wall2(cube);
}

void	side_plus_wall2(t_cube *cube)
{
	if (cube->worldmap[(int)cube->player->posx][(int)(cube->player->posy
		- cube->player->dirx * cube->player->movespeed * 4)] == '0'
		|| cube->worldmap[(int)cube->player->posx][(int)(cube->player->posy
		- cube->player->dirx * cube->player->movespeed * 4)] == 'N'
		|| cube->worldmap[(int)cube->player->posx][(int)(cube->player->posy
		- cube->player->dirx * cube->player->movespeed * 4)] == 'E'
		|| cube->worldmap[(int)cube->player->posx][(int)(cube->player->posy
		- cube->player->dirx * cube->player->movespeed * 4)] == 'S'
		|| cube->worldmap[(int)cube->player->posx][(int)(cube->player->posy
		- cube->player->dirx * cube->player->movespeed * 4)] == 'W')
		cube->player->posy -= cube->player->dirx * cube->player->movespeed * 4;
}

void	side_plus_wall(t_cube *cube)
{
	if (cube->worldmap[(int)(cube->player->posx + cube->player->diry
			* cube->player->movespeed * 4)][(int)cube->player->posy] == '0'
		|| cube->worldmap[(int)(cube->player->posx + cube->player->diry
		* cube->player->movespeed * 4)][(int)cube->player->posy] == 'N'
		|| cube->worldmap[(int)(cube->player->posx + cube->player->diry
		* cube->player->movespeed * 4)][(int)cube->player->posy] == 'E'
		|| cube->worldmap[(int)(cube->player->posx + cube->player->diry
		* cube->player->movespeed * 4)][(int)cube->player->posy] == 'S'
		|| cube->worldmap[(int)(cube->player->posx + cube->player->diry
		* cube->player->movespeed * 4)][(int)cube->player->posy] == 'W')
		cube->player->posx += cube->player->diry * cube->player->movespeed * 4;
	side_plus_wall2(cube);
}
