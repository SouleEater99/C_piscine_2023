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
			if (ft_is_charset(*str, charset) == 0 && *str)
				count++;
		}
		str++;
	}
	return (count);
}

char	*ft_strdup(char *str, char *ptr,char **res, int index)
{
	int	i;
	char	*dest;

	i = (ptr - str) + 0;
	dest = (char *)malloc(sizeof(char) * (i + 1));
	if (dest == NULL)
	{
		while (index >= 0)
			free(res[index--]);
		free(res);
		return (NULL);
	}
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

	if (str == NULL || charset == NULL) 
		return (NULL);
	str = ft_skip_charset(str, charset);
	i = ft_word_count(str, charset);
	res = (char **)malloc(sizeof(char *) * (i + 1));
	if (res == NULL)
		return (NULL);
	res[i] = NULL;
	i = 0;
	while (*str)
	{
		ptr = str;
		while (*ptr && ft_is_charset(*ptr, charset) == 0)
			ptr++;
		res[i] = ft_strdup(str, ptr,res,i);
		str = ft_skip_charset(ptr, charset);
		i++;
	}
	return (res);
}

/*

   int	main(void)
   {
   char **str;
   int	i = 0;

   str = ft_split(NULL, NULL);
   while (str[i])
   printf("%s \n", str[i++]);
   i = 0;
   while (str[i])
   {
   free(str[i++]);
   }
   free (str);
   }
int main() {
	// Test 1: Empty Input String
	char *empty_input = ""; // Empty input string
	char *base = " ,"; // Separator characters
	char **result = ft_split(empty_input, base);
		// Test 3: Null Pointers
	char *null_input = NULL; // Null input pointer
	char *null_charset = NULL; // Null charset pointer
	result = ft_split(null_input, null_charset);
	if (result != NULL && result[0] == NULL) {
		printf("Test 3: Passed (Null Pointers)\n");
	} else {
		printf("Test 3: Failed (Null Pointers)\n");
	}
	free(result);
	return 0;
}

*/



