/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 15:51:27 by lduheron          #+#    #+#             */
/*   Updated: 2023/04/24 15:41:43 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_path(char **env)
{
	int	i;

	i = 0;
	while (ft_strncmp("PATH=", *env, 5) != 0)
		env++;
	if (ft_strncmp("PATH=", *env, 5) == 0)
		return (ft_split(*env + 5, ':'));
	else
	{
		ft_putstr_fd("Error, no PATH= in environnement.\n", 2);
		return (NULL);
	}
}

char	*find_path(char *cmd, char **path_tableau)
{
	char	*path;
	char	*path_tmp;
	char	*path_tmp2;
	int		i;

	path = NULL;
	i = 0;
	while (path_tableau[i])
	{
		path_tmp = ft_strjoin(path_tableau[i], "/");
		free(path_tableau[i]);
		path_tmp2 = ft_strjoin(path_tmp, cmd);
		free(path_tmp);
		if (access(path_tmp2, F_OK) == 0)
		{
			path = ft_strdup(path_tmp2);
			free(path_tmp2);
			break ;
		}
		free(path_tmp2);
		i++;
	}
	free(path_tableau);
	return (path);
}

int	ft_exec(char *argv, char **env, t_pipex *pipex)
{
	char	**cmd;
	char	*path;
	char	**path_tableau;
	int		i;

	i = 0;
	path_tableau = NULL;
	path = NULL;
	cmd = NULL;
	path_tableau = get_path(env);
	cmd = ft_split(argv, 32);
	path = find_path(cmd[0], path_tableau);
	if (path == NULL)
	{
		ft_putstr_fd("Path unfound, commande inexistante\n", 2);
		clean(cmd, path, pipex);
		return (0);
	}
	else if (execve(path, cmd, env) == -1)
	{	
		ft_putstr_fd("Error execv\n", 2);
		clean(cmd, path, pipex);
	}
	return (0);
}
