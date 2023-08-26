#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c,1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(base) < 2)
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

void ft_putnbr_base(int nbr, char *base)
{
	long long	n;
	int	n_base;

	n = nbr;
	n_base = ft_strlen(base);
	if (check_base(base) == 1)
	{
		if (n < 0)
		{
			ft_putchar('-');
			n = -n;
		}
		if (n < n_base)
			ft_putchar(base[n]);
		else
		{
			ft_putnbr_base(n / n_base,base);
			ft_putnbr_base(n % n_base,base);
		}
	}
}
