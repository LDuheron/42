/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 20:28:04 by lduheron          #+#    #+#             */
/*   Updated: 2023/02/25 17:55:37 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putnbr_fd(int nb, int fd)
{
	char	a;
	char	b;

	if (nb == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (nb < 0)
		{
			write(fd, "-", 1);
			nb = -nb;
		}
		b = (nb % 10) + '0';
		if (nb < 10)
		{
			a = nb + '0';
			write(fd, &a, 1);
		}
		else
		{
			ft_putnbr_fd(nb / 10, fd);
			write(fd, &b, 1);
		}
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr2(char *s)
{
	if (s != NULL)
		write(2, s, ft_strlen(s));
}

// void	ft_putstr(char *s)
// {
// 	if (s != NULL)
// 		write(1, s, ft_strlen(s));
// }

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc(sizeof(char) * ft_strlen(src) + 1);
	if (dest == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
