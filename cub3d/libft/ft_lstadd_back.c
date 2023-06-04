/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 19:26:56 by ejang             #+#    #+#             */
/*   Updated: 2022/06/15 13:18:17 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*end;

	if (!lst)
		return ;
	if (*lst == 0)
	{
		*lst = new;
		return ;
	}
	else
	{
		end = ft_lstlast(*lst);
		end->next = new;
	}
}
