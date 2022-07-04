/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 09:28:29 by hawadh            #+#    #+#             */
/*   Updated: 2022/07/04 14:36:31 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	my_pixel_put(t_info *inf, int x, int y, int rgb)
{
	char	*draw;

	draw = inf->imag->addr
		+ (y * inf->imag->len + x * (inf->imag->bitspix / 8));
	*(unsigned int *)draw = rgb;
}

static void	draw_cursor(t_info *info)
{
	int	i;

	i = 0;
	mlx_mouse_get_pos(info->win, info->mouse->m_x, info->mouse->m_x);
	mlx_mouse_move(info->win, *info->mouse->m_x, *info->mouse->m_y);
	if (info->mouse->m_x && info->mouse->m_y)
	{
		while (i < 40)
		{
			my_pixel_put(info, *info->mouse->m_x + i,
				*info->mouse->m_y + i, 0x00FFFFFF);
			i++;
		}
	}
}

int	mouse_data(void *info)
{
	draw_cursor(info);
	return (EXIT_SUCCESS);
}
