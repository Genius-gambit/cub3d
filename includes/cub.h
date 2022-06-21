/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:38:18 by hawadh            #+#    #+#             */
/*   Updated: 2022/06/21 22:50:07 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <sys/stat.h>
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"

typedef struct s_data
{
	char	**file;
}	t_data;

typedef struct s_info
{
	char	*map;
	t_data	*data;
}	t_info;

/**
**	Parsing Functions
**/
void	error_print(char *str);
void	err_return(int status);
int		ft_reading(t_info *info, char *str, int fd);
int		check_map(char *str);
int		get_size(int fd);

#endif
