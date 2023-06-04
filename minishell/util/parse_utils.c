/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 23:35:49 by jeyoon            #+#    #+#             */
/*   Updated: 2022/06/25 23:57:24 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*char_to_string(char c)
{
	char	*ret;

	ret = (char *)malloc(sizeof(char) * 2);
	if (ret == NULL)
		exit(1);
	ret[0] = c;
	ret[1] = '\0';
	return (ret);
}

int	is_white_space(char c)
{
	if (c == ' ' || c >= 9 && c <= 13)
		return (TRUE);
	return (FALSE);
}
