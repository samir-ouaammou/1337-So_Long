#include "so_long.h"

void	ft_msgerror(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(-1);
}

void	ft_flood_fill(char **strs, int i, int j, char c)
{
	if (i < 0 || j < 0 || strs[i] == NULL || strs[i][j] == '\0'
		|| strs[i][j] == '\n')
		return ;
	if (strs[i][j] == c || strs[i][j] == '0')
		strs[i][j] = '*';
	else
		return ;
	ft_flood_fill(strs, i + 1, j, c);
	ft_flood_fill(strs, i - 1, j, c);
	ft_flood_fill(strs, i, j + 1, c);
	ft_flood_fill(strs, i, j - 1, c);
}

void	ft_update_and_validate_elements(t_map *map)
{
	map->i = 0;
	while (map->copy[map->i])
	{
		map->j = 0;
		while (map->copy[map->i][map->j])
		{
			if (map->copy[map->i][map->j] == 'C')
				break ;
			map->j++;
		}
		if (ft_strlen(map->copy[map->i]) != map->j)
			break ;
		map->i++;
	}
	ft_flood_fill(map->copy, map->i, map->j, 'C');
}

void	ft_count_and_check_flood_fill(t_map *map)
{
	map->i = 0;
	map->len = 0;
	while (map->copy[map->i])
	{
		map->j = 0;
		while (map->copy[map->i][map->j])
		{
			if (map->copy[map->i][map->j] == '0')
				map->nbr++;
			if (map->copy[map->i][map->j] == '*')
				map->len++;
			map->j++;
		}
		map->i++;
	}
	if (map->nbr != map->floor)
		map->len = ((map->len + map->nbr) - map->floor);
}

void	ft_validate_map_elements(t_map *map)
{
	map->i = 0;
	while (map->copy[map->i])
	{
		map->j = 0;
		while (map->copy[map->i][map->j])
		{
			if (map->copy[map->i][map->j] == 'P'
				|| map->copy[map->i][map->j] == 'E')
				map->copy[map->i][map->j] = 'C';
			map->j++;
		}
		map->i++;
	}
	ft_update_and_validate_elements(map);
	ft_count_and_check_flood_fill(map);
	if (map->len != (map->player + map->door + map->money))
	{
		write(2, "Error\nInvalid map: C (money), P (player), ", 42);
		write(2, "or E (door) must not be trapped by 1 (walls). ", 46);
		ft_msgerror("Ensure they are accessible.\n");
	}
}
