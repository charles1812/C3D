/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspreafi <cspreafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 22:36:53 by jgerbaul          #+#    #+#             */
/*   Updated: 2025/03/23 03:59:37 by cspreafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	gest_key_press(int keycode, t_cube *cube)
{
	if (keycode == 65307)
		ft_exit(cube);
	if (keycode == 'w')
		cube->player->forward = 1;
	if (keycode == 'd')
		cube->player->side = 1;
	if (keycode == 'a')
		cube->player->side = -1;
	if (keycode == 's')
		cube->player->forward = -1;
	if (keycode == 65363 || keycode == 'e')
		cube->player->rot = 1;
	if (keycode == 65361 || keycode == 'q')
		cube->player->rot = -1;
	return (0);
}

int	gest_key_relase(int keycode, t_cube *cube)
{
	if (keycode == 'w')
		cube->player->forward = 0;
	if (keycode == 'd')
		cube->player->side = 0;
	if (keycode == 'a')
		cube->player->side = 0;
	if (keycode == 's')
		cube->player->forward = 0;
	if (keycode == 65363 || keycode == 'e')
		cube->player->rot = 0;
	if (keycode == 65361 || keycode == 'q')
		cube->player->rot = 0;
	return (0);
}

int	movement(t_cube *cube)
{
	double	olddirx;
	double	oldplanex;

	olddirx = cube->player->dirx;
	oldplanex = cube->player->planex;
	if (cube->player->forward == 1)
		move_forward(cube);
	if (cube->player->forward == -1)
		move_backward(cube);
	if (cube->player->side == -1)
		move_left(cube);
	if (cube->player->side == 1)
		move_right(cube);
	if (cube->player->rot == -1)
		rotation_left(cube, olddirx, oldplanex);
	if (cube->player->rot == 1)
		rotation_right(cube, olddirx, oldplanex);
	return (0);
}
