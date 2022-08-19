/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 20:05:33 by ejang             #+#    #+#             */
/*   Updated: 2022/08/19 21:41:41 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include <stdlib.h>
#include <stdio.h>

void	free_split(char **tmp)
{
	int	i;
	int	cnt;

	i = -1;
	cnt = 0;
	while (tmp[++i])
		cnt++;
	i = -1;
	while (++i < cnt)
		free(tmp[i]);
	free(tmp);
	tmp = NULL;
}

void	print_error(char *msg)
{
	printf("%s", "Error\n");
	printf("%s\n", msg);
	exit(1);
}