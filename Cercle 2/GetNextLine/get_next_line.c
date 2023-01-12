/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 08:24:23 by lduheron          #+#    #+#             */
/*   Updated: 2022/12/08 18:19:36 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/*
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

char	*ft_strchr(const char *s, int c)
{
	const unsigned char	cpy_c = (unsigned char)c;
	size_t				i;

	i = 0;
	while (s[i] != cpy_c && s[i] != '\0')
		++i;
	if (s[i] == cpy_c)
		return ((char *)(s + i));
	return (NULL);
}

size_t	get_min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			len_s;
	size_t			new_len;
	char			*nchain;

	if (s == NULL)
		nchain = NULL;
	else
	{
		len_s = ft_strlen(s);
		new_len = 0;
		if (start <= len_s)
			new_len = get_min(len_s - start, len);
		else
			start = len_s;
		nchain = malloc((new_len + 1) * sizeof(char));
		if (nchain != NULL)
			ft_strlcpy(nchain, s + start, new_len + 1);
	}
	return (nchain);
}

int	check(char const *set, const char curr_c)
{
	if (curr_c != '\0' && ft_strchr(set, curr_c) != NULL)
		return (1);
	return (0);
}

char	*ft_strtrim(char const *s, char const *set)
{
	char			*copy;
	size_t			i;
	size_t			len;
	size_t			start;
	
	if (!s && !set)
		return (NULL);
	len = ft_strlen(s);
	start = 0;
	i = 0;
	//printf(" STRTRIM ");
	if (len > 0)
	{
		while (check(set, s[start]) == 1)
			++start;
		while (i < len && check(set, s[len - i - 1]) == 1)
			++i;
	}
	copy = ft_substr(s, start, (len - i - start));
	if (copy == NULL)
		return (NULL);
	//printf("test copy");
	//printf("%s", copy);
	return (copy);
}

*/

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

int	ft_strchr2(const char *s, char c)
{
	size_t				i;

	i = 0;
	//printf("ok entree strchr2 ");
	while (s[i] != c && s[i] != '\0')
		++i;
	if (s[i] == c)
		return (1);
	return (0);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc(sizeof(char) * ft_strlen(src) + 1);
	if (dest == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*fulfill(int fd, char *buffer, char *remains)
{
	static char	*buffy;
	int			end;

	buffy = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buffy || fd < 0 || BUFFER_SIZE < 1 || read(fd, buffy, 0))
	{
		free(buffy);
		buffy = NULL;
		return (0);
	}
	if (buffer == NULL)
		buffer = ft_strdup("");
	if (remains != NULL)
	{
		buffer = ft_strjoin(buffer, remains);
		remains = NULL;
	}
	buffy[0] = 0;
	while (ft_strchr2(buffy, '\n') == 0)
	{
		end = read(fd, buffy, BUFFER_SIZE);
		if (end < 0)
			break;
		buffy[end] = 0;
		buffer = ft_strjoin(buffer, buffy);
		//printf("%s", buffer);
		//printf("%c", '\n');
		//printf("FIN DE FULFILL\n");
	}
	free(buffy);
	//if (end == 0)
	//	return (0);
	return (buffer);
}

char	*ft_strdupbis(char *buffer)
{
	int		i;
	char	*remains;
	int		j;

	i = 0;
	j = 0;
	remains = NULL;
	while (buffer[i] != '\n')
	{
		//printf("BOUCLE%d\n", i);
		++i;
	}
	remains = malloc(sizeof(char) * ft_strlen(buffer) - i + 1);
	i++;
	if (remains == NULL)
		return (NULL);
	while (buffer[i] != '\0')
	{	
		remains[j] = buffer[i];
		i++;
		j++;
	}		
	//printf("PAS DE PB");
//	printf("%s\n", remains);
	remains[i] = '\0';
	return (remains);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	static char *remains = NULL;
	int			cut; 

	cut = 0;
	buffer = malloc(BUFFER_SIZE + 1);
	buffer = fulfill(fd, buffer, remains);
//	printf("\nFulfill ? :%s\n", buffer);
	if (!buffer)
	{
		free (buffer);
		buffer = NULL;
		return (NULL);
	}
//	printf(" Entree dans gnl ok\n ");
	cut = ft_strchr2(buffer, '\0');
//	printf("%d\n", cut);
	if (cut == 1)
	{
		//printf("BUFFER ? : %s\n", buffer);
		remains = ft_strdupbis(buffer);
		//printf(" ok alloc remains\n");
		//printf("Remains : %s\n", remains);
		buffer = ft_strtrim(buffer, remains);
		//printf("Buffer : %s\n", buffer);
	}
	//printf("%s", buffer);
	return (0);
}

/*
int	main(void)
{
	int		fd;

	fd = open("california.txt", O_RDONLY);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	return (0);
}

*/