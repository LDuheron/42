/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 12:02:12 by lduheron          #+#    #+#             */
/*   Updated: 2022/11/28 20:19:42 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*scopy;
	size_t	i;

	scopy = (malloc(ft_strlen(s) + 1));
	if (!(scopy))
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (f == NULL)
			scopy[i] = s[i];
		else
			scopy[i] = f(i, s[i]);
		i++;
	}
	scopy[i] = '\0';
	return (scopy);
}
