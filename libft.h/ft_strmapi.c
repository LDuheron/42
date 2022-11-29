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
	char	*scopie;
	size_t	i;

	scopie = (malloc(ft_strlen(s) + 1));
	if (!(scopie))
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (f == NULL)
			scopie[i] = s[i];
		else
			scopie[i] = f(i, s[i]);
		i++;
	}
	scopie[i] = '\0';
	return (scopie);
}
