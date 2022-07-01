/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@Student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:29:29 by hawadh            #+#    #+#             */
/*   Updated: 2022/07/01 09:59:59 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/**
**	Init's MLX and other variables
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
	/**
	 *	REMEMBER DELETE
	 **/
	for (int i = 0; data.file[i] != NULL; i++)
		printf("%s\n", data.file[i]);
	printf("\n");
	/**
	 *	REMEMBER DELETE
	 **/
	free_split(data.file);
	return (EXIT_SUCCESS);
}
