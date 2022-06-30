/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_file_ext.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:18:58 by hawadh            #+#    #+#             */
/*   Updated: 2022/06/30 16:39:57 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

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
