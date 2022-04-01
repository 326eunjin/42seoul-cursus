/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang < ejang@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 21:25:02 by ejang             #+#    #+#             */
/*   Updated: 2022/04/01 12:47:46 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	path_exec(char	*argv, char	**envp)
{
	char	*path;
	char	**cmd;

	cmd = ft_split(argv, ' ');
	path = cmd[0];
	if (!ft_strchr(cmd[0], '/'))
	{
		path = find_path(cmd[0], envp);
		if ((access(path, F_OK) == -1) || (path == 0))
		{
			free(path);
			free_split(cmd);
			exit(127);
		}
		execve(path, cmd, envp);
		free(path);
	}
	else
	{
		execve(path, cmd, envp);
	}
	free_split(cmd);
}

void	pipex(int infile, int outfile, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;
	int		status;

	if (pipe(fd) == -1)
		error_handle();
	pid = fork();
	if (pid == 0)
	{
		dup2(infile, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		path_exec(argv[2], envp);
	}
	else
	{
		dup2(outfile, STDOUT_FILENO);
		dup2(fd[0], STDIN_FILENO);
		close(fd[1]);
		waitpid(-1, &status, WNOHANG);
		path_exec(argv[3], envp);
	}
}

void	error_handle(void)
{
	perror("ERROR");
	exit(1);
}

int	main(int argc, char **argv, char **envp)
{
	int	infile;
	int	outfile;

	if (argc == 5)
	{
		infile = open(argv[1], O_RDONLY);
		outfile = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (infile == -1 || outfile == -1)
			error_handle();
		pipex(infile, outfile, argv, envp);
		return (0);
	}
	else
		error_handle();
}
