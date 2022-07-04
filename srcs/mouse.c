/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 23:05:19 by hawadh            #+#    #+#             */
/*   Updated: 2022/07/04 21:11:02 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/**
**	Inits and draws crosshair
**/
void	init_cursor(t_info *inf)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 960;
	y = 540;
	while (i < 30)
	{
		my_pixel_put(inf, x + i, y, 0x00FFFFFF);
		i++;
	}
	i = 0;
	while (i < 30)
	{
		my_pixel_put(inf, x, y + i, 0x00FFFFFF);
		i++;
	}
}

/**
**	Mouse event trigger manager
**/
int	mouse_move(int x, int y, t_info *info)
{
	mlx_mouse_get_pos(info->win, &x, &y);
	if (x >= 0 && x <= 1920 && y >= 0 && y <= 1080)
	{
		init_cursor(info);
		mlx_mouse_move(info->win, x, 540);
		mlx_mouse_hide();
	}
	else
		mlx_mouse_show();
	return (EXIT_SUCCESS);
}

/**
**	Initialises Mouse cursor on start
**/
int	init_mouse(t_info *info)
{
	if (!info->mouse)
		info->mouse = (t_mouse *)ft_calloc(1, sizeof(t_mouse));
	if (!info->mouse)
	{
		free_data(info);
		err_return(4);
	}
	init_cursor(info);
	mlx_mouse_hide();
	return (EXIT_SUCCESS);
}
