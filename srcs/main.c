/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:29:29 by hawadh            #+#    #+#             */
/*   Updated: 2022/07/04 14:47:42 by makhtar          ###   ########.fr       */
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
	if (init_window(info))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_info	info;
	t_data	data;

	ft_memset(&info, 0, sizeof(t_info));
	ft_memset(&data, 0, sizeof(t_data));
	info.data = &data;
	if (argc == 2)
	{
		check_map(&info, argv[1]);
		if (init(&info))
			return (EXIT_FAILURE);
	}
	else
		err_return(2);
	if (parse_arg(data.file))
		return (EXIT_FAILURE);
	free_split(data.file);
	return (EXIT_SUCCESS);
}
