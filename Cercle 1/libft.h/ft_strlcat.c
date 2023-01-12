/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:56:43 by lduheron          #+#    #+#             */
/*   Updated: 2022/11/25 17:38:57 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	if ((dst == NULL || src == 0) && size == 0)
		return (0);
	while (dst[len] != '\0' && (len < size))
		len++;
	while ((src[i] && (len + i < size - 1)) && size)
	{
		dst[len + i] = src[i];
		i++;
	}
	if (len < size)
		dst[len + i] = 0;
	i = 0;
	while (src[i] != '\0')
		i++;
	return (len + i);
}
