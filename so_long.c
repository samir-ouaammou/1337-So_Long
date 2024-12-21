#include "so_long.h"

typedef struct	s_game
{
	void	*mlx;
	void	*win;
	void	*player_img;
	void	*money_img;
	void	*floor_img;
	void	*wall_img;
	void	*door_img;
	char	**map;
	int		height;
	int		width;
	int		player_i;
	int		player_j;
	int		temp;
	int		i;
	int		j;
	int img_width;
	int img_height;
}	t_game;

int close_window(void)
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


int	main(int ac, char **av)
{
	t_game game;

	if (ac != 2)
		ft_msgerror("Error\nInvalid number of arguments.\n", NULL);

	game.map = ft_check_map_file(av[1]);
	ft_window_size(&game);
	game.mlx = mlx_init();


	game.wall_img = mlx_xpm_file_to_image(game.mlx, "./textures/wall.xpm", &game.i, &game.j);
	game.floor_img = mlx_xpm_file_to_image(game.mlx, "./textures/floor.xpm", &game.i, &game.j);
	game.door_img = mlx_xpm_file_to_image(game.mlx, "./textures/door_open.xpm", &game.i, &game.j);
	game.player_img = mlx_xpm_file_to_image(game.mlx, "./textures/player.xpm", &game.i, &game.j);
	game.money_img = mlx_xpm_file_to_image(game.mlx, "./textures/money.xpm", &game.i, &game.j);
	if (!game.wall_img || !game.floor_img)
		ft_msgerror("Error img\n", NULL);
	
	if (!game.mlx)
	{
		ft_free_map(game.map);
		ft_msgerror("Error\nFailed to initialize MiniLibX.\n", NULL);
	}
    game.win = mlx_new_window(game.mlx, game.width, game.height, "Samir Ouaammou");

	game.player_i = 0;
	while (game.map[game.player_i])
	{
		game.player_j = 0;
		while (game.map[game.player_i][game.player_j])
		{
			if (game.map[game.player_i][game.player_j] == '1')
				mlx_put_image_to_window(game.mlx, game.win, game.wall_img, (game.player_j * 64), (game.player_i * 64));
			else if (game.map[game.player_i][game.player_j] == '0')
				mlx_put_image_to_window(game.mlx, game.win, game.floor_img, (game.player_j * 64), (game.player_i * 64));
			else if (game.map[game.player_i][game.player_j] == 'E')
				mlx_put_image_to_window(game.mlx, game.win, game.door_img, (game.player_j * 64), (game.player_i * 64));
			else if (game.map[game.player_i][game.player_j] == 'P')
				mlx_put_image_to_window(game.mlx, game.win, game.player_img, (game.player_j * 64), (game.player_i * 64));
			else if (game.map[game.player_i][game.player_j] == 'C')
				mlx_put_image_to_window(game.mlx, game.win, game.money_img, (game.player_j * 64), (game.player_i * 64));


			game.player_j++;
		}
		game.player_i++;
	}


	mlx_hook(game.win, 17, 0, close_window, NULL);
	mlx_loop(game.mlx);

	return (0);
}
