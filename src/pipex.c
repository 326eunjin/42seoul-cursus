/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang < ejang@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 21:25:02 by ejang             #+#    #+#             */
/*   Updated: 2022/03/31 07:03:40 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	path_exec(char	*argv, char	**envp)
{
	char	*path;
	int		i;
	char	**cmd;

	i = 0;
	cmd = ft_split(argv, ' ');
	path = cmd[0];
	if (!ft_strchr(cmd[0], '/'))
	{
		path = find_path(cmd[0], envp);
		if (!path)
		{
			while (cmd[++i])
				free(cmd[i]);
			free(cmd);
			perror("ERROR");
			exit(127);
		}
	}
	execve(path, cmd, envp);
	while (cmd[i])
		free(cmd[i++]);
	free(cmd);
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
		outfile = open(argv[4], O_RDWR | O_CREAT | O_TRUNC);
		if (infile == -1 || outfile == -1)
			error_handle();
		pipex(infile, outfile, argv, envp);
		return (0);
	}
	else
		error_handle();
}
