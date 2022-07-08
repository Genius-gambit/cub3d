/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 11:48:10 by hawadh            #+#    #+#             */
/*   Updated: 2022/07/08 19:21:26 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/**
**	Inits data->config and calls open_xpm();
**	to open and store xpm images
*	TODO:	Load all xpm images through this function
**/
static int	init_xpm(t_info *info, t_data *data)
{
	size_t	len;

	len = confg_count(data->file);
	if (!data->confg)
		data->confg = (char **)ft_calloc(len + 1, sizeof(char *));
	if (!data->confg)
		return (EXIT_FAILURE);
	if (open_xpm(info, data, len))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/**
**	Calls image data address to draw into img
**/
static void	get_img_addr(t_info *inf)
{
	t_img	*image;

	image = (t_img *)ft_calloc(1, sizeof(t_img));
	inf->image = image;
	inf->img = mlx_new_image(inf->mlx, 1920, 1080);
	if (!inf->image)
	{
		free_data(inf);
		err_return(4, inf);
	}
	image->addr = mlx_get_data_addr(inf->img, &image->bitspix,
			&image->len, &image->end);
	if (!image->addr)
		err_return(4, inf);
}

/**
**	Initialises window, get's img address and hook management
**	mlx_loop();	here
**/
int	init_window(t_info *info)
{
	info->win = mlx_new_window(info->mlx, 1920, 1080, "Cub3d");
	if (!info->win)
		return (EXIT_FAILURE);
	get_img_addr(info);
	init_mouse(info);
	init_minimap(info);
	if (init_xpm(info, info->data))
		err_return(5, info);
	hook_management(info);
	draw_map(info);
	mlx_put_image_to_window(info->mlx, info->win, info->img, 0, 0);
	mlx_put_image_to_window(info->mlx, info->win, info->mini_map, 20, 20);
	mlx_loop(info->mlx);
	return (EXIT_SUCCESS);
}
