/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 19:28:36 by hawadh            #+#    #+#             */
/*   Updated: 2022/07/15 15:52:51 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/**
**	To manage red (x) to close window
**/
int	esc_win(t_info *info)
{
	free_data(info);
	exit(0);
	return (EXIT_SUCCESS);
}

/**
**	Handles pause button
**/
static void	handle_pause(t_info *inf)
{
	if (inf->mouse->flag == 0)
	{
		mlx_put_image_to_window(inf->mlx, inf->win, \
		inf->data->pause, 550, 250);
		mlx_mouse_show();
		inf->mouse->flag = 1;
	}
	else if (inf->mouse->flag == 1)
	{
		inf->mouse->flag = 0;
		mlx_clear_window(inf->mlx, inf->win);
		draw_map(inf);
		mlx_put_image_to_window(inf->mlx, inf->win, inf->img, 0, 0);
		mlx_put_image_to_window(inf->mlx, inf->win, inf->data->gun, 840, 520);
		mlx_put_image_to_window(inf->mlx, inf->win, inf->mini_map, 30, 30);
	}
}

/**
**	To manage key hooks (presses)
*	hook_num == 53			ESC
*	hook_num == 35			'p' (release mouse)
*	mouse->flag == 0;		Hide and reposition mouse
*	mouse->flag == 1;		Show and release mouse
**/
int	key_hook_manage(int hook_num, t_info *inf)
{
	if (hook_num == 53)
	{
		esc_win(inf);
		exit(0);
	}
	if (hook_num == 35)
		handle_pause(inf);
	return (EXIT_SUCCESS);
}
