/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:29:29 by hawadh            #+#    #+#             */
/*   Updated: 2022/06/22 17:07:34 by hawadh           ###   ########.fr       */
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
static int	init(t_info *info)
{
	info->mlx = mlx_init();
	if (!info->mlx)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_info	info;
	t_data	data;

	info.data = &data;
	if (argc == 2)
	{
		check_map(&info, argv[1]);
		if (init(&info))
			return (EXIT_FAILURE);
	}
	else
		err_return(2);
	return (EXIT_SUCCESS);
}
