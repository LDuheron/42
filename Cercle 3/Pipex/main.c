/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 15:52:49 by lduheron          #+#    #+#             */
/*   Updated: 2023/03/06 13:56:25 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
// ➜  Push_swap git:(main) ✗ valgrind --trace-children=yes --track-fds=yes --leak-check=full ./pipex infile whoami whoamii outfile

// fd[0]=read end
// fd[1] = write end
// ./pipex argv[1] argv[2] argv[3] argv[4]

void	pipex_init(t_pipex *pipex)
{
	pipex->fd[0] = -1;
	pipex->fd[1] = -1;
	pipex->file_in = -1;
	pipex->file_out = -1;
}

void	child_process(char **argv, char **env, t_pipex *pipex)
{
	printf("Child.\n");
	pipex->file_in = open(argv[1], O_RDONLY);
	if (pipex->file_in < 0)
		ft_putstr_fd("Error reading infile\n", 2);
	dup2(pipex->fd[1], 1);
	dup2(pipex->file_in, 0);
	if (pipex->fd[0] != -1)
		close(pipex->fd[0]);
	if (pipex->fd[1] != -1)
		close(pipex->fd[1]);
	ft_exec(argv[2], env, pipex);
}

void	parent_process(char **argv, char **env, t_pipex *pipex)
{
	printf("Parent.\n");
	pipex->file_out = open(argv[4], O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (pipex->file_out < 0)
		ft_putstr_fd("Error reading outfile\n", 2);
	dup2(pipex->fd[0], 0);
	dup2(pipex->file_out, 1);
	if (pipex->fd[1] != -1)
		close(pipex->fd[1]);
	if (pipex->fd[0] != -1)
		close(pipex->fd[0]);
	ft_exec(argv[3], env, pipex);
	close(pipex->file_out);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;
	pid_t	pid;

	if (argc != 5)
	{
		ft_putstr_fd("Wrong number of arguments.", 2);
		return (0);
	}
	pipex_init(&pipex);
	pipe(pipex.fd);
	pid = fork();
	if (pid == -1)
		ft_putstr_fd("Error pid", 2);
	else if (pid == 0)
		child_process(argv, env, &pipex);
	else
	{
		while (wait(0) != -1)
			;
		parent_process(argv, env, &pipex);
	}
	return (0);
}
