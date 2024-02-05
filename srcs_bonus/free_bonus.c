/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:48:49 by gmarre            #+#    #+#             */
/*   Updated: 2024/01/30 15:48:53 by gmarre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_cmd(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->curr_cmd[i])
	{
		free(pipex->curr_cmd[i]);
		i++;
	}
	free(pipex->curr_cmd);
}

void	free_path(char **path)
{
	int	i;

	i = 0;
	while (path[i])
	{
		free(path[i]);
		i++;
	}
	free(path);
}

void	free_pipes(t_pipex *pipex)
{
	int	i;

	i = -1;
	while (++i < pipex->nb_commands - 1)
		free(pipex->pipes[i]);
	free(pipex->pipes);
}
