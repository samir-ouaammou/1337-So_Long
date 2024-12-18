#include "so_long.h"

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
	elements->rows = 0;
	elements->cols = 0;
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
			write(2, "Error\nInvalid character found. Only the ", 40);
			write(2, "following are allowed:\n0 = Floor\n", 33);
			ft_msgerror("1 = Wall\nC = Money\nP = Player\nE = Door\n");
		}
		map->i++;
	}
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
			{
				write(2, "Error\nThe map must be surrounded ", 33);
				ft_msgerror("by walls (1) on all sides.\n");
			}
			i++;
		}
	}
	if (str[0] != '1' || str[ft_strlen(str) - 1] != '1')
		ft_msgerror("Error\nEach row must start and end with a wall (1).\n");
}

void	ft_verify_map_elements(t_map *map)
{
	if (!map->str)
		ft_msgerror("Error\nThe map file is empty\n");
	map->len = ft_strlen(map->map[0]);
	while (map->map[map->j])
	{
		if (map->j == 0 || map->map[map->j + 1] == NULL)
			ft_checkwall(map->map[map->j], map->j, 1337);
		else
			ft_checkwall(map->map[map->j], map->j, 42);
		ft_checkmap(map->map[map->j], map, '$');
		if (map->len != map->i)
		{
			write(2, "Error\nThe map is invalid. ", 26);
			ft_msgerror("All lines must have the same length\n");
		}
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
	{
		write(2, "Error\nInvalid map file name. ", 29);
		ft_msgerror("Please use a valid file, like map.ber\n");
	}
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
