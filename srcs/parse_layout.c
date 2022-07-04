/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_layout.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:19:03 by makhtar           #+#    #+#             */
/*   Updated: 2022/07/04 21:18:23 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/**
**	With the order, parsing all layouts
**/
int	parse_layout(char **line, int *index)
{
	int	i;

	i = 0;
	if (line[i] != NULL && parse_config(line[i++], "NO"))
		return (EXIT_FAILURE);
	if (line[i] != NULL && parse_config(line[i++], "SO"))
		return (EXIT_FAILURE);
	if (line[i] != NULL && parse_config(line[i++], "WE"))
		return (EXIT_FAILURE);
	if (line[i] != NULL && parse_config(line[i++], "EA"))
		return (EXIT_FAILURE);
	if (line[i] != NULL && parse_config_rgb(line[i++], "F"))
		return (EXIT_FAILURE);
	if (line[i] != NULL && parse_config_rgb(line[i++], "C"))
		return (EXIT_FAILURE);
	*index = i;
	return (EXIT_SUCCESS);
}

/**
**	Calls parser for maps and config
**/
int	parse_arg(char **maps)
{
	int	index;

	index = 0;
	if (parse_layout(maps, &index))
	{
		ft_putendl_fd("Invalid Layout", 2);
		return (EXIT_FAILURE);
	}
	if (parse_map(maps, index))
	{
		ft_putendl_fd("Invalid Floor or Ceiling", 2);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
