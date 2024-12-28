/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaammo <souaammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:20:25 by souaammo          #+#    #+#             */
/*   Updated: 2024/12/28 15:57:44 by souaammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_image_to_window(t_game *game, int nbr)
{
	if (nbr == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->f_img, game->j * 64,
			game->i * 64);
	else if (nbr == 1)
		mlx_put_image_to_window(game->mlx, game->win, game->w_img, game->j * 64,
			game->i * 64);
	else if (nbr == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->m_img, game->j * 64,
			game->i * 64);
	else if (nbr == 'P')
	{
		game->p_i = game->i;
		game->p_j = game->j;
		mlx_put_image_to_window(game->mlx, game->win, game->p_img, game->j * 64,
			game->i * 64);
	}
	else if (nbr == 'E')
	{
		game->d_i = game->i;
		game->d_j = game->j;
		mlx_put_image_to_window(game->mlx, game->win, game->f_img, game->j * 64,
			game->i * 64);
	}
}

void	ft_draw_map(t_game *game)
{
	game->i = 0;
	while (game->map[game->i])
	{
		game->j = 0;
		while (game->map[game->i][game->j])
		{
			if (game->map[game->i][game->j] == 'P')
				ft_put_image_to_window(game, 'P');
			else if (game->map[game->i][game->j] == '1')
				ft_put_image_to_window(game, 1);
			else if (game->map[game->i][game->j] == 'C')
			{
				game->money++;
				ft_put_image_to_window(game, 'C');
			}
			else if (game->map[game->i][game->j] == 'E')
				ft_put_image_to_window(game, 'E');
			else
				ft_put_image_to_window(game, 0);
			game->j++;
		}
		game->i++;
	}
}

void	ft_read_image(t_game *game)
{
	game->w_img = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm",
			&game->i, &game->j);
	game->f_img = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm",
			&game->i, &game->j);
	game->p_img = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm",
			&game->i, &game->j);
	game->m_img = mlx_xpm_file_to_image(game->mlx, "textures/money.xpm",
			&game->i, &game->j);
	game->d_c_img = mlx_xpm_file_to_image(game->mlx, "textures/door_close.xpm",
			&game->i, &game->j);
	game->d_o_img = mlx_xpm_file_to_image(game->mlx, "textures/door_open.xpm",
			&game->i, &game->j);
	if (!game->w_img || !game->f_img || !game->p_img || !game->m_img
		|| !game->d_c_img || !game->d_o_img)
	{
		write (2, "Error:\nFailed to read image file\n", 33);
		ft_close_window(game);
	}
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
		ft_free_and_exit(&game, "Error\nerror mlx init\n");
	game.win = mlx_new_window(game.mlx, game.width, game.height,
			"Game Si Samir");
	if (!game.win)
		ft_free_and_exit(&game, "Error\nerror mlw new window\n");
	ft_read_image(&game);
	ft_draw_map(&game);
	mlx_key_hook(game.win, ft_key_hook, &game);
	mlx_hook(game.win, 17, 0, ft_close_window, &game);
	mlx_loop(game.mlx);
	ft_free_map(game.map);
	return (0);
}
