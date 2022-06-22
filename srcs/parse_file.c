/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:24:58 by hawadh            #+#    #+#             */
/*   Updated: 2022/06/22 15:03:18 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/**
*	To check if the given map is a directory
*!	We're not allowed to use stat function
*!	We can simply check if first call to get_next_line();
*!	return is null
**/
static int	isdir(const char *file_name)
{
	struct stat	path;
	

	ft_memset(&path, 0, sizeof(struct stat));
	stat(file_name, &path);
	return (S_ISREG(path.st_mode));
}

/**
*	Confirmation that the extension of the map is cub type
**/
int	check_map(char *str)
{
	char	*tmp;
	char	*string;

	if (isdir(str) && ft_strchr(str, '.'))
	{
		string = ft_strdup(ft_strchr(str, '.'));
		tmp = string;
		++tmp;
		if (!strcmp(tmp, "cub"))
		{
			free(string);
			return (0);
		}
		else
			err_return(3);
		free(string);
	}
	else
		err_return(3);
	return (1);
}

static void	extract_data(t_data *data, int fd)
{
	int	i;

	i = 0;
	while (data->file[i])
	{
		data->file[i] = get_next_line(fd);
		i++;
	}
}

/**
*	A function to read everything given the file
*	descriptor and returns a line of char
**/
int	ft_reading(t_info *info, char *str, int fd)
{
	int		size;

	size = get_size(fd);
	printf("trial\n");
	if (size <= 0)
		err_return(1);
	fd = open(str, O_RDONLY);
	if (fd == -1)
		err_return(0);
	info->data->file = (char **)ft_calloc(size + 1, sizeof(char *));
	if (!info->data->file)
		return (EXIT_FAILURE);
	extract_data(info->data, fd);
	close (fd);
	return (EXIT_SUCCESS);
}
