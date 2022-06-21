/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:24:58 by hawadh            #+#    #+#             */
/*   Updated: 2022/06/21 17:02:58 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/**
*	To check if the given map is a directory
**/
int	isdir(const char *fileName)
{
	struct stat	path;

	memset(&path, 0, sizeof(struct stat));
	stat(fileName, &path);
	return (S_ISREG(path.st_mode));
}

/**
*	Confirmation that the extension of the map is cub type
**/
int	check_map(char *str)
{
	char	*tmp;
	char	*string;

	tmp = NULL;
	string = NULL;
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
			error_print("Map not valid");
		free(string);
	}
	else
		error_print("Map not valid");
	return (1);
}

/**
*	A function to read everything given the file
*	descriptor and returns a line of char
**/
char	*ft_reading(int fd)
{
	char	*tmp;
	char	buffer[2];
	char	*line;
	char	*old;

	line = NULL;
	while (read (fd, buffer, 1) == 1)
	{
		buffer[1] = 0;
		tmp = buffer;
		if (!line)
			line = ft_strdup(tmp);
		else
		{
			old = ft_strdup(line);
			free (line);
			line = ft_strjoin(old, tmp);
			free (old);
		}
	}
	return (line);
}
