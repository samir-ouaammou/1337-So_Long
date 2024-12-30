/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaammo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 11:42:50 by souaammo          #+#    #+#             */
/*   Updated: 2024/12/30 11:42:52 by souaammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_init_game(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->map = NULL;
	game->str = NULL;
	game->width = 0;
	game->height = 0;
	game->money = 0;
	game->nbr = 0;
	game->tmp = 0;
	game->p_i = 0;
	game->p_j = 0;
	game->d_i = 0;
	game->d_j = 0;
	game->i = 0;
	game->j = 0;
	game->player_movement = 0;
	game->player_animation_speed = 0;
	game->enemy_animation_speed = 0;
	game->money_animation_speed = 0;
	game->door_animation_speed = 0;
}

void	ft_window_size(t_game *game)
{
	while (game->map[game->height])
	{
		game->width = 0;
		while (game->map[game->height][game->width])
		{
			if (game->map[game->height][game->width] == 'P')
			{
				game->p_i = game->height;
				game->p_j = game->width;
			}
			if (game->map[game->height][game->width] == 'E')
			{
				game->d_i = game->height;
				game->d_j = game->width;
			}
			if (game->map[game->height][game->width] == 'C')
				game->money++;
			game->width++;
		}
		game->height++;
	}
	game->width = ft_strlen(game->map[0]);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		ft_msgerror("Error\nInvalid number of arguments.\n", NULL);
	ft_init_game(&game);
	game.map = ft_check_map_file(av[1]);
	ft_window_size(&game);
	game.mlx = mlx_init();
	if (!game.mlx)
		ft_free_and_exit(game.map, "Error\nerror mlx init\n");
	game.win = mlx_new_window(game.mlx, game.width * 64, game.height * 64,
			"Game Si Samir");
	if (!game.win)
		ft_free_and_exit(game.map, "Error\nerror mlx to new window\n");
	ft_read_to_img(&game);
	mlx_loop_hook(game.mlx, ft_file_put_img_to_window, &game);
	mlx_key_hook(game.win, ft_key_hook, &game);
	mlx_hook(game.win, 17, 0, ft_close_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
