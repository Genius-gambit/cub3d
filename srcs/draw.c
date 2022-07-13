/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 09:28:29 by hawadh            #+#    #+#             */
/*   Updated: 2022/07/13 21:19:38 by hawadh           ###   ########.fr       */
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
	int	xpm_y;
	int	xpm_x;

	y = 200;
	xpm_y = 0;
	while (xpm_y < xpm->hi)
	{
		x = 640;
		xpm_x = 0;
		while (xpm_x < xpm->wi)
		{
			info->image->addr[(x * 4) + 4 * (WIDTH * y)]
				= xpm->addr[(xpm_x * 4) + 4 * (xpm->wi * xpm_y)];
			xpm_x++;
			x++;
		}
		xpm_y++;
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
