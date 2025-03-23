/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgerbaul <jgerbaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 22:50:46 by cspreafi          #+#    #+#             */
/*   Updated: 2025/03/19 18:36:24 by jgerbaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	draw_background(t_cube *cube, int y)
{
	int	x;
	int	pixel;
	int	bpp;
	int	color;
	int	line_offset;

	bpp = cube->bits_per_pixel / 8;
	while (++y < SCREENHEIGHT)
	{
		line_offset = y * cube->size_line;
		if (y < cube->half_screen)
			color = cube->color_c;
		else
			color = cube->color_f;
		x = -1;
		while (++x < SCREENWIDTH)
		{
			pixel = line_offset + (x * bpp);
			*(int *)(cube->data_addr + pixel) = color;
		}
	}
}

void	draw(t_cube *cube, int x, int y, int color)
{
	int	pixel;

	if (y < SCREENHEIGHT && x < SCREENWIDTH)
	{
		pixel = (y * cube->size_line) + (x * (cube->bits_per_pixel / 8));
		*(int *)(cube->data_addr + pixel) = color;
	}
}
