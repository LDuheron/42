/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:06:11 by lduheron          #+#    #+#             */
/*   Updated: 2022/11/30 14:52:59 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
//fonctions autorisees read, malloc, free
 


static char	read_and_stock(int fd)
{
	int i;
	int	line;

	i = 0;
	line = substr(start, strchr(fd, \n));
//	read(fd, buff, BUFFER_SIZE);

}


char *get_next_line(int fd)
{
}



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


int	main()
{
	char	line;
	char	*buffer;
	int	remains


	fd = open(fd, RDONLY)
	buffer = calloc(buffer + 1)
	if (buffer == NULL)
		return ;
	
}


/*
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