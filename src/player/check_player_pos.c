/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player_pos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspreafi <cspreafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 22:30:32 by jgerbaul          #+#    #+#             */
/*   Updated: 2025/03/23 05:31:53 by cspreafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	check_ns(char c, t_cube *cube)
{
	cube->player->dirx = -1;
	cube->player->diry = 0;
	cube->player->planex = 0.0;
	cube->player->planey = 1;
	if (c == 'S')
	{
		cube->player->dirx *= -1;
		cube->player->planey *= -1;
	}
}

void	check_we(char c, t_cube *cube)
{
	cube->player->dirx = 0;
	cube->player->diry = 1;
	cube->player->planex = 1;
	cube->player->planey = -0.0;
	if (c == 'W')
	{
		cube->player->diry *= -1;
		cube->player->planex = -1;
	}
}

int	check_direction_player(char c, t_cube *cube)
{
	if (c == 'N' || c == 'S')
		check_ns(c, cube);
	else if (c == 'E' || c == 'W')
		check_we(c, cube);
	else
		return (ERROR);
	return (VALID);
}
