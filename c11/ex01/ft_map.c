#include <stdlib.h>
#include <stdio.h>

int	ft_nb(int b)
{
	return (b * 10);
}

int *ft_map(int *tab, int length, int(*f)(int))
{
	int	i;
	int	*array;

	i = 0;
	array = malloc(sizeof(int) * length);
	while (i < length)
	{
		array[i] = f(tab[i]);
		i++;
	}
	return (array);
}



int	main()
{
	int *array;
	int tab[5] = {1,2,3,4,5};
	array = ft_map(tab, 5, &ft_nb);
	int i = 0;
	while (i < 5)	
		printf("%d\n",array[i++]);
}
