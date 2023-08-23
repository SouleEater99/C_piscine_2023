/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 13:14:59 by ael-maim          #+#    #+#             */
/*   Updated: 2023/08/22 11:06:35 by ael-maim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}

int	ft_alphanumeric(char c)
{
	if ((c < 'a' || c > 'z') && (c < '0' || c > '9'))
		return (0);
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	int		i;
	int		check;

	check = 1;
	i = 0;
	ft_strlowcase(str);
	while (str[i] != '\0')
	{
		if (ft_alphanumeric(str[i]) == 1)
		{
			if (check == 1 && (str[i] >= 'a' && str[i] <= 'z'))
			{	
				str[i] -= 32;
				check = 0;
			}
			else
				check = 0;
		}
		else
			check = 1;
		i++;
	}
	return (str);
}
