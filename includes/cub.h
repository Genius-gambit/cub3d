/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:38:18 by hawadh            #+#    #+#             */
/*   Updated: 2022/07/05 21:48:36 by hawadh           ###   ########.fr       */
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
	int		flag;
	int		y;
	int		x;
}	t_mouse;

typedef struct s_floor
{
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;
}	t_floor;

typedef struct s_ceil
{
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;
}	t_ceil;

typedef struct s_data
{
	char	**file;
	char	**map;
	char	*north_xpm;
	char	*south_xpm;
	char	*east_xpm;
	char	*west_xpm;
	char	**confg;
	t_floor	floor;
	t_ceil	ceil;
}	t_data;

typedef struct s_info
{
	void	*mlx;
	void	*win;
	void	*img;
	t_data	*data;
	t_mouse	*mouse;
	t_img	*image;
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
void	error_print(char *str);
void	err_return(int status);
void	check_map(t_info *info, char *str);
char	**clean_whitespace(char **input);
char	**squash_lines(char **file, char **input);
char	*squash(char *input);
int		store_data(t_data *d, char **input);
int		check_if_map(char *input);
int		isdir(char *str);
int		get_size(char *str);
int		compare_ext(char *str);
int		check_line(char *input);
void	fetch_rgb(char *str, t_info *info, const char *layout);
int		check_rgb(char *str, const char *layout, t_info *info);
int		parse_config(char *str, const char *layout, t_info *info);
int		parse_config_rgb(char *str, const char *layout, t_info *info);
int		parse_map(char **str, int index);
int		parse_arg(char **maps, t_info *info);

/**
**	Window Functions
**/
int		init_window(t_info *info);
int		key_hook_manage(int hook_num, t_info *info);
int		esc_win(t_info *info);

/**
**	Drawing Functions
**/
void	my_pixel_put(t_info *inf, int x, int y, int rgb);
void	draw_cursor(t_info *info);
void	draw_map(t_info *info);
void	ceiling_floor(t_info *info);
void	draw_minimap(t_info *info);
int		call_draw_cursor(void *info);

/**
**	RGB Functions
**/
size_t	rgb(t_data *data, int status);

/**
**	Hook Functions
**/
void	hook_management(t_info *info);

/**
**	Mouse Functions
**/
void	init_cursor(t_info *inf);
int		init_mouse(t_info *info);
int		mouse_move(int x, int y, t_info *info);

#endif
