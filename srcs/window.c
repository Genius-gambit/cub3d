/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 11:48:10 by hawadh            #+#    #+#             */
/*   Updated: 2022/07/04 14:53:34 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static void	get_img_addr(t_info *inf)
{
	t_img	*imag;

	imag = (t_img *)ft_calloc(1, sizeof(t_img));
	inf->imag = imag;
	inf->img = mlx_new_image(inf->mlx, 1920, 1080);
	if (!inf->img)
	{
		free_data(inf);
		err_return(4);
	}
	imag->addr = mlx_get_data_addr(inf->img, &imag->bitspix,
			&imag->len, &imag->end);
}

int	init_window(t_info *info)
{
	info->win = mlx_new_window(info->mlx, 1920, 1080, "Cub3d");
	if (!info->win)
		return (EXIT_FAILURE);
	get_img_addr(info);
	init_mouse(info);
	hook_management(info);
	mlx_put_image_to_window(info->mlx, info->win, info->img, 0, 0);
	mlx_loop(info->mlx);
	return (EXIT_SUCCESS);
}
