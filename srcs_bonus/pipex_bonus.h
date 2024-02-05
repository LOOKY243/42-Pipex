/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarre <gmarre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:26:11 by gmarre            #+#    #+#             */
/*   Updated: 2024/02/02 15:43:41 by gmarre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

# define BUFFER_SIZE 42

typedef struct s_pipex
{
	char	**envp;
	int		here_doc;
	int		**pipes;
	int		i;
	int		cmd;
	int		files[2];
	int		pipe_fd[2];
	int		nb_commands;
	char	**argv;
	char	**curr_cmd;
	char	**commands;
}			t_pipex;

void		here_doc(t_pipex *pipex, char **argv);
void		manage_errors(int opt, t_pipex *pipex);
void		free_pipes(t_pipex *pipex);
void		free_path(char **path);
void		free_cmd(t_pipex *pipex);
void		get_cmds(t_pipex *pipex, char **argv, char **envp);
char		*find_path(char **envp);
void		create_pipes(t_pipex *pipex);
void		close_pipes(t_pipex *pipex);
void		close_files(t_pipex *pipex);
int			ft_strcmp(char *s1, char *s2);
#endif
