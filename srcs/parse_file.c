/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:24:58 by hawadh            #+#    #+#             */
/*   Updated: 2022/07/04 14:48:51 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static char	**extract_file(char *str, int size)
{
	char	*temp;
	char	**out;
	int		i;
	int		fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		err_return(0);
	out = (char **)ft_calloc(size + 1, sizeof(char *));
	temp = (char *)ft_calloc(1, sizeof(char));
	if (!temp || !out)
		return (NULL);
	i = 0;
	while (temp)
	{
		free(temp);
		temp = get_next_line(fd);
		if (temp)
			out[i++] = ft_strdup(temp);
	}
	free(temp);
	close(fd);
	return (out);
}

/**
**	Cleans file contents from excess whitespaces by calling squash
*	count	 < 7	stores data
*	count	== 7	stop squash to avoid map
**/
static int	clean_file(t_info *inf, char **input)
{
	char	**tmp;
	char	**file;

	tmp = clean_whitespace(input);
	if (!tmp)
		return (EXIT_FAILURE);
	file = (char **)ft_calloc(ft_ptrptrlen(tmp) + 1, sizeof(char *));
	if (!file)
		return (EXIT_FAILURE);
	file = squash_lines(file, tmp);
	if (tmp)
		free_split(tmp);
	if (store_data(inf->data, file))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/**
*	A function to read everything given the file
*	descriptor and returns a line of char
**/
static int	ft_reading(t_info *info, char *str)
{
	int		size;
	char	**temp;

	size = get_size(str);
	if (size <= 0)
		err_return(1);
	temp = extract_file(str, size);
	if (!temp)
		return (EXIT_FAILURE);
	if (clean_file(info, temp))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/**
*	Confirmation that the extension of the map is cub type
**/
void	check_map(t_info *info, char *str)
{
	if (isdir(str) && ft_strchr(str, '.'))
	{
		if (compare_ext(str))
			err_return(3);
	}
	else
		err_return(3);
	if (ft_reading(info, str))
		err_return(1);
	printf("Completed reading\n");
}
