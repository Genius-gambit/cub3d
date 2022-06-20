#include "../includes/cub.h"

int	isdir(const char *fileName)
{
	struct stat	path;
	// int			ret;

	memset(&path, 0, sizeof(struct stat));
	stat(fileName, &path);
	// ret = S_ISREG(path.st_mode);
	// printf("%d\n", ret);
	return (S_ISREG(path.st_mode));
}

void	error_print(char *str)
{
	write(2, "\033[1;91m", strlen("\033[1;91m"));
	write(2, str, strlen(str));
	write(2, "\n\033[0m", strlen("\n\033[0m"));
}

int	check_map(char *str)
{
	char	*tmp;
	char	*string;

	tmp = NULL;
	// printf("%s\n", str);
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
	{
		// printf("trace\n");
		error_print("Map not valid");
	}
	return (1);
}

void	init(char *str)
{
	int	fd;
	char	*tmp;
	char	buffer[2];
	char	*line;
	char	*old;

	fd = 0;
	// tmp = 0;
	line = NULL;
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		error_print("ERROR: File Descriptor");
		exit (1);
	}
	// if (read (fd, buffer, 1))
	// {
	// 	buffer[1] = 0;
	// 	tmp = buffer;
	// 	if (!line)
	// 		line = ft_strdup(tmp);
	// 	ft_putstr_fd("Line: ", 2);
	// 	ft_putendl_fd(line, 2);
	// }
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
	// buffer = get_next_line(fd);
	// while (buffer)
	// {
	// 	if (!tmp)
	// 		tmp = ft_strdup(buffer);
	// 	else
	// 		tmp = ft_strjoin(tmp, buffer);
	// 	free(buffer);
	// 	buffer = get_next_line(fd);
	// }
	ft_putendl_fd(line, 2);
	free(line);
	printf("Completed reading\n");
	close (fd);
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (!check_map(argv[1]))
		{
			init(argv[1]);
			return (0);
		}
		return (1);
	}
	else
		error_print("Error in arguments");
	return (0);
}