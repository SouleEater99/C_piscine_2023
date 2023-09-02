#include <unistd.h>
#include "ft_stock_str.h"
#include <stdlib.h>


void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_putchar(char c)
{
	write(1,&c,1);
}

void	ft_putnbr(int nb)
{
	long n;

	n = nb;
	if (n < 0)
	{
		write(1,"-",1);
		n = -n;
	}
	if (n > 9)
		ft_putnbr(n/10);
	else
		ft_putchar(n % 10 + '0');
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		ft_putstr(par[i].str);
		ft_putchar('\n');
		ft_putnbr(par[i].size);
		ft_putchar('\n');
		ft_putstr(par[i].copy);
		ft_putchar('\n');
		i++;
	}
	while (i >= 0)
		free(par[i--].copy);
	free(par);
}
