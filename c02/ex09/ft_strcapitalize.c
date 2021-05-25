/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 12:18:11 by ejang             #+#    #+#             */
/*   Updated: 2021/04/07 05:47:46 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_alpha(char ch)
{
	if (((ch >= 'A') && (ch <= 'Z'))
				| ((ch >= 'a') && (ch <= 'z')))
		return (1);
	else if ((ch >= '0') && (ch <= '9'))
		return (2);
	else
		return (0);
}

char	chg_ifuppercase(char ch)
{
	if ((ch >= 'A') && (ch <= 'Z'))
		ch = ch + 32;
	return (ch);
}

char	chg_iflowercase(char ch)
{
	if ((ch >= 'a') && (ch <= 'z'))
		ch = ch - 32;
	return (ch);
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	if (is_alpha(str[0]) == 1)
		str[0] = chg_iflowercase(str[0]);
	while (str[i] != '\0')
	{
		if ((is_alpha(str[i]) == 0) && (is_alpha(str[i + 1]) == 1))
			str[i + 1] = chg_iflowercase(str[i + 1]);
		if ((is_alpha(str[i - 1]) != 0) && (is_alpha(str[i]) == 1))
			str[i] = chg_ifuppercase(str[i]);
		i++;
	}
	return (str);
}
