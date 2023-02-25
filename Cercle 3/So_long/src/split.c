/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 20:21:28 by lduheron          #+#    #+#             */
/*   Updated: 2023/02/25 17:41:50 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

static char	*ftdup(char *s, char c)
{
	long	len;
	char	*scopy;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	scopy = malloc(sizeof(char) * (len + 2));
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
		free(buffer[i]);
		i--;
	}
	free(buffer);
}

char	**ft_split(char *s, char c)
{
	char	**buffer;
	long	i;

	i = 0;
	buffer = malloc((wdcount(s, c) + 1) * sizeof(char *));
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
