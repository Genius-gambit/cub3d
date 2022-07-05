/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_layout.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:19:03 by makhtar           #+#    #+#             */
/*   Updated: 2022/07/05 16:56:34 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/**
**	With the order, parsing all layouts
**/
int	parse_layout(char **line, int *index, t_info *info)
{
	int	i;

	i = 0;
	if (line[i] != NULL && parse_config(line[i++], "NO", info))
		return (EXIT_FAILURE);
	if (line[i] != NULL && parse_config(line[i++], "SO", info))
		return (EXIT_FAILURE);
	if (line[i] != NULL && parse_config(line[i++], "WE", info))
		return (EXIT_FAILURE);
	if (line[i] != NULL && parse_config(line[i++], "EA", info))
		return (EXIT_FAILURE);
	if (line[i] != NULL && parse_config_rgb(line[i++], "F", info))
		return (EXIT_FAILURE);
	if (line[i] != NULL && parse_config_rgb(line[i++], "C", info))
		return (EXIT_FAILURE);
	*index = i;
	return (EXIT_SUCCESS);
}

/**
**	Calls parser for maps and config
**/
int	parse_arg(char **maps, t_info *info)
{
	int	index;

	index = 0;
	if (parse_layout(maps, &index, info))
	{
		ft_putendl_fd("Invalid Layout", 2);
		return (EXIT_FAILURE);
	}
	if (parse_map(maps, index))
	{
		ft_putendl_fd("Invalid Floor or Ceiling", 2);
		return (EXIT_FAILURE);
	}
	printf("Floor: Red: %d, Green: %d, Blue: %d\n", \
	info->data->floor.red, info->data->floor.green, info->data->floor.blue);
	printf("Ceil: Red: %d, Green: %d, Blue: %d\n", info->data->ceil.red, \
	info->data->ceil.green, info->data->ceil.blue);
	return (EXIT_SUCCESS);
}

/*
** Printing info for the layout and the colours for floor and ceilings
**	printf("North Path: %s\n", info->data->north_xpm);
**	printf("South Path: %s\n", info->data->south_xpm);
**	printf("East Path: %s\n", info->data->east_xpm);
**	printf("West Path: %s\n", info->data->west_xpm);
*/
/*
*/