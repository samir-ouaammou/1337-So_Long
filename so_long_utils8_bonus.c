#include "so_long_bonus.h"

void	ft_msgerror(char *msg, t_map_checker *map)
{
	if (map != NULL)
	{
		if (map->str)
			free(map->str);
		if (map->line)
			free(map->line);
		if (map->map)
			ft_free_map(map->map);
		if (map->copy)
			ft_free_map(map->copy);
	}
	write(2, msg, ft_strlen(msg));
	exit(-1);
}

void	ft_free_and_exit(char **temp, char *msg)
{
	if (temp)
	{
		while (*temp)
		{
			free(*temp);
			temp++;
		}
		free(temp);
	}
	write(2, msg, ft_strlen(msg));
	exit(-1);
}

void	ft_free_image(t_game *game)
{
	mlx_destroy_image(game->mlx, game->w_img);
	mlx_destroy_image(game->mlx, game->f_img);
	mlx_destroy_image(game->mlx, game->d_img);
	mlx_destroy_image(game->mlx, game->p1_img);
	mlx_destroy_image(game->mlx, game->p2_img);
	mlx_destroy_image(game->mlx, game->p3_img);
	mlx_destroy_image(game->mlx, game->m1_img);
	mlx_destroy_image(game->mlx, game->m2_img);
	mlx_destroy_image(game->mlx, game->m3_img);
	mlx_destroy_image(game->mlx, game->m4_img);
	mlx_destroy_image(game->mlx, game->e1_img);
	mlx_destroy_image(game->mlx, game->e2_img);
	mlx_destroy_image(game->mlx, game->e3_img);
	mlx_destroy_image(game->mlx, game->e4_img);
	mlx_destroy_image(game->mlx, game->e5_img);
	mlx_destroy_image(game->mlx, game->e6_img);
}

int	ft_close_game(t_game *game)
{
	ft_free_image(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	game->i = 0;
	while (game->i < game->height)
		free(game->map[game->i++]);
	free(game->map);
	exit(0);
	return (0);
}
