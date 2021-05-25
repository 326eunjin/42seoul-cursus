/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 15:55:14 by ejang             #+#    #+#             */
/*   Updated: 2021/04/13 17:29:56 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		in_base(char ch, char *base)
{
	int i;

	i = 0;
	while (base[i] != '\0')
	{
		if (ch == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int		len(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		check_valid(char *str)
{
	int i;
	int j;

	if (len(str) < 2)
		return (0);
	while (*str != '\0')
	{
		if (*str == '+' || *str == '-' ||
				((9 <= *str && *str <= 13) || (*str == 32)))
			return (0);
		str++;
	}
	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (j < i)
		{
			if (str[j] == str[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_atoi_base(char *str, char *base)
{
	int neg;
	int nbr;

	nbr = 0;
	neg = 1;
	if (check_valid(base))
	{
		while ((9 <= *str && *str <= 13) || (*str == 32))
			str++;
		while ((*str == '-') || (*str == '+'))
		{
			if (*str == '-')
				neg = neg * (-1);
			str++;
		}
		while (in_base(*str, base) != -1)
		{
			nbr = nbr * len(base) + in_base(*str, base);
			str++;
		}
		return (nbr * neg);
	}
	return (nbr);
}
