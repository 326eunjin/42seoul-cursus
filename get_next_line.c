/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang < ejang@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 16:42:46 by ejang             #+#    #+#             */
/*   Updated: 2022/01/22 21:02:27 by ejang            ###   ########.fr       */
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

	(*backup)[line_loc] = '\0';
	if (!(ret = ft_strdup(*backup)))
	{
		free(*backup);//앞에 이남꺼 프리해야하지 않나
		*backup = 0;
		return (NULL);
	}
	if (!(tmp = ft_strdup(*backup + line_loc + 1)))
	{
		free(*backup);
		*backup = 0;
		return (NULL);
	}
	free(*backup);
	*backup = tmp;
	return (ret);//ret는 프리 안해줘도되나?
}

static	char	*rest(char **backup)
{
	int		cut;
	char	*ret;

	if (!(*backup))
		return (ft_strdup(""));
	else
	{
		if ((cut = is_new_line(*backup)) >= 0)
			return (split_line(cut,backup));
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
	while (((size = read(fd, tmp, BUFFER_SIZE)) > 0))
	{
		tmp[size] = '\0';
		backup[fd] = ft_strjoin(backup[fd], tmp);
		if ((line_loc = is_new_line(backup[fd])) >= 0)
			return (split_line(line_loc, &backup[fd]));
	}
	if (size < 0)
		return (NULL);
	return (rest(&backup[fd]));
}
//할당 해제 
//리턴값