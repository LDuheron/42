/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:56:43 by lduheron          #+#    #+#             */
/*   Updated: 2022/11/18 18:02:26 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

int	ft_strlcat(char *dst, const char *src, size_t size)
{
	int	res;

	if (dst >= src)
		return (size - ft_strlen(dst));
	res = (size - ft_strlen(dst));
	ft_strlcpy (dst, src, (size - ft_strlen(dst)));
	return (res);
}
/*

proteger pour le null et proteger pour le i deja incremente


renvoyer l;a size si dst >= 

strlcpy
penser au -1 byte pour le \0 mais pas utilise dans le strlcpy qi le fait deja 
res pour sauvegarder la taille avant de la ;odifier.

int	ft_strlcat(char *dst, const char *src, size_t size)
{
	int	len;
	size_t	i;
	int	j;

	len = 0;
	i = 0;
	j = 0;
	while (dst[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0' && dst[i] != '\0' && (i < size))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	while (dst[len] != '\0')
		len++;
	return (len);
}


int	ft_strlcat(char *dst, const char *src, size_t size)
{
	int	res;

	if (dst >= res)
		return (size - strlen(dst));
	res = (size - strlen(dst);
	ft_strlcpy (dest(size - strlen(dst));
	return (res);
}

*/
