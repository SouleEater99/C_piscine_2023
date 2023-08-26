/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 08:15:08 by ael-maim          #+#    #+#             */
/*   Updated: 2023/08/26 12:17:00 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int			i;
	int			sign;
	long long	count;

	i = 0;
	count = 0;
	sign = 1;
	while (str[i] == '-' || str[i] == '+'
		|| str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
	{
		if (str[i] == '-')
			count++;
		i++;
	}
	if (count % 2 != 0)
		sign = -sign;
	count = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		count = (count * 10) + (str[i] - '0');
		i++;
	}
	return (count * sign);
}
