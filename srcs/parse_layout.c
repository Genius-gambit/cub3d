#include "../includes/cub.h"
/*
A function to check for fds.
Return value is 0 if there is no error
Return value is 1 if there is an error
*/
int	error_fds(char *str)
{
	int		fd;
	int		ret;
	char	buf[2];

	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (1);
	ret = read(fd, buf, 1);
	if (ret == -1)
	{
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}

/*
Checking the extension for xpm files
Return value is 0 for getting success
Return value is 1 for getting fail
*/
int	check_xpm_ext(char *str)
{
	char	*tmp;

	tmp = NULL;
	if (*str && ft_strrchr(str, '.'))
	{
		tmp = ft_strrchr(str, '.');
		if (!ft_strcmp(tmp, ".xpm"))
		{
			// if (error_fds(str))
			// 	return (1);
			return (0);
		}
	}
	return (1);
}

/*
Getting the int values in a string so it can execute atoi
*/
char	*dup_num(char *str)
{
	int		count;
	char	*tmp;
	int		i;

	count = 0;
	i = 0;
	while (str[i] && !ft_isspace(str[i]))
	{
		count++;
		i++;
	}
	i = i - count;
	tmp = malloc(sizeof(char) * (count + 1));
	count = 0;
	while (str[i] && !ft_isspace(str[i]))
	{
		tmp[count] = str[i];
		count++;
		i++;
	}
	tmp[count] = 0;
	return (tmp);
}

/*
After checking the color of RGB,
if it is successful, we store the color for floor or ceiling
*/
int	get_rgb(char *tmp, int *k, char *str, int i)
{
	int	ret;

	ret = ft_atoi(tmp);
	free (tmp);
	(*k)++;
	if (ret < 0 || ret > 255)
		return (TRUE);
	if (*k > 3 || (*k == 3 && str[i] == ','))
		return (TRUE);
	return (FALSE);
}

/*
iterating through the index of numbers
*/
void	iterators(char *tmp, int *i)
{
	int	count;

	count = 0;
	while (tmp[count] && ft_isdigit(tmp[count]))
	{
		count++;
		(*i)++;
	}
}

/*
Parse function of RGB colors
*/
int	check_rgb(char *str)
{
	int				i;
	char			*tmp;
	int				k;

	i = 0;
	tmp = NULL;
	k = 0;
	while (str && str[i])
	{
		if (str[i] && ft_isdigit(str[i]))
		{
			tmp = dup_num(&str[i]);
			iterators(tmp, &i);
			if (tmp && tmp[0] && ft_isdigit(tmp[0]) && get_rgb(tmp, &k, str, i))
				return (EXIT_FAILURE);
			while ((str[i] != '\0' && ft_isspace(str[i]))
				|| (str[i] != '\0' && str[i] == ','))
				i++;
		}
		else
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

/*
Getting the string layout
*/
char	*get_layouts(char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[i] && ft_isprint(str[i]) && str[i] != ' ')
		i++;
	if (i == 0)
		return (NULL);
	tmp = malloc(sizeof(char) * (i + 1));
	if (!tmp)
		return (NULL);
	i = 0;
	while (str[i] && ft_isprint(str[i]) && !ft_isspace(str[i]))
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = 0;
	return (tmp);
}

/*
Parsing the layout for north with xpm files
*/
int	parse_north(char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = get_layouts(str);
	if (!tmp)
		return (EXIT_FAILURE);
	while (str[i] && ft_isprint(str[i]) && !ft_isspace(str[i]))
		i++;
	if (!ft_strcmp(tmp, "NO"))
	{
		while (ft_isspace(str[i]))
			i++;
		if (!check_xpm_ext(&str[i]))
		{
			free (tmp);
			return (EXIT_SUCCESS);
		}
	}
	free(tmp);
	return (EXIT_FAILURE);
}

/*
Parsing the layout for south with xpm files
*/
int	parse_south(char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = get_layouts(str);
	if (!tmp)
		return (EXIT_FAILURE);
	while (str[i] && ft_isprint(str[i]) && !ft_isspace(str[i]))
		i++;
	if (!ft_strcmp(tmp, "SO"))
	{
		while (ft_isspace(str[i]))
			i++;
		if (!check_xpm_ext(&str[i]))
		{
			free (tmp);
			return (EXIT_SUCCESS);
		}
	}
	free(tmp);
	return (EXIT_FAILURE);
}

/*
Parsing the layout for west with xpm files
*/
int	parse_west(char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = get_layouts(str);
	if (!tmp)
		return (EXIT_FAILURE);
	while (str[i] && ft_isprint(str[i]) && !ft_isspace(str[i]))
		i++;
	if (!ft_strcmp(tmp, "WE"))
	{
		while (ft_isspace(str[i]))
			i++;
		if (!check_xpm_ext(&str[i]))
		{
			free (tmp);
			return (EXIT_SUCCESS);
		}
	}
	free(tmp);
	return (EXIT_FAILURE);
}

/*
Parsing the layout for east with xpm files
*/
int	parse_east(char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = get_layouts(str);
	if (!tmp)
		return (1);
	while (str[i] && ft_isprint(str[i]) && !ft_isspace(str[i]))
		i++;
	tmp[i] = 0;
	if (!strcmp(tmp, "EA"))
	{
		while (ft_isspace(str[i]))
			i++;
		if (!check_xpm_ext(&str[i]))
		{
			free (tmp);
			return (EXIT_SUCCESS);
		}
	}
	free(tmp);
	return (EXIT_FAILURE);
}

/*
Parsing the layout for floor with xpm files
*/
int	parse_floor(char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = get_layouts(str);
	if (!tmp)
		return (EXIT_FAILURE);
	while (str[i] && ft_isprint(str[i]) && !ft_isspace(str[i]))
		i++;
	if (!ft_strcmp(tmp, "F"))
	{
		while (str[i] && ft_isspace(str[i]))
			i++;
		if (str && !check_rgb(&str[i]))
		{
			free(tmp);
			return (EXIT_SUCCESS);
		}
	}
	free(tmp);
	return (EXIT_FAILURE);
}

/*
Parsing the layout for ceiling with xpm files
*/
int	parse_ceil(char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = get_layouts(str);
	if (!tmp)
		return (EXIT_FAILURE);
	while (str[i] && ft_isprint(str[i]) && !ft_isspace(str[i]))
		i++;
	if (!ft_strcmp(tmp, "C"))
	{
		while (str[i] && ft_isspace(str[i]))
			i++;
		if (str && !check_rgb(&str[i]))
		{
			free(tmp);
			return (EXIT_SUCCESS);
		}
	}
	free(tmp);
	return (EXIT_FAILURE);
}

/*
With the order, parsing all layouts
*/
int	parse_layout(char **line, int *index)
{
	int	i;

	i = 0;
	if (line[i] != NULL && parse_north(line[i++]))
		return (EXIT_FAILURE);
	if (line[i] != NULL && parse_south(line[i++]))
		return (EXIT_FAILURE);
	if (line[i] != NULL && parse_west(line[i++]))
		return (EXIT_FAILURE);
	if (line[i] != NULL && parse_east(line[i++]))
		return (EXIT_FAILURE);
	if (line[i] != NULL && parse_floor(line[i++]))
		return (EXIT_FAILURE);
	if (line[i] != NULL && parse_ceil(line[i++]))
		return (EXIT_FAILURE);
	*index = i;
	return (EXIT_SUCCESS);
}

/*
Getting valid keys for the map
*/
int	valid_key(int c)
{
	if (c == '0')
		return ('0');
	else if (c == '1')
		return ('1');
	else if (c == 'N')
		return ('N');
	else if (c == 'W')
		return ('W');
	else if (c == 'S')
		return ('S');
	else if (c == 'E')
		return ('E');
	return (FALSE);
}

/*
Parsing for walls to check for top and bottom of the map
*/
int	parse_walls(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (valid_key(str[i]) == '1' || ft_isspace(str[i]))
			i++;
		else
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

/*
In map we need an indictaion for setting the layout and getting
the starting position of the player, We need only one part of
the layout, if there is more then we're throwing an error.
*/
int	key_layout(int c)
{
	if (valid_key(c) == 'W')
		return (1);
	else if (valid_key(c) == 'E')
		return (1);
	else if (valid_key(c) == 'S')
		return (1);
	else if (valid_key(c) == 'N')
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/*
Parsing the middle part of the map and taking everything into the
account
Valid Keys:
0: Free space
1: Walls
W: West Navigator
N: North Navigator 
S: South Navigator
E: East Navigator
*/
int	parse_env(char *str)
{
	static int	trigger;
	int			i;

	i = 0;
	while (str[i])
	{
		if (key_layout(str[i]))
		{
			if (trigger)
				return (EXIT_FAILURE);
			trigger = 1;
		}
		else if (!valid_key(str[i]) && !ft_isspace(str[i]))
			return (EXIT_FAILURE);
		i++;
	}
	if ((str[i - 2] == '1' && str[i - 1] == 10)
		|| str[i - 1] == '1')
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

/*
The root function of parsing of the map
*/
int	parse_map(char **str, int index)
{
	int	i;

	i = index;
	if (parse_walls(str[i++]))
		return (EXIT_FAILURE);
	while (str[i + 1] != NULL)
	{
		if (parse_env(str[i]))
			return (EXIT_FAILURE);
		i++;
	}
	if (parse_walls(str[i]))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	parse_arg(char **maps)
{
	int	index;

	index = 0;
	if (parse_layout(maps, &index))
	{
		ft_putendl_fd("Invalid Layout", 2);
		return(EXIT_FAILURE);
	}
	if (parse_map(maps, index))
	{
		ft_putendl_fd("Invalid Floor or Ceiling", 2);
		return(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
