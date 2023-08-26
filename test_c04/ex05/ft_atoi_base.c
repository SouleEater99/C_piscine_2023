/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 08:16:25 by ael-maim          #+#    #+#             */
/*   Updated: 2023/08/26 13:59:15 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(int sign, char *str, char *base, char c)
{
	int	i;

	i = 0;
	if (sign == 0)
		while (str[i])
			i++;
	else if (sign == 1)
		while (str[i] && ft_strlen(2, str, base, str[i]))
			i++;
	else if (sign == 2)
	{
		while (base[i])
			if (base[i++] == c)
				return (1);
	}
	return (i);
}

int	ft_power(int n, int p)
{
	int	result;

	result = 1;
	if (p < 0)
		return (0);
	while (p > 0)
	{
		result *= n;
		p--;
	}
	return (result);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(0, base, base, '\n') < 2)
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

char	*ft_check_str(int *sign, char *str)
{
	int	count;

	count = 0;
	while (*str == '-' || *str == '+'
		|| *str == ' ' || (*str >= 9 && *str <= 13))
	{
		if (*str == '-')
			count = count + 1;
		str++;
	}
	if (count % 2 != 0)
		*sign = *sign * -1;
	return (str);
}

int	ft_atoi_base(char *str, char *base)
{
	long long	result;
	int			i;
	int			n[2];
	int			sign;
	int			j;

	result = 0;
	sign = 1;
	i = 0;
	n[0] = ft_strlen(0, base, base, '\0');
	if (check_base(base) == 0)
		return (0);
	str = ft_check_str(&sign, str);
	n[1] = ft_strlen(1, str, base, '\0') - 1;
	while ((str[i] || ft_strlen(2, str, base, str[i]) == 1) && n[1] >= 0)
	{
		j = 0;
		while (base[j] && base[j] != str[i])
			j++;
		result = result + (j * ft_power(n[0], n[1]));
		i++;
		n[1]--;
	}
	return (result * sign);
}
