/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 15:52:49 by lduheron          #+#    #+#             */
/*   Updated: 2023/04/25 17:31:11 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
// ➜  Push_swap git:(main) ✗ valgrind --trace-children=yes --track-fds=yes
//--leak-check=full ./pipex infile whoami whoamii outfile
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
	pipex->file_in = open(argv[1], O_RDONLY, 0777);
	if (pipex->file_in < 0)
		ft_putstr_fd("Error opening file_in\n", 2);
	dup2(pipex->fd[1], 1);
	dup2(pipex->file_in, 0);
	if (pipex->fd[0] != -1)
		close(pipex->fd[0]);
	ft_exec(argv[2], env, pipex);
}

void	parent_process(char **argv, char **env, t_pipex *pipex)
{
	pipex->file_out = open(argv[4], O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (pipex->file_out < 0)
		ft_putstr_fd("Error opening file_out\n", 2);
	dup2(pipex->fd[0], 0);
	dup2(pipex->file_out, 1);
	if (pipex->fd[1] != -1)
		close(pipex->fd[1]);
	ft_exec(argv[3], env, pipex);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;
	pid_t	pid;

	if (argc == 5)
	{
		pipex_init(&pipex);
		if (pipe(pipex.fd) == -1)
			return (ft_putstr_fd("Error pipe creation", 2));
		pid = fork();
		if (pid == -1)
			return (ft_putstr_fd("Error fork creation", 2));		

		else if (pid == 0)
			child_process(argv, env, &pipex);
		// waitpid(pid, NULL, 0);
		wait(0);
		parent_process(argv, env, &pipex);
	} 
	else
		return (ft_putstr_fd("Wrong number of arguments.", 2));
	return (0);
}

//while (wait(0) != -1)
			// ;
