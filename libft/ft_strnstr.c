/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 11:44:31 by jeyoon            #+#    #+#             */
/*   Updated: 2021/05/14 19:06:15 by jeyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_str(char *str, char *substr)
{
	while (*substr)
	{
		if (*str != *substr)
			return (0);
		str++;
		substr++;
	}
	return (1);
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;
	size_t	i;
	size_t	haystack_len;

	if (*needle == '\0')
		return ((char *)haystack);
	haystack_len = ft_strlen(haystack);
	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return ((char *)haystack);
	if (len == 0)
		return (0);
	i = 0;
	while (i < haystack_len && i <= (len - ft_strlen(needle)))
	{
		if (find_str((char*)haystack + i, (char*)needle))
			return ((char*)haystack + i);
		i++;
	}
	return (NULL);
}
