/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 16:19:18 by jeyoon            #+#    #+#             */
/*   Updated: 2021/05/18 01:39:44 by jeyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_min(unsigned int a, unsigned int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

char				*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	slen;
	char			*temp;

	if (!s)
		return (NULL);
	slen = (unsigned int)ft_strlen(s);
	if (slen <= start || len == 0)
		return (ft_strdup(""));
	i = 0;
	if (!(temp = (char *)malloc(ft_min((unsigned int)len, slen - start) + 1)))
		return (NULL);
	while (s[start] != '\0' && i < len)
		temp[i++] = s[start++];
	temp[i] = '\0';
	return (temp);
}
