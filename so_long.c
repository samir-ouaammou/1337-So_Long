#include "so_long.h"

int	main(int ac, char **av)
{
	char	**map;

	if (ac != 2)
		ft_msgerror("Error\nInvalid number of arguments.\n", NULL);
	map = ft_check_map_file(av[1]);
	return (0);
}
