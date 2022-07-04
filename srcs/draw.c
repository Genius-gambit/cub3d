/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 09:28:29 by hawadh            #+#    #+#             */
/*   Updated: 2022/07/04 21:09:49 by hawadh           ###   ########.fr       */
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
