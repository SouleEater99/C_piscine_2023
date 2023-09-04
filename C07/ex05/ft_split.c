#include <stdlib.h>
#include <stdio.h>

int	ft_is_charset(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

char	*ft_skip_charset(char *str, char *charset)
{
	while (*str && ft_is_charset(*str, charset) == 1)
		str++;
	return (str);		
}

int	ft_word_count(char *str, char *charset)
{
	int	count;

	count = 0;
	if (ft_is_charset(*str, charset) == 0)
		count++;
	while (*str)
	{
		if (ft_is_charset(*str, charset))
		{
			str = ft_skip_charset(str, charset);
			if (ft_is_charset(*(str + 1), charset) == 0 && *(str + 1))
				count++;
		}
		str++;
	}
	return (count);
}

char	*ft_strdup(char *str, char *ptr)
{
	int	i;
	char	*dest;

	i = (ptr - str) + 0;
	dest = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str != ptr)
		dest[i++] = *str++;
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	int	i;
	char	*ptr;
	char	**res;

	str = ft_skip_charset(str, charset);
	i = ft_word_count(str, charset);
	res = (char **)malloc(sizeof(char *) * (i + 1));
	res[i] = NULL;
	i = 0;
	while (*str)
	{
		ptr = str;
		while (*ptr && ft_is_charset(*ptr, charset) == 0)
			ptr++;
		res[i++] = ft_strdup(str, ptr);
		str = ft_skip_charset(ptr, charset);
	}
	return (res);
}
/*
int	main()
{
	int	i = 0;
	char **a;
	a = ft_split("hello world ali", " ");
	while (a[i])
		printf("%s\n", a[i++]);
	while (0 <= i)
		free(a[i--]);
	free(a);
}
*/





