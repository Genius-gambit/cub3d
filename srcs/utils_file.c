/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:09:10 by hawadh            #+#    #+#             */
/*   Updated: 2022/06/22 18:41:40 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static int	count_str_size(char *input)
{
	int		i;
	size_t	count;

	i = 0;
	count = 0;
	while (input[i])
	{
		while (input[i + 1] && ft_isspace(input[i]) && ft_isspace(input[i + 1]))
			i++;
		if (input[i] && ft_isspace(input[i]) && input[i] != ' ')
			i++;
		count++;
		if (input[i])
			i++;
	}
	return (count);
}

static char	*squash(char *input)
{
	char	*temp;
	size_t	len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len = count_str_size(input);
	temp = (char *)ft_calloc(len + 1, sizeof(char));
	if (!temp)
		return (NULL);
	while (input[i])
	{
		if (input[i + 1])
			while (ft_isspace(input[i]) && ft_isspace(input[i + 1]))
				i++;
		if (input[i] && ft_isspace(input[i]) && input[i] != ' ')
			i++;
		temp[j++] = input[i++];
	}
	temp[j] = 0;
	free(input);
	return (temp);
}

int	clean_file(t_info *inf, char **temp)
{
	int		i;

	i = 0;
	while (temp[i])
	{
		inf->data->file[i] = squash(temp[i]);
		if (!inf->data->file[i])
			return (EXIT_FAILURE);
		i++;
	}
	if (temp)
		free(temp);
	return (EXIT_SUCCESS);

}
