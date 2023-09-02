#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_stelen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *copy)
{
	int	i;
	int	len;
	char	*str;

	i = 0;
	len = ft_stelen(copy);
	str = (char *)malloc(sizeof(char) * (len + 1));
	while (copy[i])
	{
		str[i] = copy[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

struct s_stock_str *ft_strs_to_tab(int ac, char **av)
{
	int		i;
	t_stock_str	*point;

	i = 0;
	point = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (point == NULL)
		return (NULL);
	while (i < ac)
	{
		point[i].size = ft_stelen(av[i]);
		point[i].str = av[i];
		point[i].copy = ft_strdup(av[i]);
		if (point[i].copy == NULL)
		{
			while (i >= 0)
				free(point[i--].copy);
			free(point);
			return (NULL);
		}
		i++;
	}
	point[ac].str = 0;
	return (point);
}
