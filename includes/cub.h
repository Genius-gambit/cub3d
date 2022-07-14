/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:38:18 by hawadh            #+#    #+#             */
/*   Updated: 2022/07/14 21:11:03 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H
# define TRUE 1
# define FALSE 0
# define WIDTH 1920
# define HEIGHT 1080

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <sys/stat.h>
# include "../libft/libft.h"
# include "../minilibx_opengl/mlx.h"
# include "../get_next_line/get_next_line.h"

/**
**	ENUM for Compass perspective of Player
*	NO	0	NORTH
*	SO	1	SOUTH
*	WE	2	WEST
*	EA	3	EAST
**/
typedef enum e_compass
{
	NO,
	SO,
	WE,
	EA,
}	t_pers;

/**
**	Player Structure
*	view	Orientation, N,S,W,E
*	y_pos	Position on Y
*	x_pos	Position on X
**/
typedef struct s_player
{
	char	view;
	int		y_pos;
	int		x_pos;
}	t_player;

typedef struct s_xpm
{
	void	*img;
	char	*addr;
	int		bitspix;
	int		len;
	int		end;
	int		wi;
	int		hi;
	int		divisible;
}	t_xpm;

/**
**	Minimap image address
**/
typedef struct s_minimap
{
	char	*addr;
	int		bitspix;
	int		len;
	int		end;
}	t_mini;

/**
**	Main window image address
**/
typedef struct s_image
{
	char	*addr;
	int		bitspix;
	int		len;
	int		end;
}	t_img;

/**
**	Mouse Data
**/
typedef struct s_mouse
{
	int		flag;
	int		y;
	int		x;
}	t_mouse;

/**
**	Floor RGB
**/
typedef struct s_floor
{
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;
}	t_floor;

/**
**	Ceiling RGB
**/
typedef struct s_ceil
{
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;
}	t_ceil;

/**
**	File Map layout and data
*	file		file contents
*	map			map contents
*	confg		Below config during mlx_xpm_file_to_image();
*	pause		Pause image
*	floor		RGB of floor
*	ceiling		RGB of ceiling
**/
typedef struct s_data
{
	char	**file;
	char	**map;
	char	**confg;
	char	*pause;
	t_xpm	*xpm;
	t_floor	floor;
	t_ceil	ceil;
}	t_data;

/**
**	Main Struct with all info including struct Pointers
*	minilibx	*mlx
*	window		*window
*	image		*img		
*	data		struct
*	mouse		struct
*	minimap		struct
**/
typedef struct s_info
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*mini_map;
	t_data		*data;
	t_mouse		*mouse;
	t_img		*image;
	t_mini		*mini;
	t_player	*player;
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
size_t	confg_count(char **file);
void	error_print(char *str);
void	err_return(int status, t_info *info);
void	check_map(t_info *info, char *str);
void	fetch_rgb(char *str, t_info *info, const char *layout);
char	**clean_whitespace(char **input);
char	**squash_lines(char **file, char **input);
char	*squash(char *input);
int		store_data(t_data *d, char **input);
int		check_if_map(char *input);
int		isdir(char *str);
int		get_size(t_info *info, char *str);
int		compare_ext(char *str);
int		check_line(char *input);
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
void	draw_minimap(t_info *info, t_mini *mini);

/**
**	player struct functions
**/

void	init_player(t_info *info);

/**
**	Mini-map functions
**/
void	init_minimap(t_info *info);
void	mini_pixel_put(t_mini *mini, int x, int y, int rgb);

/**
**	XPM Functions 
**/
int		init_xpm(t_info *info, t_data *data);

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
