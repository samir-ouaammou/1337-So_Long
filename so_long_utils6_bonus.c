#include "so_long_bonus.h"

void	ft_put_money_to_window(t_game *game)
{
	game->player_animation_step = (game->player_animation_speed / 20) % 5;
	if (game->player_animation_step == 0)
		ft_put_img_to_win(game, game->m1_img);
	else if (game->player_animation_step == 1)
		ft_put_img_to_win(game, game->m2_img);
	else if (game->player_animation_step == 2)
		ft_put_img_to_win(game, game->m3_img);
	else if (game->player_animation_step == 3)
		ft_put_img_to_win(game, game->m4_img);
	else if (game->player_animation_step == 4)
		ft_put_img_to_win(game, game->m1_img);
}

void	ft_put_player_to_window(t_game *game)
{
	game->player_animation_step = (game->player_animation_speed / (15 * 2)) % 3;
	if (game->player_animation_step == 0)
		ft_put_img_to_win(game, game->p1_img);
	else if (game->player_animation_step == 1)
		ft_put_img_to_win(game, game->p2_img);
	else if (game->player_animation_step == 2)
		ft_put_img_to_win(game, game->p1_img);
}

void	ft_put_enemy_to_window(t_game *game)
{
	game->player_animation_step = (game->player_animation_speed / 15) % 7;
	if (game->player_animation_step == 0)
		ft_put_img_to_win(game, game->e1_img);
	else if (game->player_animation_step == 1)
		ft_put_img_to_win(game, game->e2_img);
	else if (game->player_animation_step == 2)
		ft_put_img_to_win(game, game->e3_img);
	else if (game->player_animation_step == 3)
		ft_put_img_to_win(game, game->e4_img);
	else if (game->player_animation_step == 4)
		ft_put_img_to_win(game, game->e5_img);
	else if (game->player_animation_step == 5)
		ft_put_img_to_win(game, game->e6_img);
	else if (game->player_animation_step == 6)
		ft_put_img_to_win(game, game->e1_img);
}

void	ft_sleep(t_game *game)
{
	game->player_animation_speed++;
	game->i = 0;
	if (game->height * game->width <= 250)
		usleep(4000);
	else if (game->height * game->width <= 500)
		usleep(3000);
	else if (game->height * game->width <= 800)
		usleep(1000);
}

int	ft_file_put_img_to_window(t_game *game)
{
	ft_sleep(game);
	while (game->map[game->i])
	{
		game->j = 0;
		while (game->map[game->i][game->j])
		{
			if (game->map[game->i][game->j] == '1' && game->tmp == 0)
				ft_put_img_to_win(game, game->w_img);
			else if (game->map[game->i][game->j] == '0'
					|| game->map[game->i][game->j] == 'E')
				ft_put_img_to_win(game, game->f_img);
			if (game->i == game->d_i && game->j == game->d_j
				&& game->money == game->nbr)
				ft_put_img_to_win(game, game->d_img);
			else if (game->map[game->i][game->j] == 'P')
				ft_put_player_to_window(game);
			else if (game->map[game->i][game->j] == 'C')
				ft_put_money_to_window(game);
			else if (game->map[game->i][game->j] == 'X')
				ft_put_enemy_to_window(game);
			game->j++;
		}
		game->i++;
	}
	return (0);
}
