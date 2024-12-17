#include "so_long.h"

size_t	ft_strlen(const char *str)
{
	size_t	l;

	if (!str)
		return (0);
	l = 0;
	while (str[l])
		l++;
	return (l);
}

char	*ft_strdup(const char *str)
{
	size_t	i;
	char	*res;

	res = (char *)malloc(sizeof(char) + (ft_strlen(str) + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int	ft_strchr(const char *str, char c)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_strcat(char *dst, const char *src)
{
	size_t	i;
	size_t	d_len;

	if (!dst || !src)
		return (NULL);
	d_len = ft_strlen(dst);
	i = 0;
	while (src[i])
	{
		dst[d_len + i] = src[i];
		i++;
	}
	dst[d_len + i] = '\0';
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	result = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!result)
		return (NULL);
	result[0] = '\0';
	ft_strcat(result, s1);
	ft_strcat(result, s2);
	free(s1);
	s1 = NULL;
	return (result);
}
