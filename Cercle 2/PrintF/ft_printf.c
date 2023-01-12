/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:43:19 by lduheron          #+#    #+#             */
/*   Updated: 2023/01/12 13:45:16 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_c(char c)
{
	return (write(1, &c, 1));
}

int	ft_type(va_list params, char type)
{
	int	len;

	len = 0;
	if (type == 'c')
		len = ft_print_c(va_arg(params, int));
	else if (type == 's')
		len = ft_print_s(va_arg(params, char *));
	else if (type == 'd' || type == 'i')
		len = ft_nbr(va_arg(params, int));
	else if (type == 'u')
		len = ft_u_nbr((unsigned int)va_arg(params, unsigned int));
	else if (type == 'x' || type == 'X')
		len = ft_print_hexabase(type, va_arg(params, unsigned int));
	else if (type == 'p')
		len = ft_print_p(va_arg(params, size_t));
	else if (type == '%')
		len = write(1, "%", 1);
	return (len);
}

int	ft_printf(const char *v0, ...)
{
	va_list	params;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(params, v0);
	while (v0[i] != '\0')
	{
		if (v0[i] == '%')
		{
			i++;
			len += ft_type(params, v0[i]);
		}
		else
		{
			write(1, &v0[i], 1);
			len++;
		}
		i++;
	}
	va_end(params);
	return (len);
}
