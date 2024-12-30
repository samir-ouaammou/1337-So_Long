/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils8_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaammo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 11:46:32 by souaammo          #+#    #+#             */
/*   Updated: 2024/12/30 11:46:34 by souaammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	ft_free_and_exit(char **temp, char *msg)
{
	if (temp)
	{
		while (*temp)
		{
			free(*temp);
			temp++;
		}
		free(temp);
	}
	write(2, msg, ft_strlen(msg));
	exit(-1);
}

void	ft_free_image(t_game *game)
{
	if (game->p2_img)
		mlx_destroy_image(game->mlx, game->p2_img);
	if (game->p3_img)
		mlx_destroy_image(game->mlx, game->p3_img);
	if (game->m1_img)
		mlx_destroy_image(game->mlx, game->m1_img);
	if (game->m2_img)
		mlx_destroy_image(game->mlx, game->m2_img);
	if (game->m3_img)
		mlx_destroy_image(game->mlx, game->m3_img);
	if (game->m4_img)
		mlx_destroy_image(game->mlx, game->m4_img);
	if (game->e1_img)
		mlx_destroy_image(game->mlx, game->e1_img);
	if (game->e2_img)
		mlx_destroy_image(game->mlx, game->e2_img);
	if (game->e3_img)
		mlx_destroy_image(game->mlx, game->e3_img);
	if (game->e4_img)
		mlx_destroy_image(game->mlx, game->e4_img);
	if (game->e5_img)
		mlx_destroy_image(game->mlx, game->e5_img);
	if (game->e6_img)
		mlx_destroy_image(game->mlx, game->e6_img);
}

int	ft_close_game(t_game *game)
{
	if (game->w_img)
		mlx_destroy_image(game->mlx, game->w_img);
	if (game->f_img)
		mlx_destroy_image(game->mlx, game->f_img);
	if (game->d_img)
		mlx_destroy_image(game->mlx, game->d_img);
	if (game->p1_img)
		mlx_destroy_image(game->mlx, game->p1_img);
	ft_free_image(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	if (game->mlx)
		free(game->mlx);
	game->i = 0;
	while (game->i < game->height)
		free(game->map[game->i++]);
	free(game->map);
	exit(0);
	return (0);
}
