/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 20:50:46 by jeyoon            #+#    #+#             */
/*   Updated: 2022/08/19 20:54:05 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"
#include "../libft/libft.h"

char	*ft_strndup(char *str, int n)
{
	char	*new_string;
	int		i;

	i = 0;
	new_string = (char *)malloc(n + 1);
	if (!new_string)
		return (NULL);
	while (i < n)
	{
		new_string[i] = str[i];
		i++;
	}
	new_string[n] = '\0';
	return (new_string);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	int		s1_len;
	int		s2_len;
	char	*temp;

	if (!s1 && !s2)
		return (NULL);
	if (s1 && !s2)
		return (ft_strndup(s1, ft_strlen(s1)));
	if (!s1 && s2)
		return (ft_strndup(s2, ft_strlen(s2)));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	temp = (char *)malloc(s1_len + s2_len + 1);
	if (!temp)
		return (NULL);
	ft_strlcpy(temp, s1, s1_len + 1);
	ft_strlcpy(temp + s1_len, s2, s2_len + 1);
	free(s1);
	s1 = 0;
	return (temp);
}