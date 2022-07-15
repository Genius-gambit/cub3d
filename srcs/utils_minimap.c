/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_minimap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 19:44:52 by hawadh            #+#    #+#             */
/*   Updated: 2022/07/15 19:51:11 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/**
**	Draws walls on minimap
**/
static void	draw_mini_walls(t_mini *mini, int x, int y, int rgb)
{
	int	y_one;
	int	x_one;
	int	x_reset;

	y_one = y + MINI_SCALE;
	while (y < y_one)
	{
		x_one = x + MINI_SCALE;
		x_reset = x;
		while (x_reset < x_one)
		{
			while (x_reset > 85 && x_reset < 100 && y > 85 && y < 100)
				x_reset++;
			mini_pixel_put(mini, x_reset, y, rgb);
			x_reset++;
		}
		y++;
	}
}

/**
**	Draws Player at centre of minimap 
**/
static void	draw_mini_player(t_mini *mini, int x, int y, int rgb)
{
	int	x_reset;

	while (y < 101)
	{
		x_reset = x;
		while (x_reset < 101)
		{
			if (y == 85 || y == 100)
				mini_pixel_put(mini, x_reset, y, 0x000E5227);
			else if (x_reset == 85 || x_reset == 100)
				mini_pixel_put(mini, x_reset, y, 0x000E5227);
			else
				mini_pixel_put(mini, x_reset, y, rgb);
			x_reset++;
		}
		y++;
	}
}

/**
*!	TEMP FUNCTION 
**/
static void	draw_square(t_mini *mini, int x, int y, int rgb)
{
	int	x_reset;

	while (y < 108)
	{
		x_reset = x;
		while (x_reset < 108)
		{
			if (y == 78 || y == 107)
				mini_pixel_put(mini, x_reset, y, rgb);
			else if (x_reset == 78 || x_reset == 107)
				mini_pixel_put(mini, x_reset, y, rgb);
			x_reset++;
		}
		y++;
	}
}

/**
**	Draws minimap interior
*	TODO:	Draw miniature version of file map
**/
void	mini_interior(t_info *info, t_mini *mini)
{
	int	y;
	int	x;
	int	i;
	int	j;

	draw_mini_player(mini, 85, 85, 0x003D8758);
	draw_square(mini, 78, 78, 0x00FFFFFF);
	i = info->player->y_pos;
	y = 108;
	while (info->data->map[i])
	{
		j = info->player->x_pos;
		x = 108;
		while (info->data->map[i][j])
		{
			j--;
			x -= MINI_SCALE;
		}
		i++;
		y -= MINI_SCALE;
	}
	i = 0;
	while (info->data->map[i])
	{
		j = 0;
		while (info->data->map[i][j])
		{
			if (x > 3 && x < 182 && y > 3 && y < 182)
				if (info->data->map[i][j] == '1')
					draw_mini_walls(mini, x, y, 0x00000000);
			x += MINI_SCALE;
			j++;
		}
		y += MINI_SCALE;
		i++;
	}
}
