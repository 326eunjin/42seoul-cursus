/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main_util_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 20:45:11 by ejang             #+#    #+#             */
/*   Updated: 2022/08/31 16:13:03 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"
#include "../libft/libft.h"
#include "../inc/get_next_line.h"

int	is_space_in_str(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == ' ')
			return (0);
	return (1);
}

char	*chop_space(char *str)
{
	char	*ret;
	int		front;
	int		back;
	int		i;

	i = -1;
	front = 0;
	back = ft_strlen(str) - 1;
	while (str[++i] == ' ')
		front++;
	while (str[back] == ' ')
		back--;
	ret = ft_strndup(str + front, back - front + 1);
	return (ret);
}

void	remove_new_line(char **line)
{
	unsigned int	len;
	char			*tmp;

	if (*line == NULL)
		return ;
	len = ft_strlen(*line);
	if ((*line)[len - 1] == '\n')
	{
		tmp = ft_strdup(*line);
		free(*line);
		(*line) = ft_substr(tmp, 0, len - 1);
		free(tmp);
	}
	return ;
}

int	is_nswe(char *first_element)
{
	if (!ft_strncmp(first_element, "NO", 2) \
		|| !ft_strncmp(first_element, "SO", 2) \
		|| !ft_strncmp(first_element, "WE", 2) \
		|| !ft_strncmp(first_element, "EA", 2))
		return (0);
	else
		return (1);
}
