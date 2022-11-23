/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 12:02:12 by lduheron          #+#    #+#             */
/*   Updated: 2022/11/13 12:02:14 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*scopie;
	int		i;

	i = 0;
	scopie = (malloc(ft_strlen(s) + 1));
	if (!(scopie))
		return ("NULL");
	while (s[i])
	{
		scopie[i] = f(i, s[i]);
		i++;
	}
	scopie[i] = '\0';
	return (scopie);
}
