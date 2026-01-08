#include "../inc/cub3D.h"

static void    error_exit(const char *msg)
{
    write(2, "Error\n", 6);
    write(2, msg, ft_strlen(msg));
    write(2, "\n", 1);
    exit(1);
}

int	check_extension(char *filename)
{
	int		len;
	char	*str;

	if (!filename)
		return (0);
	len = ft_strlen(filename);
	if (len < 5)
		return (0);
	if (ft_strcmp(filename + len - 4, ".cub") != 0)
		return (0);
	str = ft_strstr(filename, ".cub");
	//if there is any other .cub in the filename
	if (str && str - filename < len - 4)
		return (0);
	return (1);
}

int main(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		error_exit("Usage: ./cub3D <map.cub>");
	if (!check_extension(argv[1]))
		error_exit("Invalid filename or extension");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error_exit("Cannot open the file");
	close(fd);

	return (0);

}