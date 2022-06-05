/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_pwd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:37:21 by ejang             #+#    #+#             */
/*   Updated: 2022/06/05 17:02:35 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	*fun_pwd(void)//현재 작업중인 절대경로 출력
{
	char *current_dir = getcwd(NULL, 0);
	if (current_dir == NULL)//리턴값이 null이니까 free할 필요가 없음.
	{
		printf("getcwd() cannot excute in fun_pwd\n");
		exit(1);
	}
	printf("%s\n",current_dir);
	free(current_dir);
}