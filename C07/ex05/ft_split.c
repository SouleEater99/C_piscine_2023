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

int	count_word_char(int check, char *str, char *charset)
{
	int	i;
	int	count;

	i = -1;
	count = 1;
	if (check == 0)
	{
		while (str[++i])
			if (check_charset(str[i], charset) == 1 && 
			check_charset(str[i + 1], charset) != 1 && str[i + 1])
				count++;
		return (count);
	}
	if (check == 1)
	{
		i = 0;
		while (str[i] && check_charset(str[i], charset) != 1)
			i++;
		return (i);
	}
	return (1);
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

char	*ft_allocate(char *str, char *charset, int *n)
{
	int	tmp;
	int	len;
	char	*result;

	len = *n;
	tmp = count_word_char(1, str + len, charset);
	result = (char *)malloc(sizeof(char) * (tmp + 1));
	if (result == NULL)
		return (NULL);
	*n = ft_strcpy(result, str + len, tmp) + len;
	result[tmp] = '\0';

	return (result);
}	

char	**ft_split(char *str, char *charset)
{
	int	i;
	int	len;
	int	size;
	char	**result;

	i = 0;
	len = 0;
	if (str == NULL || (str == NULL || charset == NULL))
		return (NULL);
	while (*str && check_charset(*str, charset) == 1)
		str++;
	size = 	count_word_char(0,str, charset);
	if ((result = (char **)malloc(sizeof(char *) * (size + 1))) == NULL)
		return (NULL);
	while (i < size)
	{
		while (check_charset(str[len], charset) == 1)
			len++;
		result[i++] = ft_allocate(str + len, charset, &len);
	}
	result[size] = NULL;
	return (result);
}
///*
   int	main()
   {
   char **str;
   int	i = 0;

   str = ft_split(",,hello,world,,", ",,");
   while (str[i])
   printf("%s \n", str[i++]);
   i = 0;
   while (str[i])
   {
   free(str[i++]);
   }
   free (str);
   }
 //*/

