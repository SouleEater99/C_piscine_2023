int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void ft_sort_string_tab(char **tab)
{
	int	i;
	int	j;
	int	size;
	char	*tmp;

	i = 0;
	size = 0;
	while (tab[size])
		size++;
	while (i < size - 1) 
	{
		j = i + 1;
		while (j < size)
		{
			if (ft_strcmp(tab[i],tab[j]) >= 0)
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}
