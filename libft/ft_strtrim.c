/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 17:06:27 by ejang             #+#    #+#             */
/*   Updated: 2022/06/15 13:20:52 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*ptr;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	i = 0;
	while (in_set(s1[i++], set))
		start++;
	if (start == end)
		return (ft_strdup(""));
	i = ft_strlen(s1) - 1;
	while (in_set(s1[i--], set))
		end--;
	ptr = (char *)malloc(end - start + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, (char *)s1 + start, end - start + 1);
	return (ptr);
}
