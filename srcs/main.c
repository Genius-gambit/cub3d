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
	// char	*tmp;
	char	*buffer;

	fd = 0;
	buffer = NULL;
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		error_print("ERROR: File Descriptor");
		exit (1);
	}
	buffer = get_next_line(fd);
	while (buffer)
	{
		printf("%s", buffer);
		buffer = get_next_line(fd);
	}
	printf("Completed reading\n");
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