#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_bases(int check, char *base, char c)
{
	int	i;
	int	j;

	i = 0;
	if (check == 0)
	{
		while (base[i])
		{	
			j = i + 1;

			while (base[j])
				if (base[i] == '-' || base[i] == '+' || base[i] == base[j++])
					return (0);
			i++;
		}
	}
	else if (check == 1)
	{
		while (base[i])
		{
			if (c == base[i])
				return (i);
			i++;
		}
		return (-1);
	}
	return (1);
}

int	ft_atoi(char *str, char *base_f)
{
	int	i;
	int	sign;
	int	l_base;
	int	sum;

	i = 0;
	sign = 1;
	sum = 0;
	l_base = ft_strlen(base_f);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign *= -1;
	while (str[i] && check_bases(1, base_f, str[i]) != -1)
		sum = (sum * l_base) + (check_bases(1, base_f, str[i++]));
	return (sum * sign);
}

void	ft_putnbr_base(int nbr, char *base, char *dest)
{
	int	n;
	int	i;
	char	tmp;

	i = 0;
	n= nbr;
	if (nbr < 0)
		n = -n;
	while (n != 0)
	{
		dest[i++] = base[n % ft_strlen(base)];
		n = n / ft_strlen(base);
	}
	if (nbr < 0)
		dest[i++] = '-';
	dest[i] = '\0';
	n = 0;
	while (n < --i)
	{		
		tmp = dest[i];
		dest[i] = dest[n];
		dest[n++] = tmp;
	}	
}

char	*ft_convert_base(char *nbr, char *base_form, char *base_to)
{
	int	i;
	int	nb;
	char	*result;

	i = 0;
	if (nbr == NULL || base_to == NULL || base_form == NULL
		|| check_bases(0, base_form, '\0') == 0 
			||check_bases(0 ,base_to, '\0') == 0)
		return (NULL);
	nb = ft_atoi(nbr, base_form);
	if (nb < 0)
		i++;
	while (nb != 0)
	{
		nb = nb / ft_strlen(base_to);
		i++;
	}	
	if ((result = (char *)malloc(sizeof(char) * (i + 1))) == NULL )
		return (NULL);
	nb = ft_atoi(nbr, base_form);
	ft_putnbr_base(nb, base_to, result);
	result[i] = '\0';
	return (result);
}
///*
   int	main()
   {
   char *str;
   str = ft_convert_base("    ---+--bbb","ab","0123456789");
   printf("%s", str);
   free (str);
   }
// */

