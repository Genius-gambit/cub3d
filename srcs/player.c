/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:49:05 by hawadh            #+#    #+#             */
/*   Updated: 2022/07/21 19:33:44 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/**
**	To find player pos on X coords
**/
static int	find_player_index(char *map)
{
	int	x_pos;

	x_pos = 0;
	while (map[x_pos])
	{
		if (map[x_pos] == 'N')
			return (x_pos);
		if (map[x_pos] == 'S')
			return (x_pos);
		if (map[x_pos] == 'W')
			return (x_pos);
		if (map[x_pos] == 'E')
			return (x_pos);
		x_pos++;
	}
	return (0);
}

/**
**	To find player pos on Y coords
**/
static int	find_player_array(char **map)
{
	int	y_pos;

	y_pos = 0;
	while (map[y_pos])
	{
		if (ft_strchr(map[y_pos], 'N'))
			return (y_pos);
		if (ft_strchr(map[y_pos], 'S'))
			return (y_pos);
		if (ft_strchr(map[y_pos], 'W'))
			return (y_pos);
		if (ft_strchr(map[y_pos], 'E'))
			return (y_pos);
		y_pos++;
	}
	return (0);
}

/**
**	Function to find Player Position in Array
*	Not Static so it can be called in draw_map();
*	for finding new position of player
**/
void	find_player(t_data *d, t_player *p)
{
	p->y_pos = find_player_array(d->map);
	p->x_pos = find_player_index(d->map[p->y_pos]);
	p->view = d->map[p->y_pos][p->x_pos];
}

/**
**	To draw Walls and Player in Minimap
**/
void	init_player(t_info *inf)
{
	if (!inf->player)
	{
		inf->player = (t_player *)ft_calloc(1, sizeof(t_player));
		if (!inf->player)
			err_return(7, inf);
	}
	find_player(inf->data, inf->player);
	printf("\nPlayer Pos:\nY:	%d\nX:	%d\nView:	%c\n", inf->player->y_pos, \
	inf->player->x_pos, inf->player->view);
}
