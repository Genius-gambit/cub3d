/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 19:43:20 by hawadh            #+#    #+#             */
/*   Updated: 2022/07/14 22:54:02 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/**
**	Custom Pixel Put for Minimap
**/
void	mini_pixel_put(t_mini *mini, int x, int y, int rgb)
{
	char	*draw;

	draw = mini->addr + (y * mini->len + x * (mini->bitspix / 8));
	*(unsigned int *)draw = rgb;
}

// static void	draw_mini_walls(t_mini *mini, int x, int y)
// {
// 	int	x_one;
// 	int	y_one;

// 	y_one = y * 5;
// 	while (y < y_one)
// 	{
// 		if (x == 0)
// 			x = 1;
// 		x_one = x * 5;
// 		while (x < x_one)
// 		{
// 			if (y < 182 && y > 3 && x < 257 && x > 3)
// 				mini_pixel_put(mini, x, y, 0x00F0F0F0);
// 			x++;
// 		}
// 		y++;
// 	}
// }

/**
**	Draws minimap interior
*	TODO:	Draw miniature version of file map
**/
static void	mini_interior(t_info *info, t_mini *mini)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	y = 0;
	(void)mini;
	while (info->data->map[i])
	{
		j = 0;
		x = 0;
		while (info->data->map[i][j])
		{
			// if (info->data->map[i][j] == '1')
			// 	draw_mini_walls(mini, x++, y);
			j++;
		}
		i++;
		y++;
	}
}

/**
**	Draws closer borders and calls function to draw
**	Outer borders. Calls to draw minimap interior
**/
void	draw_minimap(t_info *info, t_mini *mini)
{
	int	x;
	int	y;

	(void)info;
	y = 3;
	while (y < 182)
	{
		x = 3;
		while (x < 257)
			mini_pixel_put(mini, x++, y, 0x00606060);
		y++;
	}
	mini_interior(info, mini);
}

/**
**	Initialises struct mini and creates new image for
**	mini-map
**/
void	init_minimap(t_info *info)
{
	t_mini	*mini;

	mini = (t_mini *)ft_calloc(1, sizeof(t_mini));
	info->mini = mini;
	info->mini_map = mlx_new_image(info->mlx, 260, 185);
	if (!info->mini_map)
	{
		free_data(info);
		err_return(4, info);
	}
	mini->addr = mlx_get_data_addr(info->mini_map, &mini->bitspix,
			&mini->len, &mini->end);
	if (!mini->addr)
		err_return(4, info);
}
