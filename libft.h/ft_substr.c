/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:13:03 by lduheron          #+#    #+#             */
/*   Updated: 2022/11/11 11:13:06 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*nchaine;
	size_t	i;

	i = 0;
	nchaine = malloc((len + 1) * (sizeof(int)));
	if (!(nchaine))
		return ("NULL");
	else
	{
		while (i < (len))
		{
			nchaine[i] = s[start];
			i++;
			start++;
		}
		nchaine[i] = '\0';
	}
	return (nchaine);
}

/*
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*nchaine;
	size_t	i;

	i = 0;
	nchaine = malloc((len + 1) * (sizeof(int)));
	if (!(nchaine))
		return ("NULL");
	else
	{
		while (i < len)
		{
			nchaine[i] = s[start];
			i++;
			start++;
		}
	}
	return (nchaine);
}
*/
