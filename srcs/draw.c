/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@Student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 09:28:29 by hawadh            #+#    #+#             */
/*   Updated: 2022/07/03 23:12:36 by hawadh           ###   ########.fr       */
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

int	draw_cursor(void *info)
{
	t_info	*inf;

	inf = (t_info *)info;
	mlx_mouse_get_pos(inf->win, inf->mouse->m_x, inf->mouse->m_x);
	my_pixel_put(info, *inf->mouse->m_x, *inf->mouse->m_y, 0x00FFFFFF);
	return (EXIT_SUCCESS);
}
