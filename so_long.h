#ifndef SO_LONG_H
# define SO_LONG_H

#include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define BUFFER_SIZE 1

typedef struct s_map_checker
{
	int	floor;
	int	wall;
	int	money;
	int	door;
	int	player;
	char	**copy;
	char	**map;
	char	*line;
	char	*temp;
	char	*str;
	int	len;
	int	nbr;
	int	fd;
	int	i;
	int	j;
}	t_map_checker;

typedef struct	s_game
{
	void	*mlx;
	void	*win;
	void	*p_img;
	void	*m_img;
	void	*f_img;
	void	*w_img;
	void	*k_img;
	void	*d_c_img;
	void	*d_o_img;
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
	int		d_i;
	int		d_j;
	int		i;
	int		j;
}	t_game;

int	ft_close_window(void);
char	*get_next_line(int fd);
void	ft_free_map(char **temp);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *str);
void	ft_init_game(t_game *game);
void	ft_window_size(t_game *window);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *s, char c);
char	**ft_check_map_file(char *mapfile);
int		ft_strchr(const char *str, char c);
int		ft_key_hook(int keycode, t_game *game);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_free_and_exit(t_game *game, char *msg);
void	ft_msgerror(char *msg, t_map_checker *map);
void	ft_validate_map_elements(t_map_checker *map);
void	ft_checkmap(char *str, t_map_checker *map, char c);

#endif
