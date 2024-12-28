#include "so_long_bonus.h"

void	ft_put_img_to_win(t_game *game, void *img)
{
	mlx_put_image_to_window(game->mlx, game->win, img, game->j * 64, game->i
		* 64);
}

void	ft_put_str_to_window(t_game *game, int nbr)
{
	game->str = ft_itoa(nbr);
	mlx_put_image_to_window(game->mlx, game->win, game->w_img, 0, 0);
	mlx_put_image_to_window(game->mlx, game->win, game->w_img, 64, 0);
	mlx_put_image_to_window(game->mlx, game->win, game->w_img, 128, 0);
	mlx_string_put(game->mlx, game->win, 32, 32, 0xFFFFFF, "Steps: ");
	mlx_string_put(game->mlx, game->win, 80, 32, 0xFFFFFF, game->str);
	free(game->str);
	game->str = NULL;
}

void	ft_enemy_img(t_game *game)
{
	game->e1_img = mlx_xpm_file_to_image(game->mlx,
			"textures_bonus/Enemy/e1.xpm", &game->i, &game->j);
	game->e2_img = mlx_xpm_file_to_image(game->mlx,
			"textures_bonus/Enemy/e2.xpm", &game->i, &game->j);
	game->e3_img = mlx_xpm_file_to_image(game->mlx,
			"textures_bonus/Enemy/e3.xpm", &game->i, &game->j);
	game->e4_img = mlx_xpm_file_to_image(game->mlx,
			"textures_bonus/Enemy/e4.xpm", &game->i, &game->j);
	game->e5_img = mlx_xpm_file_to_image(game->mlx,
			"textures_bonus/Enemy/e5.xpm", &game->i, &game->j);
	game->e6_img = mlx_xpm_file_to_image(game->mlx,
			"textures_bonus/Enemy/e6.xpm", &game->i, &game->j);
}

void	ft_read_to_img(t_game *game)
{
	game->w_img = mlx_xpm_file_to_image(game->mlx, "textures_bonus/Wall/w.xpm",
			&game->i, &game->j);
	game->f_img = mlx_xpm_file_to_image(game->mlx, "textures_bonus/Floor/f.xpm",
			&game->i, &game->j);
	game->m1_img = mlx_xpm_file_to_image(game->mlx,
			"textures_bonus/Money/m1.xpm", &game->i, &game->j);
	game->m2_img = mlx_xpm_file_to_image(game->mlx,
			"textures_bonus/Money/m2.xpm", &game->i, &game->j);
	game->m3_img = mlx_xpm_file_to_image(game->mlx,
			"textures_bonus/Money/m3.xpm", &game->i, &game->j);
	game->m4_img = mlx_xpm_file_to_image(game->mlx,
			"textures_bonus/Money/m4.xpm", &game->i, &game->j);
	game->d_img = mlx_xpm_file_to_image(game->mlx, "textures_bonus/Door/d.xpm",
			&game->i, &game->j);
	game->p1_img = mlx_xpm_file_to_image(game->mlx,
			"textures_bonus/Player/p1.xpm", &game->i, &game->j);
	game->p2_img = mlx_xpm_file_to_image(game->mlx,
			"textures_bonus/Player/p2.xpm", &game->i, &game->j);
	game->p3_img = mlx_xpm_file_to_image(game->mlx,
			"textures_bonus/Player/p3.xpm", &game->i, &game->j);
	ft_enemy_img(game);
}
