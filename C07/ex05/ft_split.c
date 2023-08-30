#include <stdlib.h>
#include <stdio.h>

int	check_charset(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
		if (c == str[i++])
			return (1);
	return (0);
}

int	count_word(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (str[i])
	{
		if (check_charset(str[i], charset) == 1 
				&& check_charset(str[i + 1], charset) != 1
				&& str[i + 1])
			count++;
		i++;
	}
	return (count);
}


int	ft_strlen(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && check_charset(str[i], charset) != 1)
		i++;
	return (i);
}

int	ft_strcpy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (i);
}

char	**ft_split(char *str, char *charset)
{
	int	i;
	int	size;
	int	len;
	int	tmp;
	char	**result;

	i = 0;
	len = 0;
	if (str == NULL)
		return (NULL);
	while (*str && check_charset(*str, charset) == 1)
		str++;
	size = 	count_word(str, charset);
	if ((result = (char **)malloc(sizeof(char *) * (size + 1))) == NULL)
		return (NULL);
	while (i < size)
	{
		while (check_charset(str[len], charset) == 1)
			len++;
		tmp =  ft_strlen(str + len,charset);
		result[i] = (char *)malloc(sizeof(char) * (tmp + 1));
		if (result[i] == NULL)
			return (NULL);
		len = ft_strcpy(result[i++], str + len, tmp) + len;
	}
	result[size] = NULL;
	return (result);
}
/*
int	main()
{
	char **str;
	int	i = 0;

	str = ft_split("wor,,", ",");
	while (str[i])
		printf("%s \n", str[i++]);
	i = 0;
	while (str[i])
	{
		free(str[i++]);
	}
	free (str);
}
*/

