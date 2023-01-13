/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 12:54:18 by lduheron          #+#    #+#             */
/*   Updated: 2022/11/28 20:24:05 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*buffer;

	if (size > 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	buffer = malloc(nmemb * size);
	if (!(buffer))
		return (NULL);
	ft_bzero(buffer, nmemb * size);
	return (buffer);
}
