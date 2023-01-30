#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>


int	main(void) //char **env
{
	int	pid;
	int	pipefd[2];

	pipe(pipefd);
	pid = fork();
	if (pid == -1)
		printf("Erreur.");
	if (pid == 0) /// pid du child -> fd 1
	{
			close(pipefd[0]); // On bloque la possibilite au pipe de lire sur le fd 0.
			dup2(pipefd[1], 1);
			printf("Child.\n");
	}
	else // pid du parent fd -> 0
	{
		close(pipefd[1]); // On bloque la possibilite au pipe de lire sur le fd 1.
		dup2(pipefd[0], 0);
		printf("Parent.");
	}
	return (0);
}