/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaammo <souaammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:21:19 by souaammo          #+#    #+#             */
/*   Updated: 2024/12/24 14:19:59 by souaammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include "so_long.h"

void	ft_init_game(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->p_img = NULL;
	game->m_img = NULL;
	game->f_img = NULL;
	game->w_img = NULL;
	game->k_img = NULL;
	game->d_c_img = NULL;
	game->d_o_img = NULL;
	game->map = NULL;
	game->height = 0;
	game->width = 0;
	game->floor = 0;
	game->money = 0;
	game->door = 0;
	game->wall = 0;
	game->temp = 0;
	game->nbr = 0;
	game->p_i = 0;
	game->p_j = 0;
	game->d_i = 0;
	game->d_j = 0;
	game->p_m = 0;
	game->i = 0;
	game->j = 0;
}

void	ft_free_and_exit(t_game *game, char *msg)
{
	if (game->map)
		ft_free_map(game->map);
	ft_msgerror(msg, NULL);
}

int	ft_close_window(void)
{
	exit(0);
	return (0);
}

void	ft_window_size(t_game *window)
{
	window->height = 0;
	while (window->map[window->height])
		window->height++;
	window->width = ft_strlen(window->map[0]);
	window->height *= 64;
	window->width *= 64;
}
