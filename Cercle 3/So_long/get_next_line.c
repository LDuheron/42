/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:36:04 by lduheron          #+#    #+#             */
/*   Updated: 2023/01/13 16:58:35 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*cut_before_end_line(char *remains, int end_line)
{
	char	*line;
	int		i;

	i = 0;
	if (!remains[i])
		return (NULL);
	line = (char *)malloc(sizeof(char) * (end_line + 2));
	if (!line)
	{
		free (line);
		return (NULL);
	}
	while (remains[i] != '\0' && remains[i] != '\n')
	{
		line[i] = remains[i];
		i++;
	}
	if (remains[i] == '\n')
	{
		line[i] = remains[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*cut_after_end_line(char *remains, int end_line)
{
	char	*line;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(remains);
	if (!remains[end_line])
	{
		free(remains);
		return (NULL);
	}
	line = (char *)malloc(sizeof(char) * (len - end_line + 1));
	if (!line)
		return (NULL);
	while (remains[end_line + 1])
	{
		line[i] = remains[end_line + 1];
		i++;
		end_line++;
	}
	line[i] = '\0';
	free (remains);
	return (line);
}

char	*ft_read(int fd, char *remains)
{
	char	*buffer;
	int		end;

	end = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE +1));
	if (!buffer)
	{
		free (buffer);
		return (NULL);
	}
	while (!ft_strchr(remains, '\n') && end != 0)
	{
		end = read(fd, buffer, BUFFER_SIZE);
		if (end < 0)
			break ;
		buffer[end] = '\0';
		remains = ft_strjoin(remains, buffer);
	}
	free(buffer);
	return (remains);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*remains;
	int			end_line;

	end_line = 0;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	remains = ft_read(fd, remains);
	if (!remains)
		return (NULL);
	while (remains[end_line] && remains[end_line] != '\n')
		end_line++;
	line = cut_before_end_line(remains, end_line);
	remains = cut_after_end_line(remains, end_line);
	return (line);
}
