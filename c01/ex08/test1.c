/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 13:49:27 by ael-maim          #+#    #+#             */
/*   Updated: 2023/08/20 14:51:42 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
void	ft_sort_int_tab(int *tab, int size)
{
	int		i;
	int		j;
	int		tmp;

	i = 0;
	while (i <= size / 2)
	{
		j = 0;
		while (j < size - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	main()
{
	int		i = 0;
	int		tab[] = {9,8,7,6,5,4,3,2,1,0};
	ft_sort_int_tab(tab,10);
	printf("_____________________\n|");
	while (i < 10)
		printf(" %d |",tab[i++]);
	printf("\n----------------------");
}
