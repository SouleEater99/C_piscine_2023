int	ft_any(char **tab, int (*f)(char*))
{
	int	i;

	i = 0;
	if (tab == NULL || f == NULL)
		return (0);
	while (tab[i])
		if (f(tab[i++]) != 0)
			return (1);
	return (0);
}
