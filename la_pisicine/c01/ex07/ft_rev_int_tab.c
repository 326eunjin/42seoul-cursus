/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 02:19:20 by ejang             #+#    #+#             */
/*   Updated: 2021/04/02 03:54:20 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int a[size];
	int i;
	int tmp;

	i = 0;
	while (i < size)
	{
		a[size - i - 1] = tab[i];
		i++;
	}
	i = 0;
	while (i < size)
	{
		tmp = tab[i];
		tab[i] = a[i];
		a[i] = tmp;
		i++;
	}
}
