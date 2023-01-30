#include <unistd.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdint.h>

/* poubelle
char *find_path(char** env, char *cmd1)
{
	char **path_tableau;
 	char *path;
	int	i;

	i = 0;
	path_tableau = get_path(env);
	while(path_tableau[i])
	{
		path = ft_strjoin(path_tableau[i], cmd1); + / cmd 1 == argv[2];
		if (access(path, F_OK, X_OK) == 0)
			return (path);
		i++;
	}
	ft_put_str("Error. Please insert a valid command.");
	return (NULL);
}





	// if (pid == -1)
	// 	printf("error fork");
	// else if (pid == 0)
	// {
	// 	execve(*path, &argv[1], env);
	// 	printf("Enter in pid == 0");
	// }
// 	return(0);
// }


	// while (*path[i] && i < 10)
	// {
	// 	printf("%s\n", path[i]);
	// 	i++;
	// }


*/


size_t	ft_strlen(char const *str)
{
	int	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	join = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!join)
		return (NULL);
	while (s1[i] != '\0')
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0' && join)
	{
		join[i] = s2[j];
		i++;
		j++;
	}
	join[i] = '\0';
	return (join);
}

/*#### UTILS #######*/

int	wdcount(char const *s, char c)
{
	int	i;
	int	cpt;

	i = 0;
	cpt = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			cpt++;
			i++;
		}
		while (s[i] != c && s[i])
			i++;
	}
	return (cpt);
}

static char	*ftdup(char const *s, char c)
{
	long	len;
	char	*scopy;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	scopy = malloc(len + 1);
	if (!scopy)
		return (NULL);
	scopy[len] = 0;
	while (len > 0)
	{
		scopy[len - 1] = s[len - 1];
		len -= 1;
	}
	return (scopy);
}

static void	ftfree(char **buffer, long i)
{
	while (i)
	{
		free (buffer[i]);
		i--;
	}
	free (buffer);
}

char	**ft_split(char const *s, char c)
{
	char	**buffer;
	long	i;

	i = 0;
	buffer = malloc((wdcount(s, c) + 1) * sizeof (char *));
	if (!buffer)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (!(*s))
			break ;
		buffer[i++] = ftdup(s, c);
		if (!buffer[i - 1])
		{
			ftfree(buffer, i);
			return (buffer);
		}
		while (*s && *s != c)
			s++;
	}
	buffer[i] = NULL;
	return (buffer);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < (n - 1))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*#### PATH ######*/


char **get_path(char **env)
{
	int	i;
	
	i = 0;
	while (ft_strncmp("PATH=", *env, 5) != 0)
		env++;
	return (ft_split(*env + 5, ':'));
}

char *find_path(char *cmd1, char **env)
{
	char **path_tableau;
 	char *path;
	int	i;

	i = 0;
	path_tableau = get_path(env);
	while (path_tableau[i]) // 
	{
		path_tableau[i] = ft_strjoin(path_tableau[i], "/");
		//printf("%s\n", path);
		path_tableau[i] = ft_strjoin(path_tableau[i], cmd1); 
		//printf("%s\n", path);
		// printf("%i\n", i);
		// if (access("/mnt/nfs/homes/lduheron/ls", F_OK) == 0)
		// 	printf("bad path is working\n");
		if (access(path_tableau[i], F_OK) == 0)
		{
			printf("LE BON PATH :%s\n", path_tableau[i]);
			return (path_tableau[i]);
		}
		i++;
	}
	path = "ERROR IN FIND PATH"; //printf("ERROR IN FIND PATH");
	//ft_put_str("Error. Please insert a valid command.");
	return (path);
}

int main(int argc, char **argv, char **env)
{
	// int fdin;
	// int fdout;
	
	int		i;
	int		pid;
	int		pipefd[2];	
	char	*cmd1;
	char	*cmd2;
	char **splitargv2;
	char **splitargv3;
	char **path;
	char *path_cmd1;
	char *path_cmd2;

	// debut

	// if (argc == 5)
	// (
	// 	fdin = openfile(argv(1), INFILE);
	// 	fdout = openfile(argv[4], OUTFILE);
	// 	dup2(fdin, STDIN);
	// 	dup2(fdout, STDOUT);
	// )
	// else 
	// {
	// 	ft_putstr("Invalid number of arguments");
	// 	return (NULL);
	// }

	// initialiser les split de commandes, gerer les "grep c"
	i = 0;
	splitargv2 = ft_split(argv[2], 32);
	printf("Splitargv2 %i : %s\n", i, splitargv2[0]);
	splitargv3 = ft_split(argv[3], 32);
	printf("Splitargv3 %i : %s\n", i, splitargv3[0]);
	cmd1 = splitargv2[0];
	cmd2 = splitargv3[0];	
	path_cmd1 = find_path(cmd1, env);
	//printf("No segfault here (main)\n");
	path_cmd2 = find_path(cmd2, env);
	printf("LE PATH FINAL POUR CMD1 EST : %s\n", path_cmd1);
	printf("LE PATH FINAL POUR CMD2 EST : %s\n", path_cmd2);
	i = 0;
	pipe(pipefd);
	pid = fork();
	if (pid == -1)
		printf("Erreur.");
	if (pid == 0) /// pid du child -> fd 1
	{
			close(pipefd[0]); // On bloque la possibilite au pipe de lire sur le fd 0.
			dup2(pipefd[1], 1);
			// execve la cmd 1
			// while (splitargv2[i])
			// {
			// 	execve(*path_cmd1, &splitargv2[i], env);
			// 	i++;
			// }
			printf("Child.\n");
	}
	else // pid du parent fd -> 0
	{
		//waitpid(0);
		close(pipefd[1]); // On bloque la possibilite au pipe de lire sur le fd 1.
		dup2(pipefd[0], 0);
		//execve(*path, argv[], env);
		printf("Parent.");
	}
	return (0);
}
