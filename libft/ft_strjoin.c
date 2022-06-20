/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 17:06:29 by ejang             #+#    #+#             */
/*   Updated: 2022/06/20 17:04:04 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*temp;

	if (!s1 && !s2)
		return (NULL);
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && s2)
		return (ft_strdup(s2));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(temp = (char *)malloc(s1_len + s2_len + 1)))
		return (NULL);
	ft_strlcpy(temp, s1, s1_len + 1);
	ft_strlcat(temp, s2, s1_len + s2_len + 1);
	free(s1);
	free(s2);
	s1 = 0;
	s2 = 0;
	return (temp);
}
