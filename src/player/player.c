/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgerbaul <jgerbaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 22:36:53 by jgerbaul          #+#    #+#             */
/*   Updated: 2025/02/26 02:26:35 by jgerbaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	gest_key_press2(int keycode, t_cube *cube)
{
	if (keycode == 65505)
		cube->player->movespeed *= 2;
	return (0);
}

int	gest_key_press(int keycode, t_cube *cube)
{
	if (keycode == 65307)
		ft_exit(cube);
	if (keycode == 65362 || keycode == 'w')
		cube->player->forward = 1;
	if (keycode == 'd')
		cube->player->side = 1;
	if (keycode == 'a')
		cube->player->side = -1;
	if (keycode == 65364 || keycode == 's')
		cube->player->forward = -1;
	if (keycode == 65363 || keycode == 'e')
		cube->player->rot = 1;
	if (keycode == 65361 || keycode == 'q')
		cube->player->rot = -1;
	gest_key_press2(keycode, cube);
	return (0);
}

int	gest_key_relase(int keycode, t_cube *cube)
{
	if (keycode == 65362 || keycode == 'w')
		cube->player->forward = 0;
	if (keycode == 'd')
		cube->player->side = 0;
	if (keycode == 'a')
		cube->player->side = 0;
	if (keycode == 65364 || keycode == 's')
		cube->player->forward = 0;
	if (keycode == 65363 || keycode == 'e')
		cube->player->rot = 0;
	if (keycode == 65361 || keycode == 'q')
		cube->player->rot = 0;
	if (keycode == 65505)
		cube->player->movespeed /= 2;
	return (0);
}

int	movement(t_cube *cube)
{
	double	olddirx;
	double	oldplanex;

	olddirx = cube->player->dirx;
	oldplanex = cube->player->planex;
	if (cube->player->forward == 1)
		forward_wall(cube);
	if (cube->player->side == 1)
		side_plus_wall(cube);
	if (cube->player->side == -1)
		side_minus_wall(cube);
	if (cube->player->forward == -1)
		backward_wall(cube);
	if (cube->player->rot == 1)
		rotation_plus(cube, olddirx, oldplanex);
	if (cube->player->rot == -1)
		rotation_minus(cube, olddirx, oldplanex);
	return (0);
}
