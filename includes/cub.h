/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:38:18 by hawadh            #+#    #+#             */
/*   Updated: 2022/06/22 20:05:35 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H
# define TRUE 1
# define FALSE 0

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <sys/stat.h>
# include "../libft/libft.h"
# include "../minilibx_opengl/mlx.h"
# include "../get_next_line/get_next_line.h"

typedef struct s_data
{
	char	**file;
}	t_data;

typedef struct s_info
{
	void	*mlx;
	char	**map;
	char	**confg;
	t_data	*data;
}	t_info;

/**
**	Memory Management
**/
void	free_split(char **str);

/**
**	Parsing Functions
**/
void	error_print(char *str);
void	err_return(int status);
void	check_map(t_info *info, char *str);
int		get_size(char *str);
int		clean_file(t_info *inf, char **temp);

#endif
