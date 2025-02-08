#include "include.h"

void	cast_ray5(t_cube *cube)
{
	if (cube->worldmap[cube->ray->mapx]
		&& cube->worldmap[cube->ray->mapx][cube->ray->mapy]
		&& cube->worldmap[cube->ray->mapx][cube->ray->mapy] != '0' &&
		cube->worldmap[cube->ray->mapx][cube->ray->mapy] != 'N' &&
		cube->worldmap[cube->ray->mapx][cube->ray->mapy] != 'S' &&
		cube->worldmap[cube->ray->mapx][cube->ray->mapy] != 'E' &&
		cube->worldmap[cube->ray->mapx][cube->ray->mapy] != 'W' &&
		cube->worldmap[cube->ray->mapx][cube->ray->mapy] != 'O')
		cube->ray->hit = 1;
}
