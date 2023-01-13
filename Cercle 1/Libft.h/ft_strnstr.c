/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:11:01 by lduheron          #+#    #+#             */
/*   Updated: 2022/11/24 15:20:47 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	littlelen;

	i = 0;
	j = 0;
	littlelen = ft_strlen(little);
	if (!littlelen || !big)
		return ((char *)big);
	if (len < 0)
		len = ft_strlen(big);
	while (i < len && big[i])
	{
		j = 0;
		while (big[i + j] && big[i + j] == little[j] && (i + j) < len)
		{
			j++;
		}
		if (j == littlelen)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
