#include "so_long_bonus.h"

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		temp;

	len = 0;
	temp = n;
	if (n == 0)
		return ("0");
	while (temp != 0)
	{
		len++;
		temp /= 10;
	}
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (n != 0)
	{
		str[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

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
