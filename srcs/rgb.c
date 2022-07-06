/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:29:28 by hawadh            #+#    #+#             */
/*   Updated: 2022/07/05 18:18:36 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/**
**	Calculates colour based on status
*	status == 0;	ceiling colour
*	status == 1;	floor colour
**/
size_t	rgb(t_data *data, int status)
{
	size_t	rgb;

	rgb = 0x00FFFFFF;
	if (status == 0)
	{
		rgb = (data->ceil.red + 1) * (data->ceil.green + 1)
			* (data->ceil.blue + 1);
	}
	if (status == 1)
	{
		rgb = (data->floor.red + 1) * (data->floor.green + 1)
			* (data->floor.blue + 1);
	}
	return (rgb);
}
