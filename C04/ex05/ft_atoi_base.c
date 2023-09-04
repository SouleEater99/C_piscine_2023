#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return(i);
}

int	ft_check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(base) < 2)
		return (0);
	while (base[i])
	{
		j = i + 1;
		while (base[j])
			if (base[i] == base[j++])
				return (0);
		if (base[i] == '-' || base[i] == '+')
			return (0);
		i++;
	}
	return (1);
}

int	ft_get_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int ft_atoi_base(char *str, char *base)
{
	long	len;
	long	sign;
	long	sum;

	len = ft_strlen(base);
	sum = 0;
	sign = 1;

	if (ft_check_base(base) == 0 || *str == '\0' || *base == '\0')
		return (0);
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -sign;
	while (*str && ft_get_index(*str, base) != -1)
	{
		sum = (sum * len) + (ft_get_index(*str, base));
		str++;
	}
	return (sign * sum);
}
/*
int main()
{

	printf("%d", ft_atoi_base("---abc"  ,  "abcd));

}
*/
