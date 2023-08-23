/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_ft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 14:34:07 by ael-maim          #+#    #+#             */
/*   Updated: 2023/08/19 15:45:13 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void ft_ultimate_ft(int *********nbr)
{
	*********nbr = 42;
}

int main()
{
	int a = 24;
	printf("value of a: %d", a);
	printf(" \naddress mem a: %p\n\n", &a);
	int	*nbr1 = &a;
	printf("value of nbr1: %d", *nbr1);
	printf(" \naddress mem 1: %p\n", nbr1);
	printf("where alocate in memory 1: %p\n \n", &nbr1);
	int	**nbr2 = &nbr1;
	printf("value of nbr2: %d", **nbr2);
	printf(" \naddress mem 2: %p\n", nbr2);
	printf("where alocate in memory 2: %p\n \n", &nbr2);
	int	***nbr3 = &nbr2;
	printf("value of nbr3: %d", ***nbr3);
	printf(" \naddress mem 3: %p\n", nbr3);
	printf("where alocate in memory 3: %p \n\n", &nbr3);
	int	****nbr4 = &nbr3;
	printf("value of nbr4: %d", ****nbr4);
	printf(" \naddress mem 4: %p\n", nbr4);
	printf("where alocate in memory 4: %p\n \n", &nbr4);
	int	*****nbr5 = &nbr4;
	printf("value of nbr5: %d", *****nbr5);
	printf(" \naddress mem 5: %p\n", nbr5);
	printf("where alocate in memory 5: %p \n\n", &nbr5);
	int	******nbr6 = &nbr5;
	printf("value of nbr6: %d", ******nbr6);
	printf(" \naddress mem 6: %p\n", nbr6);
	printf("where alocate in memory 6: %p\n \n", &nbr6);
	int	*******nbr7 = &nbr6;
	printf("value of nbr7: %d", *******nbr7);
	printf(" \naddress mem 7: %p\n", nbr7);
	printf("where alocate in memory 7: %p\n \n", &nbr7);
	int	********nbr8 = &nbr7;
	printf("value of nbr8: %d", ********nbr8);
	printf(" \naddress mem 8: %p\n", nbr8);
	printf("where alocate in memory 8: %p\n \n", &nbr8);
	int *********nbr9 = &nbr8;
	printf("value of nbr9: %d", *********nbr9);
	printf("   \naddress mem 9: %p\n", nbr9);
	printf("where alocate in memory 9: %p\n \n", &nbr9);

	ft_ultimate_ft(nbr9);
	printf("new value of a: %d\n\n",a);
	printf(" \naddress mem of a: %p\n\n", &a);
}
