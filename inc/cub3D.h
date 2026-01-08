# ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stddef.h>

typedef struct s_game
{
	//storing file paths for textures for each wall direction
	char *no;
	char *so;
	char *we;
	char *ea;

	//storing the colors of the ceiling and ground
	int     floor_r;
    int     floor_g;
    int     floor_b;

    int     ceil_r;
    int     ceil_g;
    int     ceil_b;

	//map
    char    **map;
}t_game;

int	ft_strlen(const char *s);
int ft_strcmp(char *s1, char *s2);
int	check_extension(char *filename);
char	*ft_strstr(char *haystack, char *needle);

#endif