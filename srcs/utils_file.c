/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:09:10 by hawadh            #+#    #+#             */
/*   Updated: 2022/06/22 20:19:08 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static size_t	get_act_size(char **input)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (input[i])
	{
		if (ft_strncmp(input[i], "", ft_strlen(input[i])))
			count++;
		i++;
	}
	return (count);
}

static int	store_data(t_data *d, char **input)
{
	int	i;
	int	j;

	d->file = (char **)ft_calloc(get_act_size(input) + 1, sizeof(char *));
	if (!d->file)
		return (EXIT_FAILURE);
	i = 0;
	j = 0;
	while (input[i])
	{
		if (ft_strncmp(input[i], "", ft_strlen(input[i])))
			d->file[j++] = ft_strdup(input[i]);
		i++;
	}
	free_split(input);
	return (EXIT_SUCCESS);
}

/**
**	Returns Actual size of string without excess whitespaces
**/
static int	count_str_size(char *input)
{
	char	*temp;
	size_t	count;

	count = 0;
	temp = input;
	while (*temp)
	{
		if (temp == input)
			while (*temp && ft_isspace(*temp))
				temp++;
		while (*temp && ft_isspace(*temp) && ft_isspace(*(temp + 1)))
			temp++;
		if (*temp && ft_isspace(*temp) && *temp != ' ')
			temp++;
		if (*temp)
		{
			count++;
			temp++;
		}
	}
	return (count);
}

/**
**	Squashes lines by removing any excess whitespaces
**/
static char	*squash(char *input)
{
	char	*out;
	char	*temp;
	size_t	len;
	int		i;

	i = 0;
	temp = input;
	len = count_str_size(input);
	out = (char *)ft_calloc(len + 1, sizeof(char));
	if (!temp)
		return (NULL);
	while (*temp)
	{
		if (temp == input)
			while (*temp && ft_isspace(*temp))
				temp++;
		while (*temp && ft_isspace(*temp) && ft_isspace(*(temp + 1)))
			temp++;
		if (*temp && ft_isspace(*temp) && *temp != ' ')
			temp++;
		if (*temp)
			out[i++] = *temp++;
	}
	return (out);
}

/**
**	Cleans file contents from excess whitespaces by calling squash
*	count	 < 7	stores data
*	count	== 7	stop squash to avoid map
**/
int	clean_file(t_info *inf, char **input)
{
	char	**tmp;
	int		count;
	int		i;

	i = 0;
	count = 0;
	tmp = (char **)ft_calloc(ft_ptrptrlen(input) + 1, sizeof(char *));
	if (!tmp)
		return (EXIT_FAILURE);
	while (input[i] && count < 7)
	{
		tmp[i] = squash(input[i]);
		if (!tmp[i])
			return (EXIT_FAILURE);
		if (ft_strncmp(tmp[i], "", ft_strlen(tmp[i])))
			count++;
		i++;
	}
	if (input)
		free_split(input);
	if (store_data(inf->data, tmp))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);

}
