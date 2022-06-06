/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 16:19:56 by jeyoon            #+#    #+#             */
/*   Updated: 2021/05/18 14:37:23 by jeyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_include(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*temp;
	size_t	len;
	char	*start;
	char	*end;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = (char *)s1;
	end = start + ft_strlen(s1) - 1;
	while (*start && is_include(*start, set))
		start++;
	if (*start == '\0')
		return (ft_strdup(""));
	while (*end && is_include(*end, set))
		end--;
	len = end - start + 1;
	if (!(temp = (char *)malloc(len + 1)))
		return (NULL);
	ft_strlcpy(temp, start, len + 1);
	return (temp);
}
