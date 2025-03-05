#include "include.h"

int	check_closed_door(t_cube *cube)
{
	if (cube->worldmap[(int)cube->player->posx][(int)cube->player->posy] == 'D')
		cube->worldmap[(int)cube->player->posx][(int)cube->player->posy] = 'O';
	else if (cube->worldmap[(int)cube->player->posx]
		[(int)cube->player->posy + 1] == 'D')
		cube->worldmap[(int)cube->player->posx]
		[(int)cube->player->posy + 1] = 'O';
	else if (cube->worldmap[(int)cube->player->posx]
		[(int)cube->player->posy - 1] == 'D')
		cube->worldmap[(int)cube->player->posx]
		[(int)cube->player->posy - 1] = 'O';
	else if (cube->worldmap[(int)cube->player->posx + 1]
		[(int)cube->player->posy] == 'D')
		cube->worldmap[(int)cube->player->posx + 1]
		[(int)cube->player->posy] = 'O';
	else if (cube->worldmap[(int)cube->player->posx - 1]
		[(int)cube->player->posy] == 'D')
		cube->worldmap[(int)cube->player->posx - 1]
		[(int)cube->player->posy] = 'O';
	else
		return (0);
	return (1);
}

int	check_open_door(t_cube *cube)
{
	if (cube->worldmap[(int)cube->player->posx]
		[(int)cube->player->posy] == 'O')
		cube->worldmap[(int)cube->player->posx]
		[(int)cube->player->posy] = 'D';
	else if (cube->worldmap[(int)cube->player->posx]
		[(int)cube->player->posy + 1] == 'O')
		cube->worldmap[(int)cube->player->posx]
		[(int)cube->player->posy + 1] = 'D';
	else if (cube->worldmap[(int)cube->player->posx]
		[(int)cube->player->posy - 1] == 'O')
		cube->worldmap[(int)cube->player->posx]
		[(int)cube->player->posy - 1] = 'D';
	else if (cube->worldmap[(int)cube->player->posx + 1]
		[(int)cube->player->posy] == 'O')
		cube->worldmap[(int)cube->player->posx + 1]
		[(int)cube->player->posy] = 'D';
	else if (cube->worldmap[(int)cube->player->posx - 1]
		[(int)cube->player->posy] == 'O')
		cube->worldmap[(int)cube->player->posx - 1]
		[(int)cube->player->posy] = 'D';
	else
		return (0);
	return (1);
}

void	check_door_around(t_cube *cube)
{
	if (check_closed_door(cube) != 0)
		return ;
	else if (check_open_door(cube) != 0)
		return ;
}
