/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_layout.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:19:03 by makhtar           #+#    #+#             */
/*   Updated: 2022/07/07 18:08:25 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/**
**	Counts number of lines of config
**/
static size_t	confg_count(char **file)
{
	size_t	count;

	count = 0;
	while (file[count] && !check_if_map(file[count]))
		count++;
	return (count);
}

/**
**	Stores config of file in data->confg
*	Confg is first line before map
*	Which includes N, S, E, W and C, F
**/
static int	store_confg_map(t_data *data)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = -1;
	j = 0;
	len = confg_count(data->file);
	data->confg = (char **)ft_calloc(len + 1, sizeof(char *));
	data->map = (char **)ft_calloc((ft_ptrptrlen(data->file)
				- len) + 1, sizeof(char *));
	if (!data->confg || !data->map)
		return (EXIT_FAILURE);
	while (data->file[i] && ++i < len)
		data->confg[i] = ft_strdup(data->file[i]);
	while (data->file[i])
		data->map[j++] = ft_strdup(data->file[i++]);
	return (EXIT_SUCCESS);
}

/**
**	With the order, parsing all layouts
**/
static int	parse_layout(char **line, int *index, t_info *info)
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
	if (store_confg_map(info->data))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
