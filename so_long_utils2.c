/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaammo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 11:44:08 by souaammo          #+#    #+#             */
/*   Updated: 2024/12/30 11:44:10 by souaammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_checkmap(char *str, t_map_checker *map, char c)
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
			ft_msgerror("1 = Wall\nC = Money\nP = Player\nE = Door\n", map);
		}
		map->i++;
	}
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

void	ft_update_and_validate_elements(t_map_checker *map)
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
		if (ft_strlen(map->copy[map->i]) != (size_t)map->j)
			break ;
		map->i++;
	}
	ft_flood_fill(map->copy, map->i, map->j, 'C');
}

void	ft_count_and_check_flood_fill(t_map_checker *map)
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

void	ft_validate_map_elements(t_map_checker *map)
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
		ft_msgerror("Ensure they are accessible\n", map);
	}
}
