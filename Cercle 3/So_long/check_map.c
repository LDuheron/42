#include "get_next_line.h"
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

///// UTILS /////

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

char	**ft_split(char *s, char c)
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

///// Check MAP /////
 


// int check_columns()
// {
	
// }

// int	check_lines()

// ///// RECAP /////

int	check_map(char **line,  int nbr_ligne)
{
	int i;
	int	columns;
	int len_line;

	i = 0;
	printf("Entree check map\n");
	columns = ft_strlen(line[0]);
	printf("valeur de len ref: %i\n", columns);
	while (i < nbr_ligne)
	{
		len_line = ft_strlen(line[i]);
		if (len_line != columns)
		{	
			printf("%s", line[i]);
			printf("Error len\n");
			return(0);
		}
		printf("li0 %d\n", line[i][0]);
		
		printf("li0 %s\n", &line[i][0]);
		//printf("li0 %d\n", **line[i][0]);
		if (line[i][0] != 1 || line[i][columns - 1] != 1)
		{
			printf("%s", line[i]);
			printf("Error wall\n");
			return(0);
		}
		i++;
	}
	return (1);
}

///// MAIN - PARSING /////

int main(void)
{
	int		fd;
	char	*line;
	char **final;
	int	i;
	int nbr_ligne;

	nbr_ligne = 0;
	fd = open("map.ber", O_RDONLY);
    while ((line = get_next_line(fd)))
	{
		free (line);
		nbr_ligne++;
	}
	final = malloc(sizeof(char**) * nbr_ligne);
	fd = open("map.ber", O_RDONLY);
	i = 0;
	while ((line = get_next_line(fd)))
    {
        final[i] = line;
		//printf("%s", final[i]);
      //  free(line); 
		i++;
    }
	printf("\n");
	printf("nombre de ligne : %i\n", nbr_ligne);
	check_map(final, nbr_ligne);
    return (0);
} 

// int error_message_map(int a)
// {
// 	if (a = 0)
// 		ft_putstr();
// 	if (a = 0)
// 		ft_putstr();
// 	if (a = 0)
// 		ft_putstr();
// }