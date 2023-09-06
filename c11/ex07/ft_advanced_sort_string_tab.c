void ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *, char *))
{
	int	i;
	int	size;
	int	j;
	char	*tmp;

	i = -1;
	size = 0;
	while (tab[size])
		size++;
	while (++i < size - 1)
	{	
		j = i;
		while (++j < size)
		{
			if (cmp(tab[i],tab[j]) > 1)
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
		}
	}
}
