#include <stdio.h>

int	ft_str_in_base(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i])
		if (base[i++] == c)
			return (1);
	return (0);
}

int	ft_strlen(int sign, char *str, char *base)
{
	int	i;

	i = 0;
	if (sign == 0)
		while (str[i])
			i++;
	else if (sign == 1)
	{
		while (str[i] && ft_str_in_base(base, str[i]))
		{
			i++;
		}
	}
	return (i);
}

int	ft_power(int n, int p)
{
	int	result;

	result = 1;
	if (p < 0)
		return (0);
	while (p > 0)
	{
		result *= n;
		p--;
	}
	return (result);
}


int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(0,base,base) < 2)
		return (0);
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '-' || base[i] == '+')
			return (0);
		while (base[j])
			if (base[i] == base[j++])
				return (0);
		i++;
	}
	return (1);
}



char	*ft_check_str(int *sign, char *str)
{
	int	count;
	
	count = 0;
	while (*str == '-' || *str == '+' 
			|| *str == ' ' || (*str >= 9 && *str <= 13))
	{
		if (*str == '-')
			count = count + 1;
		str++;
	}
	if (count % 2 != 0)
		*sign = *sign * -1;
	
	return (str);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	n_base;
	int	sign;
	long long	result;
	int	n_str;
	int	j;

	result = 0;
	sign = 1;
	i = 0;
	n_base = ft_strlen(0,base,base);
	if (check_base(base) == 0)
		return (0);
	str = ft_check_str(&sign, str);
	n_str = ft_strlen(1,str,base) - 1;
	//printf("str : %c \n",*str);
	while ((str[i] || ft_str_in_base(base, str[i]) == 1) && n_str >= 0)
	{
		j = 0;
		while (base[j] && base[j] != str[i])
			j++;
		result = result + (j * ft_power(n_base, n_str));
		i++;
		n_str--;
	}
	//printf("result : %d\nn_base : %d\nn_str:%d\nsign:%d\n",result,n_base,n_str,sign);
	return (result * sign);
}
/*
int main()
{
	char a[] = "-21474848";
	char b[] = "0123456789";
	int d;
	d = ft_atoi_base(a,b);
	printf("%d \n",d);
}
*/
