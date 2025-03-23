/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgerbaul <jgerbaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 00:13:42 by jgerbaul          #+#    #+#             */
/*   Updated: 2025/03/21 23:35:32 by jgerbaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	ft_exit_windowless(t_cube *cube)
{
	gc_free_p(7);
	mlx_destroy_image(cube->mlx, cube->texture->img);
	mlx_destroy_image(cube->mlx, cube->texture1->img);
	mlx_destroy_image(cube->mlx, cube->texture2->img);
	mlx_destroy_image(cube->mlx, cube->texture3->img);
	gc_free_p(4);
	mlx_destroy_display(cube->mlx);
	gc_free_p(2);
	free(cube->mlx);
	gc_free_p(6);
	gc_free_p(3);
	exit(0);
}

int	ft_exit(t_cube *cube)
{
	if (cube->loaded == 1)
		gc_free_p(7);
	if (cube->win)
	{
		mlx_destroy_image(cube->mlx, cube->texture->img);
		mlx_destroy_image(cube->mlx, cube->texture1->img);
		mlx_destroy_image(cube->mlx, cube->texture2->img);
		mlx_destroy_image(cube->mlx, cube->texture3->img);
	}
	gc_free_p(4);
	if (cube->win)
	{
		mlx_destroy_window(cube->mlx, cube->win);
		mlx_destroy_display(cube->mlx);
	}
	gc_free_p(2);
	free(cube->mlx);
	gc_free_p(6);
	gc_free_p(3);
	gc_free_all();
	exit(0);
}

void	error_initmap_free(t_cube *cube, int ret)
{
	gc_free_p(7);
	gc_free_p(4);
	gc_free_p(2);
	free(cube->mlx);
	gc_free_p(6);
	gc_free_p(3);
	if (ret == 2)
		printf("map isn't filled\n");
	if (ret == 3)
		printf("can't open file\n");
	if (ret == 4)
		printf("unable to allocate the map\n");
	if (ret == 5)
		printf("init player error\n");
	if (ret == 6)
		printf("error found in the map\n");
	if (ret == 7)
		printf("extra char found\n");
	if (ret == 8)
		printf("texture error\n");
	if (ret == 9)
		printf("failed to obtain color\n");
	exit(1);
}

int	error_arg(void)
{
	printf("./cub3D *.cub\n");
	return (1);
}

void	error_tex_free(t_cube *cube)
{
	gc_free_p(7);
	gc_free_p(4);
	mlx_destroy_display(cube->mlx);
	gc_free_p(2);
	free(cube->mlx);
	gc_free_p(6);
	gc_free_p(3);
	exit(1);
}
