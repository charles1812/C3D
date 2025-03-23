/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tex_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspreafi <cspreafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 22:50:42 by cspreafi          #+#    #+#             */
/*   Updated: 2025/03/23 04:36:54 by cspreafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	get_color_west(t_cube *cube, int y, int texx)
{
	int	d;
	int	texy;
	int	color;

	d = y * 256 - SCREENHEIGHT * 128 + cube->ray->lineheight * 128;
	texy = ((d * cube->texture->height) / cube->ray->lineheight) / 256;
	if (texx >= 0 && texx < 256 && texy >= 0 && texy < 64)
		color = cube->texture->data[cube->texture->width * texy + texx];
	return (color);
}

int	get_color_north(t_cube *cube, int y, int texx)
{
	int	d;
	int	texy;
	int	color;

	d = y * 256 - SCREENHEIGHT * 128 + cube->ray->lineheight * 128;
	texy = ((d * cube->texture1->height) / cube->ray->lineheight) / 256;
	if (texx >= 0 && texx < 256 && texy >= 0 && texy < 64)
		color = cube->texture1->data[cube->texture1->width * texy + texx];
	return (color);
}

int	get_color_east(t_cube *cube, int y, int texx)
{
	int	d;
	int	texy;
	int	color;

	d = y * 256 - SCREENHEIGHT * 128 + cube->ray->lineheight * 128;
	texy = ((d * cube->texture2->height) / cube->ray->lineheight) / 256;
	if (texx >= 0 && texx < 256 && texy >= 0 && texy < 64)
		color = cube->texture2->data[cube->texture2->width * texy + texx];
	return (color);
}

int	get_color_south(t_cube *cube, int y, int texx)
{
	int	d;
	int	texy;
	int	color;

	d = y * 256 - SCREENHEIGHT * 128 + cube->ray->lineheight * 128;
	texy = ((d * cube->texture3->height) / cube->ray->lineheight) / 256;
	if (texx >= 0 && texy >= 0 && texy < 64)
		color = cube->texture3->data[cube->texture3->width * texy + texx];
	return (color);
}
