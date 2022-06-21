/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:29:29 by hawadh            #+#    #+#             */
/*   Updated: 2022/06/21 17:03:10 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/**
*	Duplicating the map in a string in 
*	If fd is an error, exits the program
*	typedef struct which can help us in the program,
*	when we update the scenario
*	If the file is empty, exits the program
**/
static void	init(char *str, t_info *info)
{
	int		fd;
	char	*map;

	fd = 0;
	map = NULL;
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		error_print("ERROR: File Descriptor");
		exit (1);
	}
	map = ft_reading(fd);
	if (!map)
	{
		close (fd);
		error_print("ERROR: Empty File");
		exit (1);
	}
	info->map = ft_strdup(map);
	free(map);
	printf("Completed reading\n");
	close (fd);
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc == 2)
	{
		if (!check_map(argv[1]))
		{
			init(argv[1], &info);
			free(info.map);
			return (0);
		}
		return (1);
	}
	else
		error_print("Error in arguments");
	return (0);
}