#include "so_long.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	if (!s1 || !s2)
		return (-1);
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_msgerror(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(-1);
}

void	ft_init_map_elements(t_map *elements)
{
	elements->floor = 0;
	elements->wall = 0;
	elements->money = 0;
	elements->door = 0;
	elements->player = 0;
	elements->map = 0;
	elements->line = 0;
	elements->temp = 0;
	elements->str = 0;
	elements->len = 0;
	elements->fd = 0;
	elements->i = 0;
	elements->j = 0;
}

void	ft_checkmap(char *str, t_map *map, char c)
{
	map->i = 0;
	while (str[map->i])
	{
		c = str[map->i];
		if (c == '0')
			map->floor++;
		else if (c == '1')
			map->wall++;
		else if (c == 'C')
			map->money++;
		else if (c == 'E')
			map->door++;
		else if (c == 'P')
			map->player++;
		else if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P')
		{
			write(2, "Error\nInvalid character found. Only the following are allowed:" ,62);
			ft_msgerror("\n0 = Floor\n1 = Wall\nC = Money\nP = Player\nE = Door\n");
		}
		map->i++;
	}
	if (map->len != map->i)
		ft_msgerror("Error\nThe map is invalid. All lines must have the same\n");
}

void	ft_checkwall(char *str, int index, int n)
{
	int	i;

	i = 0;
	if (n == 1337)
	{
		while (str[i])
		{
			if (str[i] != '1')
				ft_msgerror("Error\nThe map must be surrounded by walls (1) on all sides.\n");
			i++;
		}
	}
	if (str[0] != '1' || str[ft_strlen(str) - 1] != '1')
		ft_msgerror("Error\nEach row must start and end with a wall (1).\n");
}

void	ft_verify_map_elements(t_map *map)
{
	map->len = ft_strlen(map->map[0]);
	while (map->map[map->j])
	{
		if (map->j == 0 || map->map[map->j + 1] == NULL)
			ft_checkwall(map->map[map->j], map->j, 1337);
		else
			ft_checkwall(map->map[map->j], map->j, 42);
		ft_checkmap(map->map[map->j], map, '$');
		map->j++;
	}
	if (map->player != 1)
		ft_msgerror("Error\nThe map must contain exactly one player 'P'.\n");
	if (map->door != 1)
		ft_msgerror("Error\nThe map must contain exactly one door 'E'.\n");
	if (map->money < 1)
		ft_msgerror("Error\nThe map must contain at least one money 'C'.\n");
}

void	ft_read_map_file(char *mapfile)
{
	t_map	map;

	map.len = ft_strlen(mapfile);
	if ((map.len < 5) || (ft_strcmp(&mapfile[map.len - 4], ".ber") != 0))
		ft_msgerror("Error\nInvalid map file name. Please use a valid file,like map.ber\n");
	ft_init_map_elements(&map);
	map.fd = open(mapfile, O_RDONLY);
	if (map.fd == -1)
		ft_msgerror("Error\nopening file map\n");
	while (1)
	{
		map.line = get_next_line(map.fd);
		if (!map.line)
			break ;
		map.temp = ft_strjoin(map.str, map.line);
		if (!map.temp)
			ft_msgerror("Error\nFailed to read the file\n");
		map.str = map.temp;
	}
	map.map = ft_split(map.str, '\n');
	ft_verify_map_elements(&map);
}
