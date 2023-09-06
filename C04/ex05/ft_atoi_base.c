#include <stdio.h>

int	ft_check_base(char *base)
{

	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = 0;
		while (base[j])
		{
			if (base[i] == base[j] && i != j)
				return (0);
			j++;
		}
		if (base[i] == ' ' || base[i] == '-' || base[i] == '+' 
			|| (base[i] >= 9 && base[i] <= 13))
				return (0);
		i++;
	}
	return (i);

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

	sum = 0;
	sign = 1;
	len = ft_check_base(base);
	if (len >= 2)
	{
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
	}
	return (sign * sum);
}
/*
#include <stdio.h>
   int main()
   {

   printf("%d", ft_atoi_base("  \n --1o3o --","0123456o89"));

   }
 */
