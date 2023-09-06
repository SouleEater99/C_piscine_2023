#include "ft.h"

int	ft_check_opera(char op, char *opera)
{
	int	i;

	i = 0;
	while (opera[i])
	{
		if (op == opera[i++])
			return (i);
	}
	return (-1);
}

int	ft_check_error(char *op, int n2, char *opera)
{
	if (ft_check_opera(op[0], opera) == -1)
	{
		ft_putstr("0\n");
		return (0);
	}
	if (n2 == 0 && op[0] == opera[2])
	{
		ft_putstr("Stop : division by zero\n");
		return (0);
	}
	if (opera[4] == op[0] && n2 == 0)
	{
		ft_putstr("Stop : modulo by zero\n");
		return (0);
	}
	return (1);
}

int	ft_do_op(int n1, char *op, int n2)
{
	int	tmp;
	char	*opera;
	int	(*tab[5])(int, int) = {add, sub, div, mul, mod};

	opera = "+-/*%";
	tmp = ft_check_opera(op[0], opera) - 1;
	if (ft_check_error(op, n2, opera) != 1)
		return (0);
	ft_putnbr(tab[tmp](n1,n2));
	ft_putchar('\n');
	return (1);
}
