#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_count(char **strs, int size)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while(i < size)
	{
		count = count + ft_strlen(strs[i++]);
	}
	return (count);
}

void	ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
}

char *ft_strjoin(int size, char **strs, char *sep)
{
	int	i;
	int	count;
	char	*dest;

	i = 0;
	if (size == 0 || strs == NULL || sep == NULL)
		return (NULL);
	count = ft_count(strs, size) + (ft_strlen(sep) * (size - 1));
	dest = (char *)malloc(sizeof(char) * (count + 1));
	if (dest == NULL)
		return (NULL);
	dest[0] = '\0';
	while (i < size)
	{
		ft_strcat(dest, strs[i++]);
		if (i != size && size > 1)
			ft_strcat(dest, sep);

	}
	return (dest);
}
/*
#include <stdio.h>
int	main()
{
	char *a[] = {""};
	char *b;
	b = ft_strjoin(0,a,",");
	printf("%s", b);
	free(b);
}
*/
