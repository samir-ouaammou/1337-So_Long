#include "so_long.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	if (!s1 || !s2)
		return (-1);
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_free_map(char **temp)
{
	int	i;

	i = 0;
	if (temp != NULL)
	{
		while (temp[i])
		{
			free(temp[i]);
			i++;
		}
		free(temp);
	}
}

void	ft_msgerror(char *msg, t_map_checker *map)
{
	free(map->str);
	free(map->line);
	ft_free_map(map->map);
	ft_free_map(map->copy);
	write(2, msg, ft_strlen(msg));
	exit(-1);
}
