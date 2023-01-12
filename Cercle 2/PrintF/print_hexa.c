/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:28:02 by lduheron          #+#    #+#             */
/*   Updated: 2023/01/12 13:46:27 by lduheron         ###   ########.fr       */
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
