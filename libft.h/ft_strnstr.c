/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:11:01 by lduheron          #+#    #+#             */
/*   Updated: 2022/11/13 11:45:07 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little)
		return (*big);
	while (i < len)
	{
		while (big[i] == little[j])
		{
			i++;
			j++;
		}
		i++;
	}
	return (*big);
}

/*
return (NULL);

*/
