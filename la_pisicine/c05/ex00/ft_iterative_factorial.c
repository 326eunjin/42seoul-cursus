/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 20:44:30 by ejang             #+#    #+#             */
/*   Updated: 2021/04/11 22:16:42 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int result;
	int i;

	i = 1;
	result = 1;
	if (0 <= nb)
	{
		while (i <= nb)
		{
			if (nb == 0)
			{
				i = 1;
				break ;
			}
			else
			{
				result = i * result;
				i++;
			}
		}
		return (result);
	}
	return (0);
}
