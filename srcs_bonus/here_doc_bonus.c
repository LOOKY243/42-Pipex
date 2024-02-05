/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarre <gmarre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:47:29 by gmarre            #+#    #+#             */
/*   Updated: 2024/02/02 15:46:30 by gmarre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	open_file(int opt)
{
	int	fd;

	if (opt == 1)
		fd = open("here_doc.txt", O_CREAT | O_WRONLY | O_TRUNC, 0666);
	else
		fd = open("here_doc.txt", O_RDONLY, 0666);
	if (fd == -1)
	{
		perror("Open");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if ((s1[i] < s2[i]) || (s2[i] < s1[i]))
			return (s1[i] - s2[i]);
		else
			i++;
	}
	return (0);
}

void	here_doc(t_pipex *pipex, char **argv)
{
	int		bytes;
	char	input[BUFFER_SIZE + 1];

	pipex->files[0] = open_file(1);
	bytes = 1;
	write(1, "pipe heredoc> ", 15);
	while (bytes > 0)
	{
		bytes = read(STDIN_FILENO, input, BUFFER_SIZE);
		input[bytes] = 0;
		if (bytes == -1)
			manage_errors(5, pipex);
		if (ft_strlen(input) - 1 == ft_strlen(argv[2]))
			if (!ft_strncmp(input, argv[2], ft_strlen(argv[2])))
				break ;
		if (write(pipex->files[0], input, bytes) != bytes)
		{
			close(pipex->files[0]);
			manage_errors(4, pipex);
		}
		write(1, "pipe heredoc> ", 15);
	}
	close(pipex->files[0]);
	pipex->files[0] = open_file(2);
}
