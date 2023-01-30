#include <unistd.h>

int main{void}
{

	return (0);
}
	else
	{
		close(pipe(pipex->fd1[0]));// fd1?
		dup2(pipe(pipex->fd1[1]));
		printf("Test pid parent dans le else"); 
		if (pipex->fd1 == 0)
		{
			pri