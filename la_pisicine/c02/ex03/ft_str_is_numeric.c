/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 11:54:28 by ejang             #+#    #+#             */
/*   Updated: 2021/04/06 11:56:22 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!((str[i] >= '0') && (str[i] <= '9')))
			return (0);
		else
			i++;
	}
	return (1);
}
