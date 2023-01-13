int main(void)
{
	int		fd;
	char	*line;

	fd = open("california.txt", O_RDONLY);
    //fd = ;
	while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line); 
    }
    printf("%s", line);
    return (0);
} 




/*int	main(void)
{
	int		fd;
	char *line;

//	printf("Entree main\n");
	fd = open("california.txt", O_RDONLY);
//	printf("%i\n",fd);
	line = get_next_line(fd);
	printf("%s\n", line);
	free (line);
	line = get_next_line(fd);
	printf("%s\n", line);
	free (line);
	line = get_next_line(fd);
printf("%s\n", line);
	free (line);
	//printf("%s\n",	get_next_line(fd));
//	printf("%s\n",	get_next_line(fd));
	//printf("%s\n",	get_next_line(fd));
	//printf("%s\n",	get_next_line(fd));
	// printf("%s\n",	get_next_line(fd));
	// printf("%s\n",	get_next_line(fd));
	// printf("%s\n",	get_next_line(fd));
	// printf("%s\n",	get_next_line(fd));
	// printf("%s\n",	get_next_line(fd));
	// printf("%s\n",	get_next_line(fd));
	return (0);
}*/

// int main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("california.txt", O_RDONLY);
//     //fd = 1;
// 	while ((line = get_next_line(fd)))
//     {
//         printf("%s", line);
//         free(line); 
//     }
//     printf("%s", line);
//     return (0);
// } 

// int	main(void)
// {
// 	char *line = NULL;
// 	int fd;

// 	fd = open("californiaC.c", O_RDWR);
// 	//
// 	while (line == get_next_line(fd))
// 	{
// 		//line = get_next_line(fd);
// 		printf("%s\n", line);
// 		free(line);
// 	}
// 	close(fd);
// }

// /*

