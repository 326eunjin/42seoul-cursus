/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang < ejang@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 16:42:46 by ejang             #+#    #+#             */
/*   Updated: 2022/01/28 12:37:33 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int	is_new_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static	char	*split_line(int line_loc, char **backup)
{
	char	*ret;
	char	*tmp;

	tmp = NULL;
	if (ft_strlen(*backup + line_loc + 1) > 0)
	{
		tmp = ft_strdup(*backup + line_loc + 1);
		if (!tmp)
		{
			free(*backup);
			*backup = 0;
			return (NULL);
		}
	}
	(*backup)[line_loc + 1] = '\0';
	ret = ft_strdup(*backup);
	if (!ret)
	{
		free(*backup);
		*backup = 0;
		return (NULL);
	}
	free(*backup);
	*backup = tmp;
	return (ret);
}

static	char	*rest(char **backup)
{
	int		cut;
	char	*ret;

	if (!(*backup))
		return (NULL);
	else
	{
		cut = is_new_line(*backup);
		if (cut >= 0)
			return (split_line(cut, backup));
		ret = ft_strdup(*backup);
		free(*backup);
		*backup = 0;
		return (ret);
	}
}

char	*get_next_line(int fd)
{
	static char	*backup[OPEN_MAX];
	char		tmp[BUFFER_SIZE + 1];
	int			size;
	int			line_loc;

	if ((fd < 0) || (fd > OPEN_MAX) || (BUFFER_SIZE <= 0))
		return (NULL);
	size = read(fd, tmp, BUFFER_SIZE);
	while (size > 0)
	{
		tmp[size] = '\0';
		backup[fd] = ft_strjoin(backup[fd], tmp);
		line_loc = is_new_line(backup[fd]);
		if (line_loc >= 0)
			return (split_line(line_loc, &backup[fd]));
		size = read(fd, tmp, BUFFER_SIZE);
	}
	if (size < 0)
		return (NULL);
	return (rest(&backup[fd]));
}
