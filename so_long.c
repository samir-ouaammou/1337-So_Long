#include "so_long.h"

typedef struct	s_game
{
	void	*mlx;
	void	*win;
	void	*p_img;
	void	*m_img;
	void	*f_img;
	void	*w_img;
	void	*d_img;
	int		money;
	int		door;
	int		floor;
	int		wall;
	char	**map;
	int		height;
	int		width;
	int		temp;
	int		nbr;
	int		p_i;
	int		p_j;
	int		i;
	int		j;
}	t_game;

int ft_close_window(void)
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

void	ft_put_image_to_window(t_game *game, int nbr)
{
	if (nbr == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->f_img, game->j * 64, game->i * 64);
	else if (nbr == 1)
		mlx_put_image_to_window(game->mlx, game->win, game->w_img, game->j * 64, game->i * 64);
	else if (nbr == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->m_img, game->j * 64, game->i * 64);
	else if (nbr == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->p_img, game->j * 64, game->i * 64);
	else if (nbr == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->d_img, game->j * 64, game->i * 64);
}

void ft_draw_map(t_game *game)
{
	game->money = 0;
	game->i = 0;
	while (game->map[game->i])
	{
		game->j = 0;
		while (game->map[game->i][game->j])
		{
			if (game->map[game->i][game->j] == 'P')
			{
				game->p_i = game->i;
				game->p_j = game->j;
			}
			if (game->map[game->i][game->j] == '1')
				ft_put_image_to_window(game, 1);
			else if (game->map[game->i][game->j] == 'C')
				ft_put_image_to_window(game, 'C');
			else if (game->map[game->i][game->j] == 'P')
				ft_put_image_to_window(game, 'P');
			else if (game->map[game->i][game->j] == 'E')
				ft_put_image_to_window(game, 'E');
			else
				ft_put_image_to_window(game, 0);

			game->j++;
		}
		game->i++;
	}
}

void	ft_load_textures(t_game *game)
{
	game->w_img = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &game->i, &game->j);
	game->f_img = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm", &game->i, &game->j);
	game->m_img = mlx_xpm_file_to_image(game->mlx, "textures/money.xpm", &game->i, &game->j);
	game->d_img = mlx_xpm_file_to_image(game->mlx, "textures/door_close.xpm", &game->i, &game->j);
	game->p_img = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm", &game->i, &game->j);
}

