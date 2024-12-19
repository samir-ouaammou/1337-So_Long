#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define BUFFER_SIZE 1

typedef struct s_map_checker
{
	int	floor;
	int	wall;
	int	money;
	int	door;
	int	player;
	char	**copy;
	char	**map;
	char	*line;
	char	*temp;
	char	*str;
	int	len;
	int	nbr;
	int	fd;
	int	i;
	int	j;
}	t_map_checker;

char	*get_next_line(int fd);
void	ft_free_map(char **temp);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *str);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *s, char c);
char	**ft_check_map_file(char *mapfile);
int		ft_strchr(const char *str, char c);
void	ft_msgerror(char *msg, t_map_checker *map);
void	ft_validate_map_elements(t_map_checker *map);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_checkmap(char *str, t_map_checker *map, char c);

#endif
