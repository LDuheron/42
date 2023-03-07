/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:01:00 by lduheron          #+#    #+#             */
/*   Updated: 2023/03/03 13:46:44 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdint.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_pipex {
	int	fd[2];
	int	file_in;
	int	file_out;
}	t_pipex;

int			main(int argc, char **argv, char **env);
// utils pipex et split
void		*ft_memset(void *s, int value, int n);
void		ft_putstr_fd(char *s, int fd);
char		**ft_split(char *s, char c);
char		*ft_strjoin(char const *s1, char const *s2);
int			ft_strlen(char const *str);
int			ft_strncmp(const char *s1, const char *s2, int n);
int			wdcount(char const *s, char c);
char		*ft_strdup(char *src);

// get_path
int			ft_exec(char *argv, char **env, t_pipex *pipex);
char		*find_path(char *cmd, char **path_tableau);
char		**get_path(char **env);
void		clean(char **cmd, char *path, t_pipex *pipex);

///main.c
void		parent_process(char **argv, char **env, t_pipex *pipex);
void		child_process(char **argv, char **env, t_pipex *pipex);
void		pipex_init(t_pipex *pipex);

#endif