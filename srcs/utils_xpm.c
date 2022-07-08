/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_xpm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 20:06:18 by hawadh            #+#    #+#             */
/*   Updated: 2022/07/08 20:43:05 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/**
**	Opens xpm layout images and stores them within
*	data->confg		NO, SO, WE, EA
*	data->pause		Fixed image ./imgs/pause.xpm
**/
int	open_xpm(t_info *inf, t_data *d, size_t len)
{
	size_t	i;
	int		x;
	int		y;

	i = 0;
	while (i < len)
	{
		if (i == 0)
			d->confg[i] = mlx_xpm_file_to_image(inf->mlx, d->north_xpm, &x, &y);
		if (i == 1)
			d->confg[i] = mlx_xpm_file_to_image(inf->mlx, d->south_xpm, &x, &y);
		if (i == 2)
			d->confg[i] = mlx_xpm_file_to_image(inf->mlx, d->west_xpm, &x, &y);
		if (i == 3)
			d->confg[i] = mlx_xpm_file_to_image(inf->mlx, d->east_xpm, &x, &y);
		if (i > 3)
			d->confg[i] = ft_strdup(d->file[i]);
		if (!d->confg[i])
			return (EXIT_FAILURE);
		i++;
	}
	d->pause = mlx_xpm_file_to_image(inf->mlx, "./imgs/pause.xpm", &x, &y);
	if (!d->pause)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
