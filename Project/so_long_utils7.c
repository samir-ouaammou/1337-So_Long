/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils7.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaammo <souaammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 11:46:22 by souaammo          #+#    #+#             */
/*   Updated: 2025/01/03 20:06:25 by souaammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_player_left(t_game *game)
{
	if (game->map[game->p_i][game->p_j - 1] != '1')
	{
		ft_put_str_to_window(game, ++game->player_movement);
		if (game->map[game->p_i][game->p_j - 1] == 'C')
			game->nbr++;
		if (game->map[game->p_i][game->p_j - 1] == 'X')
		{
			write(1, "\nGame Over: The enemy killed you!\n\n", 35);
			ft_close_game(game);
		}
		game->map[game->p_i][game->p_j] = '0';
		game->map[game->p_i][game->p_j - 1] = 'P';
		game->p_j--;
		if (game->money == game->nbr && game->p_i == game->d_i
			&& game->p_j == game->d_j)
		{
			write(1, "\nCongratulations! You've won the game!\n\n", 40);
			ft_close_game(game);
		}
	}
}

void	ft_move_player_up(t_game *game)
{
	if (game->map[game->p_i - 1][game->p_j] != '1')
	{
		ft_put_str_to_window(game, ++game->player_movement);
		if (game->map[game->p_i - 1][game->p_j] == 'C')
			game->nbr++;
		if (game->map[game->p_i - 1][game->p_j] == 'X')
		{
			write(1, "\nGame Over: The enemy killed you!\n\n", 35);
			ft_close_game(game);
		}
		game->map[game->p_i][game->p_j] = '0';
		game->map[game->p_i - 1][game->p_j] = 'P';
		game->p_i--;
		if (game->money == game->nbr && game->p_i == game->d_i
			&& game->p_j == game->d_j)
		{
			write(1, "\nCongratulations! You've won the game!\n\n", 40);
			ft_close_game(game);
		}
	}
}

void	ft_move_player_right(t_game *game)
{
	if (game->map[game->p_i][game->p_j + 1] != '1')
	{
		ft_put_str_to_window(game, ++game->player_movement);
		if (game->map[game->p_i][game->p_j + 1] == 'C')
			game->nbr++;
		if (game->map[game->p_i][game->p_j + 1] == 'X')
		{
			write(1, "\nGame Over: The enemy killed you!\n\n", 35);
			ft_close_game(game);
		}
		game->map[game->p_i][game->p_j] = '0';
		game->map[game->p_i][game->p_j + 1] = 'P';
		game->p_j++;
		if (game->money == game->nbr && game->p_i == game->d_i
			&& game->p_j == game->d_j)
		{
			write(1, "\nCongratulations! You've won the game!\n\n", 40);
			ft_close_game(game);
		}
	}
}

void	ft_move_player_down(t_game *game)
{
	if (game->map[game->p_i + 1][game->p_j] != '1')
	{
		ft_put_str_to_window(game, ++game->player_movement);
		if (game->map[game->p_i + 1][game->p_j] == 'C')
			game->nbr++;
		if (game->map[game->p_i + 1][game->p_j] == 'X')
		{
			write(1, "\nGame Over: The enemy killed you!\n\n", 35);
			ft_close_game(game);
		}
		game->map[game->p_i][game->p_j] = '0';
		game->map[game->p_i + 1][game->p_j] = 'P';
		game->p_i++;
		if (game->money == game->nbr && game->p_i == game->d_i
			&& game->p_j == game->d_j)
		{
			write(1, "\nCongratulations! You've won the game!\n\n", 40);
			ft_close_game(game);
		}
	}
}

int	ft_key_hook(int keycode, t_game *game)
{
	game->tmp++;
	if (keycode == 65307)
		ft_close_game(game);
	else if ((keycode == 65361 || keycode == 'a') && game->p_j > 1)
		ft_move_player_left(game);
	else if ((keycode == 65362 || keycode == 'w') && game->p_i > 1)
		ft_move_player_up(game);
	else if ((keycode == 65363 || keycode == 'd') && game->p_j < game->j - 2)
		ft_move_player_right(game);
	else if ((keycode == 65364 || keycode == 's') && game->p_i < game->i - 2)
		ft_move_player_down(game);
	return (0);
}
