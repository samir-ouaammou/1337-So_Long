#include "so_long_bonus.h"

void	ft_init_map_elements(t_map_checker *elements)
{
	elements->floor = 0;
	elements->wall = 0;
	elements->money = 0;
	elements->door = 0;
	elements->player = 0;
	elements->enemy = 0;
	elements->copy = 0;
	elements->map = 0;
	elements->line = 0;
	elements->temp = 0;
	elements->str = 0;
	elements->len = 0;
	elements->nbr = 0;
	elements->fd = 0;
	elements->i = 0;
	elements->j = 0;
}

void	ft_checkwall(char *str, int n, t_map_checker *map)
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
				ft_msgerror("by walls (1) on all sides\n", map);
			}
			i++;
		}
	}
	if (str[0] != '1' || str[ft_strlen(str) - 1] != '1')
	{
		write(2, "Error\nEach row must start and", 29);
		ft_msgerror(" end with a wall (1)\n", map);
	}
}

void	ft_verify_map_elements(t_map_checker *map)
{
	if (!map->str)
		ft_msgerror("Error\nThe map file is empty\n", map);
	map->len = ft_strlen(map->map[0]);
	while (map->map[map->j])
	{
		if (map->j == 0 || map->map[map->j + 1] == NULL)
			ft_checkwall(map->map[map->j], 1337, map);
		else
			ft_checkwall(map->map[map->j], 42, map);
		ft_checkmap(map->map[map->j], map, '$');
		if (map->len != map->i)
		{
			write(2, "Error\nThe map is invalid. ", 26);
			ft_msgerror("All lines must have the same length\n", map);
		}
		map->j++;
	}
	if (map->player != 1)
		ft_msgerror("Error\nThe map must contain exactly one player P\n", map);
	if (map->door != 1)
		ft_msgerror("Error\nThe map must contain exactly one door E\n", map);
	if (map->money < 1)
		ft_msgerror("Error\nThe map must contain at least one money C\n", map);
	ft_validate_map_elements(map);
	ft_free_map(map->copy);
}

void	ft_read_map_file(t_map_checker *map)
{
	while (1)
	{
		map->line = get_next_line(map->fd);
		if (!map->line)
			break ;
		if (map->line[0] == '\n')
		{
			write(2, "Error\nInvalid map: The map contains an ", 39);
			write(2, "empty line. Ensure there are no blank ", 38);
			ft_msgerror("lines between rows of the map.\n", map);
		}
		map->temp = ft_strjoin(map->str, map->line);
		if (!map->temp)
			ft_msgerror("Error\nFailed to read the file\n", map);
		map->str = map->temp;
		free(map->line);
	}
}

char	**ft_check_map_file(char *mapfile)
{
	t_map_checker	map;

	map.len = ft_strlen(mapfile);
	if ((map.len < 5) || (ft_strcmp(&mapfile[map.len - 4], ".ber") != 0))
	{
		write(2, "Error\nInvalid map file name. ", 29);
		ft_msgerror("Please use a valid file, like map.ber\n", NULL);
	}
	ft_init_map_elements(&map);
	map.fd = open(mapfile, O_RDONLY);
	if (map.fd == -1)
		ft_msgerror("Error\nError opening file map\n", NULL);
	ft_read_map_file(&map);
	map.map = ft_split(map.str, '\n');
	map.copy = ft_split(map.str, '\n');
	ft_verify_map_elements(&map);
	free(map.str);
	return (map.map);
}
