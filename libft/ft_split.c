/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 16:20:15 by jeyoon            #+#    #+#             */
/*   Updated: 2021/05/18 15:01:03 by jeyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_cnt_strs(char const *s, char c)
{
	int		i;
	int		cnt_strs;

	i = 0;
	cnt_strs = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			cnt_strs++;
			while (s[i] && (s[i] != c))
				i++;
		}
		else
			i++;
	}
	return (cnt_strs);
}

static int	get_str(char **str, int str_len, char c)
{
	int		len;

	len = 0;
	*str += str_len;
	while (**str && **str == c)
		(*str)++;
	while ((*str)[len])
	{
		if ((*str)[len] == c)
			break ;
		len++;
	}
	return (len);
}

static char	**all_free(char **result)
{
	int		i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		result[i] = NULL;
		i++;
	}
	free(result);
	result = NULL;
	return (NULL);
}

char		**ft_split(char const *s, char c)
{
	int		cnt_strs;
	char	**result;
	int		i;
	char	*str;
	int		str_len;

	if (!s)
		return (NULL);
	cnt_strs = get_cnt_strs(s, c);
	if (!(result = (char **)malloc(sizeof(char *) * (cnt_strs + 1))))
		return (NULL);
	i = 0;
	str = (char *)s;
	str_len = 0;
	while (i < cnt_strs)
	{
		str_len = get_str(&str, str_len, c);
		if (!(result[i] = (char *)malloc(str_len + 1)))
			return (all_free(result));
		ft_strlcpy(result[i], str, str_len + 1);
		i++;
	}
	result[i] = 0;
	return (result);
}
