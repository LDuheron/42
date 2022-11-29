/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:07:45 by lduheron          #+#    #+#             */
/*   Updated: 2022/11/24 09:18:55 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const unsigned char	cpy_c = (unsigned char)c;
	size_t				i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
		i++;
	while (s[i] != c && s[i] >= 0 && i > 0)
		i--;
	if (s[i] == cpy_c)
		return ((char *)(s + i));
	return (0);
}
