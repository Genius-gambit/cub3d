#include "../includes/cub.h"

/*To check if the given map is a directory*/
int	isdir(const char *fileName)
{
	struct stat	path;

	memset(&path, 0, sizeof(struct stat));
	stat(fileName, &path);
	return (S_ISREG(path.st_mode));
}

void	error_print(char *str)
{
	write(2, "\033[1;91m", strlen("\033[1;91m"));
	write(2, str, strlen(str));
	write(2, "\n\033[0m", strlen("\n\033[0m"));
}

/*Confirmation that the extension of the map is cub type*/
int	check_map(char *str)
{
	char	*tmp;
	char	*string;

	tmp = NULL;
	string = NULL;
	if (isdir(str) && strchr(str, '.'))
	{
		string = strdup(strchr(str, '.'));
		tmp = string;
		++tmp;
		if (!strcmp(tmp, "cub"))
		{
			free(string);
			return (0);
		}
		else
			error_print("Map not valid");
		free(string);
	}
	else
		error_print("Map not valid");
	return (1);
}

/*A function to read everything given the file
descriptor and returns a line of char* */
char	*ft_reading(int fd)
{
	char	*tmp;
	char	buffer[2];
	char	*line;
	char	*old;

	line = NULL;
	while (read (fd, buffer, 1) == 1)
	{
		buffer[1] = 0;
		tmp = buffer;
		if (!line)
			line = ft_strdup(tmp);
		else
		{
			old = ft_strdup(line);
			free (line);
			line = ft_strjoin(old, tmp);
			free (old);
		}
	}
	return (line);
}


void	init(char *str, t_info *info)
{
	int	fd;
	char	*map;

	fd = 0;
	map = NULL;
	fd = open(str, O_RDONLY);
	/*If fd is an error, exits the program*/
	if (fd == -1)
	{
		error_print("ERROR: File Descriptor");
		exit (1);
	}
	map = ft_reading(fd);
	/*If the file is empty, exits the program*/
	if (!map)
	{
		close (fd);
		error_print("ERROR: Empty File");
		exit (1);
	}
	/* Duplicating the map in a string in 
	typedef struct which can help us in the program,
	when we update the scenario*/
	info->map = ft_strdup(map);
	free(map);
	printf("Completed reading\n");
	close (fd);
}

int main(int argc, char **argv)
{
	t_info	info;
	if (argc == 2)
	{
		if (!check_map(argv[1]))
		{
			init(argv[1], &info);
			free(info.map);
			return (0);
		}
		return (1);
	}
	else
		error_print("Error in arguments");
	return (0);
}