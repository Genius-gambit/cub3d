/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 19:28:36 by hawadh            #+#    #+#             */
/*   Updated: 2022/07/05 21:52:25 by hawadh           ###   ########.fr       */
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
*	TODO:	fix hook_num == 46, keyboard button 'm'
*	TODO:		to be used for releasing mouse on
*	TODO:		fullscreen
**/
int	key_hook_manage(int hook_num, t_info *info)
{
	if (hook_num == 53)
	{
		esc_win(info);
		exit(0);
	}
	// if (hook_num == 46 && info->mouse->flag == 0)
	// {
	// 	mlx_mouse_show();
	// 	info->mouse->flag = 1;
	// }
	// if (hook_num == 46 && info->mouse->flag == 1)
	// 	info->mouse->flag = 0;
	return (EXIT_SUCCESS);
}
