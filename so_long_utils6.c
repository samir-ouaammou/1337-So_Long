#include "so_long.h"


// void    ft_move_player_right(t_game *game)
// {

// }



int	ft_key_hook(int keycode, t_game *game)
{
    game->money = 5;
	printf("Key pressed: %d\n", keycode);
	if (keycode == 65361 || keycode == 'a')
	{
		if (game->p_j > 1 && game->map[game->p_i][game->p_j - 1] != '1'  && (game->map[game->p_i][game->p_j - 1] != 'E' || game->nbr == game->money))
		{
            if (game->map[game->p_i][game->p_j - 1] == 'C')
                game->nbr++;
			mlx_put_image_to_window(game->mlx, game->win, game->f_img, game->p_j * 64, game->p_i * 64);
			game->map[game->p_i][game->p_j] = '0';
			game->p_j--;
			game->map[game->p_i][game->p_j] = 'P';
			mlx_put_image_to_window(game->mlx, game->win, game->p_img, game->p_j * 64, game->p_i * 64);
            if (game->nbr == game->money && game->p_i != game->d_i && game->p_j != game->d_j)
                mlx_put_image_to_window(game->mlx, game->win, game->d_o_img, game->d_j * 64, game->d_i * 64);
            if (game->p_i == game->d_i && game->p_j == game->d_j)
            {
                write(1, "Congratulations! You've won the game!\n", 38);
                exit(0);
            }
		}
	}
	else if (keycode == 65362 || keycode == 'w')
	{
		if (game->p_i > 1 && game->map[game->p_i - 1][game->p_j] != '1'&& (game->map[game->p_i - 1][game->p_j] != 'E' || game->nbr == game->money))
		{
            if (game->map[game->p_i - 1][game->p_j] =='C')
                game->nbr++;
			mlx_put_image_to_window(game->mlx, game->win, game->f_img, game->p_j * 64, game->p_i * 64);
			game->map[game->p_i][game->p_j] = '0';
			game->p_i--;
			game->map[game->p_i][game->p_j] = 'P';
			mlx_put_image_to_window(game->mlx, game->win, game->p_img, game->p_j * 64, game->p_i * 64);
            if (game->nbr == game->money && game->p_i != game->d_i && game->p_j != game->d_j)
               mlx_put_image_to_window(game->mlx, game->win, game->d_o_img, game->d_j * 64, game->d_i * 64);
            if (game->p_i == game->d_i && game->p_j == game->d_j)
            {
                write(1, "Congratulations! You've won the game!\n", 38);
                exit(0);
            }
		}
	}
	else if (keycode == 65363 || keycode == 'd')
	{
		if (game->p_j < game->j - 2 && game->map[game->p_i][game->p_j + 1] != '1' && (game->map[game->p_i][game->p_j + 1] != 'E' || game->nbr == game->money))
		{
            if (game->map[game->p_i][game->p_j + 1] == 'C')
                game->nbr++;
			mlx_put_image_to_window(game->mlx, game->win, game->f_img, game->p_j * 64, game->p_i * 64);
			game->map[game->p_i][game->p_j] = '0';
			game->p_j++;
			game->map[game->p_i][game->p_j] = 'P';
			mlx_put_image_to_window(game->mlx, game->win, game->p_img, game->p_j * 64, game->p_i * 64);
            if (game->nbr == game->money && game->p_i != game->d_i && game->p_j != game->d_j)
                mlx_put_image_to_window(game->mlx, game->win, game->d_o_img, game->d_j * 64, game->d_i * 64);
            if (game->p_i == game->d_i && game->p_j == game->d_j)
            {
                write(1, "Congratulations! You've won the game!\n", 38);
                exit(0);
            }
		}
	}
	else if (keycode == 65364 || keycode == 's')
	{
		if (game->p_i < game->i - 2 && game->map[game->p_i + 1][game->p_j] != '1' && (game->map[game->p_i + 1][game->p_j] != 'E' || game->nbr == game->money))
		{
            if (game->map[game->p_i + 1][game->p_j] == 'C')
                game->nbr++;
			mlx_put_image_to_window(game->mlx, game->win, game->f_img, game->p_j * 64, game->p_i * 64);
			game->map[game->p_i][game->p_j] = '0';
			game->p_i++;
			game->map[game->p_i][game->p_j] = 'P';
			mlx_put_image_to_window(game->mlx, game->win, game->p_img, game->p_j * 64, game->p_i * 64);
            if (game->nbr == game->money && game->p_i != game->d_i && game->p_j != game->d_j)
                mlx_put_image_to_window(game->mlx, game->win, game->d_o_img, game->d_j * 64, game->d_i * 64);
            if (game->p_i == game->d_i && game->p_j == game->d_j)
            {
                write(1, "Congratulations! You've won the game!\n", 38);
                exit(0);
            }
		}
	}
        
	return (0);
}



/*


ft_move_player_left()
ft_move_player_up()
ft_move_player_down()

*/