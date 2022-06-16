/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tolowerstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:30:38 by jeyoon            #+#    #+#             */
/*   Updated: 2022/06/16 18:48:17 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	tolower_str(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		str[idx] = ft_tolower(str[idx]);
		idx++;
	}
}

char	*get_lower_str(char *str)
{
	int		idx;
	int		len;
	char	*ret;

	len = ft_strlen(str);
	if (len == 0)
		return (ft_strdup(""));
	ret = ft_strdup(str);
	if (ret == 0)
		return (0);
	tolower_str(ret);
	return (ret);
}
