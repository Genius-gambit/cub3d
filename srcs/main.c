/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:29:29 by hawadh            #+#    #+#             */
/*   Updated: 2022/06/22 15:02:32 by makhtar          ###   ########.fr       */
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

	fd = open(str, O_RDONLY);
	if (fd == -1)
		err_return(0);
	printf("here\n");
	if (ft_reading(info, str, fd))
		err_return(1);
	printf("Completed reading\n");
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
		err_return(2);
	return (0);
}
