/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 19:43:20 by hawadh            #+#    #+#             */
/*   Updated: 2022/07/05 19:47:41 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/**
**	Draws minimap interior
*	TODO:	Draw miniature version of file map
**/
static void	mini_interior(t_info *info)
{
	int	x;
	int	y;

	y = 21;
	while (y < 180)
	{
		x = 21;
		while (x < 255)
			my_pixel_put(info, x++, y, 0x00606060);
		y++;
	}
}

/**
**	Draws far borders of minimap
*	Status 0	draws far y border
*	Status 1	draws far x border
**/
static void	mini_bottom_top(t_info *info, int status)
{
	int	x;
	int	y;

	if (status == 0)
	{
		x = 255;
		y = 20;
		while (y < 180)
			my_pixel_put(info, x, y++, 0x000000);
	}
	if (status == 1)
	{
		x = 20;
		y = 180;
		while (x < 255)
			my_pixel_put(info, x++, y, 0x000000);
	}
}

/**
**	Draws closer borders and calls function to draw
**	Outer borders. Calls to draw minimap interior
**/
void	draw_minimap(t_info *info)
{
	int	x;
	int	y;

	x = 20;
	y = 20;
	while (y < 180)
	{
		x = 20;
		if (y > 20)
			my_pixel_put(info, x, y, 0x00000000);
		if (y == 20)
			while (x < 255)
				my_pixel_put(info, x++, y, 0x00000000);
		if (y != 20)
			my_pixel_put(info, x, y, 0x000000);
		y++;
	}
	mini_bottom_top(info, 0);
	mini_bottom_top(info, 1);
	mini_interior(info);
}
