/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang < ejang@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:15:02 by ejang             #+#    #+#             */
/*   Updated: 2022/03/31 06:38:26 by ejang            ###   ########.fr       */
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

#endif