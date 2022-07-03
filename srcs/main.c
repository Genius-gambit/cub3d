/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:29:29 by hawadh            #+#    #+#             */
/*   Updated: 2022/07/01 01:49:47 by makhtar          ###   ########.fr       */
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
// static int	init(t_info *info)
// {
	// info->mlx = mlx_init();
	// if (!info->mlx)
	// 	return (EXIT_FAILURE);
// 	return (EXIT_SUCCESS);
// }

int	main(int argc, char **argv)
{
	t_info	info;
	t_data	data;

	info.data = &data;
	if (argc == 2)
	{
		check_map(&info, argv[1]);
		// if (init(&info))
		// 	return (EXIT_FAILURE);
	}
	else
		err_return(2);
	// parse_arg(data.file);
	if (parse_arg(data.file))
		return (EXIT_FAILURE);
	// for (int i = 0; data.file[i] != NULL; i++)
	// 	printf("%s\n", data.file[i]);
	// printf("\n");
	free_split(data.file);
	return (EXIT_SUCCESS);
}
