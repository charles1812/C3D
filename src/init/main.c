/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgerbaul <jgerbaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 22:30:21 by jgerbaul          #+#    #+#             */
/*   Updated: 2025/03/22 00:34:57 by jgerbaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	init_map2(t_cube *cube)
{
	if (check_symbols(cube) != 0)
		return (7);
	if (check_textures(cube) != 0)
		return (8);
	if (check_color(cube) != 0)
		return (9);
	return (VALID);
}

int	init_map(char *s, t_cube *cube)
{
	int	fd;
	int	ret;

	fd = open(s, O_RDONLY);
	if (check_ext(s, (int)ft_strlen(s)) != 0)
	{
		error_initmap_free(cube, 10);
		return (2);
	}
	if (fd == -1)
		return (3);
	cube->worldmap = make_map(fd);
	close(fd);
	if (!cube->worldmap)
		return (4);
	cube->start_map = get_start_map(cube);
	if (get_player_pos(cube) != 0)
		return (5);
	if (checkmap(cube) != 0)
		return (6);
	ret = init_map2(cube);
	if (ret != VALID)
		return (ret);
	return (VALID);
}

int	init_game(t_cube *cube)
{
	cube->player->forward = 0;
	cube->player->side = 0;
	cube->player->rot = 0;
	cube->player->movespeed = 0.0075;
	cube->player->rotspeed = 0.01;
	cube->mlx = mlx_init();
	if (!cube->mlx)
		return (ERROR);
	if (load_xpm_texture(cube->we_tex_name, cube) == NULL
		|| load_xpm_texture1(cube->no_tex_name, cube) == NULL
		|| load_xpm_texture2(cube->ea_tex_name, cube) == NULL
		|| load_xpm_texture3(cube->so_tex_name, cube) == NULL)
		error_tex_free(cube);
	if (check_texture_size(cube) != VALID)
		ft_exit_windowless(cube);
	cube->win = mlx_new_window(cube->mlx, SCREENWIDTH,
			SCREENHEIGHT, "cub3D");
	if (!cube->win)
		return (ERROR);
	cube->loaded = 1;
	cube->size_map = get_size(cube);
	cube->half_screen = SCREENHEIGHT / 2;
	return (VALID);
}

int	main(int ac, char **av)
{
	t_cube	*cube;
	int		ret;

	cube = gc_alloc(sizeof(t_cube), 6);
	cube->player = gc_alloc(sizeof(t_player), 2);
	cube->loaded = 0;
	if (ac != 2)
		return (error_arg());
	ret = init_map(av[1], cube);
	if (ret != 0)
	{
		printf("Error init ");
		error_initmap_free(cube, ret);
	}
	if (init_game(cube) != VALID)
		ft_exit(cube);
	draw_loop(cube);
	mlx_loop_hook(cube->mlx, draw_loop, cube);
	mlx_hook(cube->win, 17, 1L << 17, ft_exit, cube);
	mlx_hook(cube->win, 3, 1L << 1, gest_key_relase, cube);
	mlx_hook(cube->win, 2, 1L << 0, gest_key_press, cube);
	mlx_loop(cube->mlx);
	return (0);
}
