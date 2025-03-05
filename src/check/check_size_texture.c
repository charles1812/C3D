/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_size_texture.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgerbaul <jgerbaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 23:16:37 by jgerbaul          #+#    #+#             */
/*   Updated: 2025/02/25 00:17:18 by jgerbaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	check_height_texture(t_cube *cube)
{
	if (cube->texture->height != 64 || cube->texture1->height != 64
		|| cube->texture3->height != 64 || cube->texture2->height != 64)
	{
		printf("Error texture height should be 64px\n");
		return (ERROR);
	}
	return (VALID);
}

int	check_length_texture(t_cube *cube)
{
	if (cube->texture->width != 64 || cube->texture1->width != 64
		|| cube->texture3->width != 64 || cube->texture2->width != 64)
	{
		printf("Error texture lenght should be 64px\n");
		return (ERROR);
	}
	return (VALID);
}

void	check_texture_while(bool *tx, bool *tx1, t_cube *cube, int div)
{
	if (cube->texture->width % div == 0)
		(*tx) = true;
	if (cube->texture1->width % div == 0)
		(*tx1) = true;
}

int	check_texture_size(t_cube *cube)
{
	if (check_height_texture(cube) != VALID)
		return (ERROR);
	if (check_length_texture(cube) != VALID)
		return (ERROR);
	return (VALID);
}
