/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaammo <souaammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 11:45:15 by souaammo          #+#    #+#             */
/*   Updated: 2025/01/03 20:06:32 by souaammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	ft_check_read_image(t_game *game)
{
	if (!game->w_img || !game->f_img || !game->d_img)
	{
		write (2, "Error:\nFailed to read image file\n", 33);
		ft_close_game(game);
	}
	if (!game->p1_img || !game->p2_img || !game->p3_img)
	{
		write (2, "Error:\nFailed to read image file\n", 33);
		ft_close_game(game);
	}
	if (!game->m1_img || !game->m2_img || !game->m3_img || !game->m4_img)
	{
		write (2, "Error:\nFailed to read image file\n", 33);
		ft_close_game(game);
	}
	if (!game->e1_img || !game->e2_img || !game->e3_img || !game->e4_img
		|| !game->e5_img || !game->e6_img)
	{
		write (2, "Error:\nFailed to read image file\n", 33);
		ft_close_game(game);
	}
}

void	ft_enemy_img(t_game *game)
{
	game->e1_img = mlx_xpm_file_to_image(game->mlx,
			"textures/Bonus/Enemy/e1.xpm", &game->i, &game->j);
	game->e2_img = mlx_xpm_file_to_image(game->mlx,
			"textures/Bonus/Enemy/e2.xpm", &game->i, &game->j);
	game->e3_img = mlx_xpm_file_to_image(game->mlx,
			"textures/Bonus/Enemy/e3.xpm", &game->i, &game->j);
	game->e4_img = mlx_xpm_file_to_image(game->mlx,
			"textures/Bonus/Enemy/e4.xpm", &game->i, &game->j);
	game->e5_img = mlx_xpm_file_to_image(game->mlx,
			"textures/Bonus/Enemy/e5.xpm", &game->i, &game->j);
	game->e6_img = mlx_xpm_file_to_image(game->mlx,
			"textures/Bonus/Enemy/e6.xpm", &game->i, &game->j);
}

void	ft_read_to_img(t_game *game)
{
	game->w_img = mlx_xpm_file_to_image(game->mlx, "textures/Bonus/Wall/w.xpm",
			&game->i, &game->j);
	game->f_img = mlx_xpm_file_to_image(game->mlx, "textures/Bonus/Floor/f.xpm",
			&game->i, &game->j);
	game->m1_img = mlx_xpm_file_to_image(game->mlx,
			"textures/Bonus/Money/m1.xpm", &game->i, &game->j);
	game->m2_img = mlx_xpm_file_to_image(game->mlx,
			"textures/Bonus/Money/m2.xpm", &game->i, &game->j);
	game->m3_img = mlx_xpm_file_to_image(game->mlx,
			"textures/Bonus/Money/m3.xpm", &game->i, &game->j);
	game->m4_img = mlx_xpm_file_to_image(game->mlx,
			"textures/Bonus/Money/m4.xpm", &game->i, &game->j);
	game->d_img = mlx_xpm_file_to_image(game->mlx, "textures/Bonus/Door/d.xpm",
			&game->i, &game->j);
	game->p1_img = mlx_xpm_file_to_image(game->mlx,
			"textures/Bonus/Player/p1.xpm", &game->i, &game->j);
	game->p2_img = mlx_xpm_file_to_image(game->mlx,
			"textures/Bonus/Player/p2.xpm", &game->i, &game->j);
	game->p3_img = mlx_xpm_file_to_image(game->mlx,
			"textures/Bonus/Player/p3.xpm", &game->i, &game->j);
	ft_enemy_img(game);
	ft_check_read_image(game);
}
