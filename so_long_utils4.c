/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaammo <souaammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:21:11 by souaammo          #+#    #+#             */
/*   Updated: 2024/12/24 14:18:59 by souaammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_free_map(char **temp)
{
	int	i;

	i = 0;
	if (temp != NULL)
	{
		while (temp[i])
		{
			free(temp[i]);
			i++;
		}
		free(temp);
	}
}

void	ft_putnbr(int nbr)
{
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	nbr %= 10;
	nbr += 48;
	write(1, &nbr, 1);
}

void	ft_msgerror(char *msg, t_map_checker *map)
{
	if (map != NULL)
	{
		if (map->str)
			free(map->str);
		if (map->line)
			free(map->line);
		if (map->map)
			ft_free_map(map->map);
		if (map->copy)
			ft_free_map(map->copy);
	}
	write(2, msg, ft_strlen(msg));
	exit(-1);
}
