/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@Student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 09:28:29 by hawadh            #+#    #+#             */
/*   Updated: 2022/07/03 14:27:47 by hawadh           ###   ########.fr       */
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

void	draw_cursor(t_info *info)
{
	t_mouse	*mouse;
	int		i;

	i = 0;
	mouse = (t_mouse *)ft_calloc(1, sizeof(t_mouse));
	mouse->m_x = (int *)ft_calloc(1, sizeof(int));
	mouse->m_y = (int *)ft_calloc(1, sizeof(int));
	info->mouse = mouse;
	mlx_mouse_get_pos(info->win, info->mouse->m_x, info->mouse->m_x);
	my_pixel_put(info, *info->mouse->m_x, *info->mouse->m_y, 0x00FFFFFF);
}
