#include "so_long.h"

int	main(int ac, char **av)
{
	char	**str;
	int		i;

	if (ac != 2)
		ft_msgerror("Error\nInvalid number of arguments.\n", NULL);
	(void)ac;
	str = ft_check_map_file(av[1]);
	i = 0;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
	}
	free(str);
	str = NULL;
	return (0);
}
