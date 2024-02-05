/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_pipes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:48:27 by gmarre            #+#    #+#             */
/*   Updated: 2024/01/30 15:48:29 by gmarre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (&envp[i][5]);
		i++;
	}
	return (NULL);
}

void	get_cmds(t_pipex *pipex, char **argv, char **envp)
{
	int		j;
	int		trigger;
	char	*tmp;
	char	**path;

	path = ft_split(find_path(envp), ':');
	pipex->curr_cmd = ft_split(argv[pipex->cmd], ' ');
	j = -1;
	while (path[++j])
	{
		tmp = ft_strjoin(path[j], pipex->curr_cmd[0]);
		if (access(tmp, X_OK) == 0)
		{
			free(pipex->curr_cmd[0]);
			pipex->curr_cmd[0] = tmp;
			trigger = 0;
			break ;
		}
		free(tmp);
	}
	free_path(path);
	pipex->cmd++;
}

void	create_pipes(t_pipex *pipex)
{
	int	i;

	i = -1;
	pipex->pipes = ft_calloc(pipex->nb_commands - 1, sizeof(int **));
	while (++i < pipex->nb_commands - 1)
	{
		pipex->pipes[i] = ft_calloc(2, sizeof(int *));
		if (pipe(pipex->pipes[i]) == -1)
		{
			free_cmd(pipex);
			manage_errors(3, pipex);
		}
	}
}

void	close_pipes(t_pipex *pipex)
{
	int	i;

	i = -1;
	while (++i < pipex->nb_commands - 1)
	{
		close(pipex->pipes[i][0]);
		close(pipex->pipes[i][1]);
	}
	close(pipex->files[0]);
	close(pipex->files[1]);
}
