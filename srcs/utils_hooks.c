/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 19:28:36 by hawadh            #+#    #+#             */
/*   Updated: 2022/07/07 18:07:35 by hawadh           ###   ########.fr       */
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
**	To manage key hooks (presses)
*	hook_num == 53			ESC
*	hook_num == 46			'm' (release mouse)
*	mouse->flag == 0;		Hide and reposition mouse
*	mouse->flag == 1;		Show and release mouse
**/
int	key_hook_manage(int hook_num, t_info *info)
{
	if (hook_num == 53)
	{
		esc_win(info);
		exit(0);
	}
	if (hook_num == 46)
	{
		if (info->mouse->flag == 0)
		{
			mlx_put_image_to_window(info->mlx, info->win, \
			info->data->pause, 700, 300);
			mlx_mouse_show();
			info->mouse->flag = 1;
		}
		else if (info->mouse->flag == 1)
			info->mouse->flag = 0;
	}
	return (EXIT_SUCCESS);
}
