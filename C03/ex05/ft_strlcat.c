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
	unsigned int	len_src;
	unsigned int	len_dest;
	unsigned int	res;

	len_src = ft_strlen(src);
	len_dest = ft_strlen(dest);
	res = 0;
	i = 0;
	if (size > len_dest)
		res = len_src + len_dest;
	else
		res = len_src + size;
	while (src[i] && (len_dest + 1) < size)
	{
		dest[len_dest] = src[i];
		len_dest++;
		i++;
	}
	dest[len_dest] = '\0';
	return (res);
}
