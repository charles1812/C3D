/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspreafi <cspreafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 22:50:36 by cspreafi          #+#    #+#             */
/*   Updated: 2025/02/13 22:50:37 by cspreafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	get_color_side_zero(t_cube *cube, int y, int texx) // NO SO
{
	int	color;

	if (cube->ray->side == 0 && cube->ray->raydirx > 0)
		color = get_color_south(cube, y, texx);
	else if (cube->ray->side == 0 && cube->ray->raydirx < 0)
		color = get_color_north(cube, y, texx);
	return (color);
}

int	get_color_side_one(t_cube *cube, int y, int texx)
{
	int	color;

	if (cube->ray->side == 1 && cube->ray->raydiry > 0)
		color = get_color_east(cube, y, texx);
	else if (cube->ray->side == 1 && cube->ray->raydiry < 0)
		color = get_color_west(cube, y, texx);
	return (color);
}

void	get_color_texture(t_cube *cube, int y, int texx, int x)
{
	int	color;

	while (y < cube->ray->drawend)
	{
		if (cube->worldmap[cube->ray->mapx][cube->ray->mapy] == '1')
		{
			if (cube->ray->side == 0)
				color = get_color_side_zero(cube, y, texx);
			else if (cube->ray->side == 1)
				color = get_color_side_one(cube, y, texx);
		}
		draw(cube, x, y, color);
		y++;
	}
}
