/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:27:21 by lduheron          #+#    #+#             */
/*   Updated: 2022/11/28 15:18:24 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	nblen(int n)
{
	size_t			i;
	unsigned int	nb;

	i = 0;
	nb = n;
	if (n < 0)
	{
		nb *= -1;
		i++;
	}
	while (nb != 0 || i == 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	size_t	i;
	char	*s;
	size_t	len;
	long	nb;

	len = nblen(n);
	nb = n;
	s = malloc(len + 1);
	if (!(s))
		return (0);
	i = 0;
	if (n < 0)
	{
		s[i++] = '-';
		nb *= -1;
	}
	s[len] = 0;
	while (len > i)
	{
		s[--len] = nb % 10 + '0';
		nb /= 10;
	}
	return (s);
}
