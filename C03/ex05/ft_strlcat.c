int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = ft_strlen(src) + ft_strlen(dest);
	if (j > size - 1)
		return (size);
	j = ft_strlen(dest);
	while (src[i] && i < size - 1)
		dest[j++] = src[i++];
	dest[j] = '\0';
	return (ft_strlen(dest));
}
