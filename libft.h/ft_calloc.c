/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 12:54:18 by lduheron          #+#    #+#             */
/*   Updated: 2022/11/22 15:49:56 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*buffer;

	if (nmemb > 65535)
		return (NULL);
	buffer = (void *)malloc(nmemb * size);
	if (!(buffer))
		return (NULL);
	ft_bzero(buffer, nmemb * size);
	return (buffer);
}
/*

malloc mais en initialisant la memoire prise a la valeur 0
en cas d'echec elle renvoie un pointeur nul 

overflow

*/
