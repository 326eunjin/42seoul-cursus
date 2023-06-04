/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 21:26:41 by ejang             #+#    #+#             */
/*   Updated: 2022/06/15 13:18:08 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_make(int len, char *ptr, long long tmp)
{
	while (len)
	{
		ptr[len] = tmp % 10 + '0';
		tmp = tmp / 10;
		len--;
	}
}

static	int	get_len(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int				len;
	char			*ptr;
	long long		tmp;

	len = get_len(n);
	ptr = (char *)malloc(len + 1);
	if (!ptr)
		return (NULL);
	ptr[len] = 0;
	if (n < 0)
	{
		tmp = (long long)n * -1;
		ptr[0] = '-';
		len = len - 1;
		ft_make(len, ptr, tmp);
	}
	else
	{
		while (len--)
		{
			ptr[len] = n % 10 + '0';
			n = n / 10;
		}
	}
	return (ptr);
}