int	ft_key_hook(int keycode, t_game *game)
{
	printf("Key pressed: %d\n", keycode);
	if (keycode == 65361 || keycode == 'a')
	{
		if (game->p_j > 1 || game->map[game->p_i][game->p_j] != '1')
		{
			mlx_put_image_to_window(game->mlx, game->win, game->f_img, game->p_j * 64, game->p_i * 64);
			game->map[game->p_i][game->p_j] = '0';
			game->p_j--;
			game->map[game->p_i][game->p_j] = 'P';
			mlx_put_image_to_window(game->mlx, game->win, game->p_img, game->p_j * 64, game->p_i * 64);
			return (0);
		}
	}
	else if (keycode == 65362 || keycode == 'w')
	{
		if (game->p_i > 1 && game->map[game->p_i][game->p_j] != '1')
		{
			mlx_put_image_to_window(game->mlx, game->win, game->f_img, game->p_j * 64, game->p_i * 64);
			game->map[game->p_i][game->p_j] = '0';
			game->p_i--;
			game->map[game->p_i][game->p_j] = 'P';
			mlx_put_image_to_window(game->mlx, game->win, game->p_img, game->p_j * 64, game->p_i * 64);
		}
	}
	else if (keycode == 65363 || keycode == 'd')
	{
		if (game->p_j < game->j - 2  && game->map[game->p_i][game->p_j] != '1')
		{
			mlx_put_image_to_window(game->mlx, game->win, game->f_img, game->p_j * 64, game->p_i * 64);
			game->map[game->p_i][game->p_j] = '0';
			game->p_j++;
			game->map[game->p_i][game->p_j] = 'P';
			mlx_put_image_to_window(game->mlx, game->win, game->p_img, game->p_j * 64, game->p_i * 64);
			return (0);
		}
	}
	else if (keycode == 65364 || keycode == 's')
	{
		if (game->p_i < game->i - 2 && game->map[game->p_i][game->p_j] != '1')
		{
			mlx_put_image_to_window(game->mlx, game->win, game->f_img, game->p_j * 64, game->p_i * 64);
			game->map[game->p_i][game->p_j] = '0';
			game->p_i++;
			game->map[game->p_i][game->p_j] = 'P';
			mlx_put_image_to_window(game->mlx, game->win, game->p_img, game->p_j * 64, game->p_i * 64);
		}
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_game game;

	if (ac != 2)
		ft_msgerror("Error\nInvalid number of arguments.\n", NULL);

	game.map = ft_check_map_file(av[1]);
	ft_window_size(&game);
	game.mlx = mlx_init();
	if (!game.mlx)
	{
		ft_free_map(game.map);
		ft_msgerror("Error\nerrormlx init\n", NULL);
	}
	game.win = mlx_new_window(game.mlx, game.width, game.height, "Game Si Samir");
	if (!game.win)
	{
		ft_free_map(game.map);
		ft_msgerror("Error\nerror mlw new window\n", NULL);
	}
	ft_load_textures(&game);
	
	if (!game.w_img)
	{
		ft_free_map(game.map);
		ft_msgerror("Error\nerror mlx xpm file to image\n", NULL);
	}
	ft_draw_map(&game);
	mlx_key_hook(game.win, ft_key_hook, &game);
	mlx_hook(game.win, 17, 0, ft_close_window, NULL);
	mlx_loop(game.mlx);
	ft_free_map(game.map);
	return (0);
}






















// int	ft_key_hook(int keycode, t_game *game)
// {
// 	printf("%d\n", keycode);
// 	if (keycode == 65361)
// 	{
// 		if (game->j > 0)
// 		{
// 			game->map[game->i][game->j] = '0';
// 			game->map[game->i][game->j - 1] = 'p';
// 		}
// 		ft_draw_map(game);
// 	}
// 	return (0);
// }

// int	main(int ac, char **av)
// {
// 	t_game game;

// 	if (ac != 2)
// 		ft_msgerror("Error\nInvalid number of arguments.\n", NULL);

// 	game.map = ft_check_map_file(av[1]);
// 	ft_window_size(&game);
// 	game.mlx = mlx_init();
// 	if (!game.mlx)
// 	{
// 		ft_free_map(game.map);
// 		ft_msgerror("Error\nerrormlx init\n", NULL);
// 	}
// 	game.win = mlx_new_window(game.mlx, game.width, game.height, "Game Si Samir");
// 	if (!game.win)
// 	{
// 		ft_free_map(game.map);
// 		ft_msgerror("Error\nerror mlw new window\n", NULL);
// 	}
// 	game.w_img = mlx_xpm_file_to_image(game.mlx, "textures/wall.xpm", &game.i, &game.j);
// 	game.f_img = mlx_xpm_file_to_image(game.mlx, "textures/floor.xpm", &game.i, &game.j);
// 	game.m_img = mlx_xpm_file_to_image(game.mlx, "textures/money.xpm", &game.i, &game.j);
// 	game.p_img = mlx_xpm_file_to_image(game.mlx, "textures/door_open.xpm", &game.i, &game.j);
// 	if (!game.w_img)
// 	{
// 		ft_free_map(game.map);
// 		ft_msgerror("Error\nerror mlx xpm file to image\n", NULL);
// 	}
// 	ft_draw_map(&game);
// 	while (1)
// 	{
// 		mlx_key_hook(game.win, ft_key_hook, &game);
// 	}
	
// 	mlx_hook(game.win, 17, 0, ft_close_window, NULL);
// 	mlx_loop(game.mlx);
// 	ft_free_map(game.map);
// 	return (0);
// }
