/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:24:58 by hawadh            #+#    #+#             */
/*   Updated: 2022/06/22 19:23:01 by hawadh           ###   ########.fr       */
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
	temp = ft_memset((char *)ft_calloc(1, sizeof(char)), 0, 1);
	if (!temp || !out)
		return (NULL);
	i = 0;
	while (temp)
	{
		free(temp);
		temp = get_next_line(fd);
		if (temp)
			out[i] = ft_strdup(temp);
		i++;
	}
	if (temp)
		free(temp);
	close(fd);
	return (out);
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

static int	compare_ext(char *str)
{
	char	*tmp;

	tmp = str;
	tmp = ft_strrchr(str, '.');
	if (*tmp && !strcmp(tmp, ".cub"))
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

/**
*	To check if the given map is a directory
**/
static int	isdir(char *str)
{
	int		fd;
	int		ret;
	char	buf[1];

	fd = open(str, O_RDONLY);
	ret = read(fd, buf, 1);
	if (ret == -1)
		return (FALSE);
	close(fd);
	return (TRUE);
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
