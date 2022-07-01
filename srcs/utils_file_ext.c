/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_file_ext.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@Student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:18:58 by hawadh            #+#    #+#             */
/*   Updated: 2022/07/01 10:01:19 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/**
**	Checks if line only contains spaces
**/
int	check_line(char *input)
{
	char	*temp;

	temp = input;
	while (*temp)
	{
		if (!ft_isspace(*temp))
			return (FALSE);
		temp++;
	}
	return (TRUE);
}

/**
**	Removes excess whitespace ' '
*	check_if_map();		If not first line of map
*						keep squashing
**/
char	**squash_lines(char **file, char **input)
{
	size_t	i;

	i = 0;
	while (input[i])
	{
		if (!check_if_map(input[i]))
			file[i] = squash(input[i]);
		else
			file[i] = ft_strdup(input[i]);
		i++;
	}
	return (file);
}
