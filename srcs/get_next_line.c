/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: jeyoon <jeyoon@student.42seoul.kr>		 +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/10/17 13:07:02 by jeyoon			#+#	#+#			 */
/*   Updated: 2021/10/28 16:11:23 by jeyoon           ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "get_next_line.h"

char	*mem_free(char	**backup, char **buffer)
{
	if (backup != NULL)
	{
		free(*backup);
		*backup = 0;
	}
	if (buffer != NULL)
	{
		free(*buffer);
		*buffer = 0;
	}
	return (NULL);
}

int	is_newline(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		if (str[idx] == '\n')
			return (idx);
		idx++;
	}
	return (-1);
}

char	*cut_line(char **backup, char **buffer, int cut_idx)
{
	char	*new_backup;
	int		idx;
	char	*result;

	if (cut_idx == -1)
	{
		if (ft_strlen(*backup) == 0)
			return (mem_free(backup, buffer));
		result = ft_strndup(*backup, ft_strlen(*backup));
		if (!result)
			return (mem_free(backup, buffer));
		mem_free(backup, buffer);
		return (result);
	}
	idx = 0;
	result = ft_strndup(*backup, cut_idx + 1);
	new_backup = ft_strndup(*backup + cut_idx + 1,
			ft_strlen(*backup) - cut_idx - 1);
	if (!result || !new_backup)
		mem_free(backup, buffer);
	free(*buffer);
	free(*backup);
	*backup = new_backup;
	return (result);
}

char	*get_next_line(int fd)
{
	static char		*backup;
	char			*buffer;
	ssize_t			read_size;
	int				cut_idx;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (backup == NULL)
		backup = ft_strndup("", 1);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!backup || !buffer)
		return (mem_free(&backup, &buffer));
	while (1)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size == -1)
			return (mem_free(&backup, &buffer));
		buffer[read_size] = '\0';
		backup = ft_strjoin(backup, buffer);
		if (!backup)
			return (mem_free(&backup, &buffer));
		cut_idx = is_newline(backup);
		if (cut_idx >= 0 || read_size == 0)
			return (cut_line(&backup, &buffer, cut_idx));
	}
}
