/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 22:51:08 by ejang             #+#    #+#             */
/*   Updated: 2021/04/09 03:09:33 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		len(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;

	i = 0;
	if (*to_find == 0)
		return (str);
	while (str[i] != '\0')
	{
		if (str[i] == to_find[0])
		{
			j = 0;
			while (to_find[j] != '\0')
			{
				if (str[i + j] != to_find[j])
					break ;
				j++;
			}
			if (j == len(to_find))
				return (str + i);
		}
		i++;
	}
	return (0);
}
