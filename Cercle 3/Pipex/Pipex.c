#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

// https://csnotes.medium.com/pipex-tutorial-42-project-4469f5dd5901 
// free si ereur 

// 	foncton pour intialiser tous les parametres dont jai besoin	
// 	memset pour faire pointer vers null tout les pointeurs?


void	ft_putstr(char *s)
{
	if (s != NULL)
		write(1, s, 1);
}

struct t_pipex {
	int	pid;
	int infile; // 
	int	outfile; //
	int	fd1;
	int	fd2;
	char **path_tableau;
	char *path;
	
};

// 	execv(path, ma commande et mon environenemnt)
// 	-> creer une fonctionqui va aller dans lenvironnement et regarder ligne par ligne si cest le bon ou pas , a chaque fois separe en :, avec access cherche rsi bien dans lexecutable, utiliser fok et accessok, join commande, access pour voir si ca marche et s = condition verifier qu otut return 1 car 0 = echec; rejouter un / quand bonne commande pour terminer le path:
// 	en deuxieme parametre donner ma commande en argv2 et ensuite donner l'environnement.

void pipex(char **env)
{
	pid_t	pid;
	int	pipefd[2];
	int fd[2];

	pipe(pipefd);
	pid = fork();
	if (pid == -1)
		printf("Erreur.");
	if (pid == 0) // pid du child -> fd 1
	{
		close(pipefd[0]); // On bloque la possibilite au pipe de lire sur le fd 0.
		dup2(pipefd[1], 1);
		printf("Child.\n");
		execve(cmd1);//
	}
	else // pid du parent fd -> 0
	{
		waitpid(0); /// pas compris le fonctionnement 
		close(pipefd[1]); // On bloque la possibilite au pipe de lire sur le fd 1.
		dup2(pipefd[0], 0);
		printf("Parent.");
		execve(path, argv[], env);
	}
	return (0);
}

// ./pipex argv[1] argv[2] argv[3] argv[4]
int	main(int argc, char *argv)
{
	
	struct t_pipex pipex;
	
	if (argc (!= 5))
	{
		ft_putstr_fd("Invalid number of argument", 2);
		return (NULL);
	}
	// Find the path
	fd[0] = open(argv[1], O_RDONLY);
	fd[1] = open(argv[4], O_RDONLY, O_WRONLY, O_RDWR, 0644);
	// Fork
	ft_pipex(void);
	return (0);
}

// pour avoir l'env 
// env dans le terminal
// fonction get path pour remplir path par le vrai path et le donner a  excev(path, env) ?? 

// chercher "PATH=" dan senv
// join avec un / pour qu'il puisse lire


	// fd[0] = open("fd1.txt", O_RDONLY);
	// fd[1] = open("fd2.txt", O_RDONLY);