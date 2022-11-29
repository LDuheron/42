/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:50:26 by lduheron          #+#    #+#             */
/*   Updated: 2022/11/10 18:50:31 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
