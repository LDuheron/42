/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:06:11 by lduheron          #+#    #+#             */
/*   Updated: 2022/11/30 15:48:26 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t nmemb, size_t size);
ssize_t	read(int fd, void *buf, size_t count);


#include "get_next_line.h"
//fonctions autorisees read, malloc, free
static char	read_and_fulfill(int fd)
{
	size_t 	i;
	char	*line;
	char	*buffertmp;
	char	find_end_line // trouver le \n
	
	i = 0;
	while (find_end_line = ft_strchr(line, \n) == 0)
	while (line[i] != find_end_line)
		{
	
		}
		substr(start, strchr(line, \n));
	
	//if after le pointeur sur strch va dans remains
//	read(fd, buff, BUFFER_SIZE);
		line = strjoin(line, buffertmp)
	return(line);
}



{
	char	line;
	char	*buffer;
	char	*remains;

	*buffer = calloc(buffer_size + 1), sizeof(char);
	if (buffer == NULL)
		return ;
	
}

char *get_next_line(int fd)
{
	int	i;
	int	x;

	if (fd < 0 || buffer_size < 0)
		return ;
	*line = calloc(buffer_size + 1), sizeof(char);
	*buffer = calloc(buffer_size + 1), sizeof(char);
	if ( !line || !buffer)
		return ;
	
	if (remains == NULL)
	line = (strjoin )


int	main(int buffer_size)
{
	int		fd;
	size_t	i;
	char	*line;
	
	i = 0;
	fd = open(fd, RDONLY);
	while (i >)
	{
		line = get_next_line(fd, buffersize);
		printf;
		i++;
	}
}


/*

while (i);
(
	int	i;
	int	j;

	i = 0;
	j = 0;
)
strjoin

line = 
buffer = 


size_t	ft_strlcpy(char *dst, const char *src, unsigned int size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && (i + 1) < size)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
*/
