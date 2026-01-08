#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static void    error_exit(const char *msg)
{
    write(2, "Error\n", 6);
    write(2, msg, strlen(msg));
    write(2, "\n", 1);
    exit(1);
}

static int  has_exact_cub_extension(const char *file)
{
    size_t  len;
    const char *p;

    if (!file)
        return (0);

    len = strlen(file);
    if (len < 5)                 // 최소: "a.cub"
        return (0);

    if (strcmp(file + len - 4, ".cub") != 0)
        return (0);

    // reject ".cub" appearing earlier, e.g. "map.cub.cub"
    p = strstr(file, ".cub");
    if (p && (size_t)(p - file) < len - 4)
        return (0);

    return (1);
}

int main(int argc, char **argv)
{
    int fd;

    if (argc != 2)
        error_exit("Usage: ./cub3D <map.cub>");

    if (!has_exact_cub_extension(argv[1]))
        error_exit("Invalid file extension (must be exactly .cub)");

    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
        error_exit("Cannot open file");

    close(fd);

    // temporary success message (remove later)
    write(1, "OK\n", 3);
    return (0);
}











#include <stddef.h> // for NULL

char    *ft_strstr(const char *haystack, const char *needle)
{
    size_t i;
    size_t j;

    if (!haystack || !needle)
        return NULL;

    if (needle[0] == '\0')
        return (char *)haystack;

    i = 0;
    while (haystack[i] != '\0')
    {
        j = 0;
        while (haystack[i + j] != '\0' && needle[j] != '\0'
            && haystack[i + j] == needle[j])
        {
            j++;
        }
        if (needle[j] == '\0') // reached end of needle => full match
            return (char *)(haystack + i);
        i++;
    }
    return NULL;
}
