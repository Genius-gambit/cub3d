/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 09:28:29 by hawadh            #+#    #+#             */
/*   Updated: 2022/07/13 19:28:46 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/**
**	Custom pixel put
**/
void	my_pixel_put(t_info *inf, int x, int y, int rgb)
{
	char	*draw;

	draw = inf->image->addr
		+ (y * inf->image->len + x * (inf->image->bitspix / 8));
	*(unsigned int *)draw = rgb;
}

static void	add_xpm(t_info *info, t_xpm *xpm)
{
	int	y;
	int	x;
	int	limit_x;
	int	limit_y;

	x = 540;
	y = 200;
	limit_x = x + xpm->wi;
	limit_y = y + xpm->hi;
	while (y < limit_y)
	{
		x = 640;
		while (x < limit_x)
		{
			info->image->addr[x + 4 * (WIDTH * y)]
				= xpm->addr[x + 4 * (64 * y)];
			x++;
		}
		y++;
	}
}

/**
**	Calls xpm struct based on player orientation at start
**/
static void	place_xpm(t_info *info, t_data *data)
{
	if (info->player->view == 'N')
		add_xpm(info, &data->xpm[NO]);
	if (info->player->view == 'S')
		add_xpm(info, &data->xpm[SO]);
	if (info->player->view == 'W')
		add_xpm(info, &data->xpm[WE]);
	if (info->player->view == 'E')
		add_xpm(info, &data->xpm[EA]);
}

/**
**	Draws everything include map
*	init_cursor(); to reinitialise crosshair
*	after each redraw
**/
void	draw_map(t_info *info)
{
	ceiling_floor(info);
	place_xpm(info, info->data);
	draw_minimap(info, info->mini);
	init_cursor(info);
}
