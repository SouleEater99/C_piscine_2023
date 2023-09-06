#include "ft.h"

void	ft_putchar(char c)
{
	write(1,&c ,1);
}

void	ft_putnbr(int nb)
{
	long long nbr;

	nbr  = nb;
	if (nbr < 0)
	{
		nbr = -nbr;
		ft_putchar('-');
	}
	if (nbr < 10)
	{
		ft_putchar(nbr + '0');
	}
	else
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}
