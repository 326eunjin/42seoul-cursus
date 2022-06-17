/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:08:49 by ejang             #+#    #+#             */
/*   Updated: 2022/06/17 17:11:51 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	free_split(char **tmp)//ft_split으로 할당한거 해제하기 
{
	int	i;
	int	cnt;

	i = -1;
	cnt = 0;
	while(tmp[++i])
		cnt++;
	i = -1;
	while (++i < cnt)
		free(tmp[i]);
	free(tmp);
	tmp = NULL;
}

void	free_split_part(char **tmp, int idx)
{
	int i = 0;
	while(i<idx)
	{
		free(tmp[i]);
		tmp[i] = NULL;
		i++;
	}
	free(tmp);
	tmp = NULL;;
}