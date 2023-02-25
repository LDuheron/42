/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 20:28:53 by lduheron          #+#    #+#             */
/*   Updated: 2023/02/22 20:28:54 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexabase(char type, unsigned int nb)
{
	char	*hexa;

	if (type == 'x')
		hexa = "0123456789abcdef";
	else if (type == 'X')
		hexa = "0123456789ABCDEF";
	if (nb <= 15)
		return (write(1, &hexa[nb], 1));
	if (nb > 15)
		return (ft_print_hexabase(type, nb / 16) + write(1, &hexa[nb % 16], 1));
	return (0);
}

int	ft_hexa_p(char type, size_t nb)
{
	char	*hexa;

	if (type == 'x')
		hexa = "0123456789abcdef";
	else if (type == 'X')
		hexa = "0123456789ABCDEF";
	if (nb <= 15)
		return (write(1, &hexa[nb], 1));
	if (nb > 15)
		return (ft_hexa_p(type, nb / 16) + write(1, &hexa[nb % 16], 1));
	return (0);
}

int	ft_print_p(size_t p)
{
	int	len;

	if (p == 0)
		return (write(1, "(nil)", 5));
	len = write(1, "0x", 2);
	len += ft_hexa_p('x', p);
	return (len);
}

int	ft_print_s(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		return (write(1, "(null)", 6));
	}
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}
