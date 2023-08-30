#include <stdlib.h>

int ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	size;

	size = max- min;
	i = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = (int *)malloc(sizeof(int) * size);
	if (*range == NULL)
		return (-1);
	while(min < max)
		(*range)[i++] = min++;
	return (size);
}
