/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspreafi <cspreafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 22:50:26 by cspreafi          #+#    #+#             */
/*   Updated: 2025/02/18 02:36:10 by cspreafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	check_ray_collision_with_wall(t_cube *cube)
{
	if (cube->worldmap[cube->ray->mapx]
		&& cube->worldmap[cube->ray->mapx][cube->ray->mapy]
		&& cube->worldmap[cube->ray->mapx][cube->ray->mapy] != '0' &&
		cube->worldmap[cube->ray->mapx][cube->ray->mapy] != 'N' &&
		cube->worldmap[cube->ray->mapx][cube->ray->mapy] != 'S' &&
		cube->worldmap[cube->ray->mapx][cube->ray->mapy] != 'E' &&
		cube->worldmap[cube->ray->mapx][cube->ray->mapy] != 'W')
		cube->ray->hit = 1;
}
