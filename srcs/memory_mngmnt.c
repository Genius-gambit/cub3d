/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_mngmnt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@Student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 20:02:35 by hawadh            #+#    #+#             */
/*   Updated: 2022/07/03 14:17:30 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static void	free_struct_mouse(t_mouse *mouse)
{
	if (mouse->m_x)
		free(mouse->m_x);
	if (mouse->m_y)
		free(mouse->m_y);
	if (mouse)
		free(mouse);
}

static void	free_struct_imag(t_img *imag)
{
	if (imag->addr)
		free(imag->addr);
	if (imag)
		free(imag);
}

static void	free_struct_data(t_data *data)
{
	if (data->map)
		free_split(data->map);
	if (data->confg)
		free_split(data->confg);
	if (data->file)
		free_split(data->file);
}

/**
**	Frees all the Data
**/
void	free_data(t_info *info)
{
	if (info->win)
		mlx_destroy_window(info->mlx, info->win);
	if (info->mlx)
		free(info->mlx);
	free_struct_data(info->data);
	free_struct_imag(info->imag);
	free_struct_mouse(info->mouse);
}

/**
**	Frees 2D arrays
**/
void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		if (str[i])
			free(str[i++]);
	if (str)
		free(str);
}
