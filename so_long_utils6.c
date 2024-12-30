/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils6.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaammo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 11:46:02 by souaammo          #+#    #+#             */
/*   Updated: 2024/12/30 11:46:04 by souaammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_player_right(t_game *game)
{
	if (game->map[game->p_i][game->p_j + 1] != '1')
	{
		write(1, "Player moved! 🚶‍♂️ Total steps: [", 42);
		ft_putnbr(++game->p_m);
		write(1, "]\n", 2);
		if (game->map[game->p_i][game->p_j + 1] == 'C')
			game->nbr++;
		mlx_put_image_to_window(game->mlx, game->win, game->f_img, game->p_j
			* 64, game->p_i * 64);
		game->map[game->p_i][game->p_j] = '0';
		game->p_j++;
		game->map[game->p_i][game->p_j] = 'P';
		mlx_put_image_to_window(game->mlx, game->win, game->p_img, game->p_j
			* 64, game->p_i * 64);
		if (game->nbr == game->money)
			mlx_put_image_to_window(game->mlx, game->win, game->d_o_img,
				game->d_j * 64, game->d_i * 64);
		if (game->p_i == game->d_i && game->p_j == game->d_j
			&& game->money == game->nbr)
		{
			write(1, "Congratulations! You've won the game!\n", 38);
			ft_close_window(game);
		}
	}
}

void	ft_move_player_left(t_game *game)
{
	if (game->map[game->p_i][game->p_j - 1] != '1')
	{
		write(1, "Player moved! 🚶‍♂️ Total steps: [", 42);
		ft_putnbr(++game->p_m);
		write(1, "]\n", 2);
		if (game->map[game->p_i][game->p_j - 1] == 'C')
			game->nbr++;
		mlx_put_image_to_window(game->mlx, game->win, game->f_img, game->p_j
			* 64, game->p_i * 64);
		game->map[game->p_i][game->p_j] = '0';
		game->p_j--;
		game->map[game->p_i][game->p_j] = 'P';
		mlx_put_image_to_window(game->mlx, game->win, game->p_img, game->p_j
			* 64, game->p_i * 64);
		if (game->nbr == game->money)
			mlx_put_image_to_window(game->mlx, game->win, game->d_o_img,
				game->d_j * 64, game->d_i * 64);
		if (game->p_i == game->d_i && game->p_j == game->d_j
			&& game->money == game->nbr)
		{
			write(1, "Congratulations! You've won the game!\n", 38);
			ft_close_window(game);
		}
	}
}

void	ft_move_player_up(t_game *game)
{
	if (game->map[game->p_i - 1][game->p_j] != '1')
	{
		write(1, "Player moved! 🚶‍♂️ Total steps: [", 42);
		ft_putnbr(++game->p_m);
		write(1, "]\n", 2);
		if (game->map[game->p_i - 1][game->p_j] == 'C')
			game->nbr++;
		mlx_put_image_to_window(game->mlx, game->win, game->f_img, game->p_j
			* 64, game->p_i * 64);
		game->map[game->p_i][game->p_j] = '0';
		game->p_i--;
		game->map[game->p_i][game->p_j] = 'P';
		mlx_put_image_to_window(game->mlx, game->win, game->p_img, game->p_j
			* 64, game->p_i * 64);
		if (game->nbr == game->money)
			mlx_put_image_to_window(game->mlx, game->win, game->d_o_img,
				game->d_j * 64, game->d_i * 64);
		if (game->p_i == game->d_i && game->p_j == game->d_j
			&& game->money == game->nbr)
		{
			write(1, "Congratulations! You've won the game!\n", 38);
			ft_close_window(game);
		}
	}
}

void	ft_move_player_down(t_game *game)
{
	if (game->map[game->p_i + 1][game->p_j] != '1')
	{
		write(1, "Player moved! 🚶‍♂️ Total steps: [", 42);
		ft_putnbr(++game->p_m);
		write(1, "]\n", 2);
		if (game->map[game->p_i + 1][game->p_j] == 'C')
			game->nbr++;
		mlx_put_image_to_window(game->mlx, game->win, game->f_img, game->p_j
			* 64, game->p_i * 64);
		game->map[game->p_i][game->p_j] = '0';
		game->p_i++;
		game->map[game->p_i][game->p_j] = 'P';
		mlx_put_image_to_window(game->mlx, game->win, game->p_img, game->p_j
			* 64, game->p_i * 64);
		if (game->nbr == game->money)
			mlx_put_image_to_window(game->mlx, game->win, game->d_o_img,
				game->d_j * 64, game->d_i * 64);
		if (game->p_i == game->d_i && game->p_j == game->d_j
			&& game->money == game->nbr)
		{
			write(1, "Congratulations! You've won the game!\n", 38);
			ft_close_window(game);
		}
	}
}

int	ft_key_hook(int keycode, t_game *game)
{
	if (keycode == 65307)
		ft_close_window(game);
	if ((keycode == 65363 || keycode == 'd') && game->p_j < game->j - 2)
		ft_move_player_right(game);
	else if ((keycode == 65361 || keycode == 'a') && game->p_j > 1)
		ft_move_player_left(game);
	else if ((keycode == 65362 || keycode == 'w') && game->p_i > 1)
		ft_move_player_up(game);
	else if ((keycode == 65364 || keycode == 's') && game->p_i < game->i - 2)
		ft_move_player_down(game);
	return (0);
}
