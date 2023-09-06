#include "ft.h"

int	main(int ac, char **av)
{
	int	n1;
	int	n2;

	if (ac == 4)
	{
		n1 = ft_atoi(av[1]);
		n2 = ft_atoi(av[3]);
		ft_do_op(n1,av[2],n2);
	}
}
