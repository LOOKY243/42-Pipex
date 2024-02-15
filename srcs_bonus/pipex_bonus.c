/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarre <gmarre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:26:00 by gmarre            #+#    #+#             */
/*   Updated: 2024/02/05 16:19:50 by gmarre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	dups(int input, int output)
{
	dup2(input, STDIN_FILENO);
	dup2(output, STDOUT_FILENO);
	close(input);
	close(output);
}

void	manage_errors(int opt, t_pipex *pipex)
{
	if (opt == 0)
	{
		free_cmd(pipex);
		perror("Fork");
	}
	else if (opt == 1)
		perror("Execve");
	else if (opt == 2)
		perror("Open");
	else if (opt == 3)
		perror("Pipe");
	else if (opt == 4)
		perror("Write");
	else if (opt == 5)
		perror("Read");
	else if (opt == 6)
		perror("command not found");
	exit(EXIT_FAILURE);
}

void	child(t_pipex *pipex)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		manage_errors(0, pipex);
	get_cmds(pipex, pipex->argv, pipex->envp);
	if (pid == 0)
	{
		if (pipex->i == 0)
			dups(pipex->files[0], pipex->pipes[0][1]);
		else if (pipex->i == pipex->nb_commands - 1)
			dups(pipex->pipes[pipex->i - 1][0], pipex->files[1]);
		else
			dups(pipex->pipes[pipex->i - 1][0], pipex->pipes[pipex->i][1]);
		close_pipes(pipex);
		free_pipes(pipex);
		if (execve(pipex->curr_cmd[0], pipex->curr_cmd, pipex->envp) == -1)
		{
			free_cmd(pipex);
			manage_errors(1, pipex);
		}
	}
	free_cmd(pipex);
}

int	which_pipex(t_pipex *pipex, char **argv, int argc)
{
	if (!ft_strcmp(argv[1], "here_doc") && argc == 6)
	{
		pipex->cmd = 3;
		pipex->nb_commands = argc - 4;
		here_doc(pipex, argv);
		pipex->files[1] = open(argv[argc - 1], O_CREAT | O_WRONLY | O_APPEND,
				0666);
	}
	else if (ft_strcmp(argv[1], "here_doc") && argc >= 5)
	{
		pipex->cmd = 2;
		pipex->nb_commands = argc - 3;
		pipex->files[0] = open(argv[1], O_RDONLY);
		pipex->files[1] = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC,
				0666);
		if (pipex->files[1] == -1 || pipex->files[0] == -1)
		{
			close_files(pipex);
			manage_errors(2, pipex);
		}
	}
	else
		return (0);
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc < 5)
		return (1);
	if (!envp || !envp[0])
		return (1);
	pipex.argv = argv;
	pipex.commands = &argv[2];
	pipex.envp = envp;
	if (!which_pipex(&pipex, argv, argc))
		return (1);
	create_pipes(&pipex);
	pipex.i = -1;
	while (++pipex.i < pipex.nb_commands)
		child(&pipex);
	close_pipes(&pipex);
	pipex.i = -1;
	while (++pipex.i < pipex.nb_commands)
		waitpid(-1, NULL, 0);
	free_pipes(&pipex);
	unlink("here_doc.txt");
	return (0);
}
