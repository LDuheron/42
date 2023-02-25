/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_i_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:24:42 by lduheron          #+#    #+#             */
/*   Updated: 2023/01/12 13:52:38 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	max_nb(int nb)
{
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	return (12);
}

void	ft_print_nbr(int nb)
{
	if (nb == -2147483648)
		max_nb(nb);
	else
	{
		if (nb < 0)
		{
			write(1, "-", 1);
			nb = -nb;
		}
		if (nb >= 10)
		{
			ft_print_nbr(nb / 10);
			ft_print_nbr(nb % 10);
		}
		else
			ft_print_c(nb + '0');
	}
}

int	nb_len(int nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}

int	ft_nbr(int nb)
{
	long long int	nb_cpy;
	int				len;

	len = 0;
	nb_cpy = nb;
	if (nb < 0)
		len += 1;
	if (nb == 0)
	{
		write(1, "0", 1);
		len += 1;
	}
	else
	{
		ft_print_nbr(nb);
		len += nb_len(nb_cpy);
	}
	return (len);
}
