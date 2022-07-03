/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@Student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:38:18 by hawadh            #+#    #+#             */
/*   Updated: 2022/07/03 10:07:44 by hawadh           ###   ########.fr       */
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

typedef struct s_image
{
	char	*addr;
	int		bitspix;
	int		len;
	int		end;
}	t_img;

typedef struct s_mouse
{
	int		*m_y;
	int		*m_x;
}	t_mouse;

typedef struct s_data
{
	char	**file;
	char	**map;
	char	**confg;
}	t_data;

typedef struct s_info
{
	void	*mlx;
	void	*win;
	void	*img;
	t_data	*data;
	t_mouse	*mouse;
	t_img	*imag;
}	t_info;

/**
**	Memory Management
**/
void	free_split(char **str);
void	free_data(t_info *info);

/**
**	Parsing Functions
**/
size_t	get_act_size(char **input);
char	**clean_whitespace(char **input);
char	**squash_lines(char **file, char **input);
char	*squash(char *input);
void	error_print(char *str);
void	err_return(int status);
void	check_map(t_info *info, char *str);
int		store_data(t_data *d, char **input);
int		check_if_map(char *input);
int		isdir(char *str);
int		get_size(char *str);
int		compare_ext(char *str);
int		check_line(char *input);

/**
**	Window Functions
**/
int		init_window(t_info *info);
int		key_hook_manage(int hook_num, t_info *info);
int		esc_win(t_info *info);

/**
**	Drawing Functions
**/
void	draw_cursor(t_info *info);
void	my_pixel_put(t_info *inf, int x, int y, int rgb);

#endif
