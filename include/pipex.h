/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:15:02 by ejang             #+#    #+#             */
/*   Updated: 2022/03/31 21:26:53 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include <sys/types.h>
# include <stdio.h>
# include "../libft/libft.h"

void	path_exec(char	*argv, char	**envp);
void	pipex(int infile, int outfile, char **argv, char **envp);
void	error_handle(void);
char	*find_path(char *cmd, char **envp);
void	free_split(char **args);

#endif