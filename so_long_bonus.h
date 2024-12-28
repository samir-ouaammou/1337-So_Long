#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define BUFFER_SIZE 1

typedef struct s_map_checker
{
	int		floor;
	int		wall;
	int		money;
	int		door;
	int		enemy;
	int		player;
	char	**copy;
	char	**map;
	char	*line;
	char	*temp;
	char	*str;
	int		len;
	int		nbr;
	int		fd;
	int		i;
	int		j;
}			t_map_checker;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	char	*str;
	int		width;
	int		height;
	int		money;
	int		nbr;
	int		tmp;
	int		p_i;
	int		p_j;
	int		d_i;
	int		d_j;
	int		i;
	int		j;
	int		player_movement;
	int		player_animation_speed;
	int		enemy_animation_speed;
	int		money_animation_speed;
	int		door_animation_speed;
	int		keycode;
	int		player_animation_step;
	int		enemy_animation_step;
	int		money_animation_step;
	int		door_animation_step;
	void	*w_img;
	void	*f_img;
	void	*d_img;
	void	*p1_img;
	void	*p2_img;
	void	*p3_img;
	void	*m1_img;
	void	*m2_img;
	void	*m3_img;
	void	*m4_img;
	void	*e1_img;
	void	*e2_img;
	void	*e3_img;
	void	*e4_img;
	void	*e5_img;
	void	*e6_img;

}			t_game;

char		*ft_itoa(int n);
char		*get_next_line(int fd);
void		ft_free_map(char **temp);
size_t		ft_strlen(const char *str);
int			ft_close_game(t_game *data);
char		*ft_strdup(const char *str);
void		ft_free_image(t_game *game);
void		ft_read_to_img(t_game *game);
char		*ft_strjoin(char *s1, char *s2);
char		**ft_split(char const *s, char c);
char		**ft_check_map_file(char *mapfile);
int			ft_strchr(const char *str, char c);
char		*ft_strcat(char *dst, const char *src);
int			ft_key_hook(int keycode, t_game *game);
int			ft_file_put_img_to_window(t_game *game);
void		ft_free_and_exit(char **temp, char *msg);
int			ft_strcmp(const char *s1, const char *s2);
void		ft_msgerror(char *msg, t_map_checker *map);
void		ft_put_img_to_win(t_game *game, void *img);
void		ft_put_str_to_window(t_game *game, int nbr);
void		ft_validate_map_elements(t_map_checker *map);
void		ft_checkmap(char *str, t_map_checker *map, char c);

#endif
