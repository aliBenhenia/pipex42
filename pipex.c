/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenheni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 19:14:50 by abenheni          #+#    #+#             */
/*   Updated: 2022/12/19 19:14:53 by abenheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	excuter(char *cmd, char *env[])
{
	char	**commands;
	char	*ful;
	char	**paths;

	commands = ft_split(cmd, ' ');
	paths = ft_split(get_path(env), ':');
	if (!commands || !paths)
		my_error("error when check commands or paths");
	ful = check_path(paths, commands);
	if (ful)
	{
		if (execve(ful, commands, env) == -1)
			my_error("error execve");
	}
	my_free(commands);
	my_free(paths);
	my_error("command not found");
}

void	first_cmnd(int *fd, char *av[], char *env[])
{
	int	f1;

	f1 = open(av[1], O_RDONLY, 0777);
	if (f1 == -1)
		my_error("error with open file1");
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		my_error("ERROR with dup");
	if (dup2(f1, STDIN_FILENO) == -1)
		my_error("ERROR with dup");
	close(fd[0]);
	close(f1);
	close(fd[1]);
	excuter(av[2], env);
}

void	sc_command(int *fd, char *av[], char *env[])
{
	int	f2;

	f2 = open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (f2 == -1)
		my_error("error with open file2");
	if (dup2(fd[0], STDIN_FILENO) == -1)
		my_error("ERROR with dup");
	if (dup2(f2, STDOUT_FILENO) == -1)
		my_error("ERROR with dup");
	close(fd[0]);
	close(fd[1]);
	close(f2);
	excuter(av[3], env);
}

void	pipex(char ac, char *av[], char *env[])
{
	int	fd[2];
	int	pid1;

	if (ac != 5)
		my_error("SHOULD 5 arguments !");
	if (pipe(fd) == -1)
		my_error("ERROR with pipe");
	pid1 = fork();
	if (pid1 == -1)
		my_error("ERROR with fork");
	if (pid1 == 0)
	{
		first_cmnd(fd, av, env);
	}
	if (pid1 > 0)
	{
		wait(NULL);
		sc_command(fd, av, env);
	}
	close(fd[0]);
	close(fd[1]);
}
