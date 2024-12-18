#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

# define BUFFER_SIZE 1

char	*get_next_line(int fd);
void	ft_msgerror(char *msg);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *str);
void    ft_read_map_file(char *mapfile);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *s, char c);
int		ft_strchr(const char *str, char c);
int	    ft_strcmp(const char *s1, const char *s2);

typedef struct  s_map
{
    int     floor;
    int     wall;
    int     money;
    int     door;
    int     player;
    char    **map;
    char    *line;
    char    *temp;
    char    *str;
    int     rows;
    int     cols;
    int     len;
    int     fd;
    int     i;
    int     j;
} t_map;

#endif
