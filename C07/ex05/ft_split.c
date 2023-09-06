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
	if (c == '\0')
		return (1);
	return (0);
}

int	ft_word_count(char *str, char *charset)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_is_charset(str[i + 1], charset) == 1
				&& ft_is_charset(str[i], charset) == 0)
			words++;
		i++;
	}
	return (words);
}

void	ft_strcpy(char *dest, char *from, char *charset)
{
	int	i;

	i = 0;
	while (ft_is_charset(from[i], charset) == 0)
	{
		dest[i] = from[i];
		i++;
	}
	dest[i] = '\0';
}

void	ft_strdup(char **result, char *str, char *charset)
{
	int		i;
	int		j;
	int		word;

	word = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_is_charset(str[i], charset) == 1)
			i++;
		else
		{
			j = 0;
			while (ft_is_charset(str[i + j], charset) == 0)
				j++;
			result[word] = (char*)malloc(sizeof(char) * (j + 1));
			ft_strcpy(result[word], str + i, charset);
			i += j;
			word++;
		}
	}
}


char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		words;

	if (!str && !charset)
		return (NULL);
	words = ft_word_count(str, charset);
	result = (char**)malloc(sizeof(char*) * (words + 1));
	result[words] = 0;
	ft_strdup(result, str, charset);
	return (result);
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
