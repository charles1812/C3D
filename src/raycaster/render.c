/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspreafi <cspreafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 22:50:19 by cspreafi          #+#    #+#             */
/*   Updated: 2025/02/27 00:57:20 by cspreafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	get_size(t_cube *cube)
{
	if (map_len(cube->worldmap) - cube->start_map < 16)
		return (16);
	else if (map_len(cube->worldmap) - cube->start_map > 16
		&& map_len(cube->worldmap) - cube->start_map <= 32)
		return (12);
	else if (map_len(cube->worldmap) - cube->start_map > 32
		&& map_len(cube->worldmap) - cube->start_map <= 64)
		return (10);
	else if (map_len(cube->worldmap) - cube->start_map > 32)
		return (8);
	return (12);
}

void	draw_cube(t_cube *cube, int x, int y, int color)
{
	int	x1;
	int	countx;
	int	y1;
	int	county;

	county = 0;
	y1 = y * cube->size_map / 2;
	while (county < cube->size_map / 3)
	{
		x1 = x * cube->size_map / 2;
		countx = 0;
		while (countx < cube->size_map / 3)
		{
			dont_draw_line(cube, y1, x1, color);
			x1++;
			countx++;
		}
		county++;
		y1++;
	}
}

int	draw_loop(t_cube *cube)
{
	int	x;

	x = 0;
	cube->img = mlx_new_image(cube->mlx, SCREENWIDTH, SCREENHEIGHT);
	cube->data_addr = mlx_get_data_addr(cube->img,
			&cube->bits_per_pixel, &cube->size_line, &cube->endian);
	movement(cube);
	draw_background(cube, -1);
	cube->ray = malloc(sizeof(t_raycast) * 1);
	while (x < SCREENWIDTH)
	{
		cast_ray(cube, x);
		x++;
	}
	free(cube->ray);
	mlx_put_image_to_window(cube->mlx, cube->win, cube->img, 0, 0);
	mlx_destroy_image(cube->mlx, cube->img);
	return (0);
}
