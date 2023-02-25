/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:25:37 by lduheron          #+#    #+#             */
/*   Updated: 2023/01/12 13:53:02 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_unsigned_nbr(unsigned int nb)
{
	if (nb >= 10)
	{
		ft_print_unsigned_nbr(nb / 10);
		ft_print_unsigned_nbr(nb % 10);
	}
	else
		ft_print_c(nb + '0');
}

int	nb_u_len(unsigned int nb)
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

int	ft_u_nbr(unsigned int nb)
{
	unsigned int	nb_cpy;
	int				len;

	len = 0;
	nb_cpy = nb;
	if (nb == 0)
	{
		write(1, "0", 1);
		len += 1;
	}
	else
	{
		ft_print_unsigned_nbr(nb);
		len += nb_u_len(nb_cpy);
	}
	return (len);
}
