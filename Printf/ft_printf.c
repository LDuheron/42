/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:15:44 by lduheron          #+#    #+#             */
/*   Updated: 2023/01/11 11:54:06 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// fonctons autorisees : malloc, free, write, va_start, va_arg, va_copy, va_end

//POINTEUR 

int	ft_conv_pointeur(char type, unsigned long long int nb)
{
	long long int	nb_cpy;	
	int	len;

	len = 0;
	nb_cpy = nb;
	if (nb == 0)
	{
		write(1, "0", 1);
		len = 1;
	}
	else
	{
		ft_print_hexabase(type, nb);
		len = hexa_len(nb_cpy);
		//printf("len dans conv pointeur %i", len);
	}
	return (len);
}

int	ft_print_pointer(unsigned long long int p)
{
	int	len;


	len = 2;
	if (p == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	len += ft_conv_pointeur('x', p);
	return (len);
}
	// 

// LES PRINTS
int	ft_printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printf_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
			write(1, "(null)", 6);
		return (6);
	}
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		//free (&str[i]);
		i++;
	}
	return (i);
}

// PRINT NBR
int	max_nb(int nb)
{
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	return (12);
}

int	ft_print_nbr(int nb)
{
	int len = 0;

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
			ft_printchar(nb + '0');
	}
	return (len);
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
	int	len = 0;

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
		len += ft_print_nbr(nb);
		len += nb_len(nb_cpy);
	}
	return (len);
}

// PRINT UNSIGNED NBR

int	ft_print_unsigned_nbr(unsigned int nb)
{
	int	len = 0;

	if (nb >= 10)
	{
		ft_print_unsigned_nbr(nb / 10);
		ft_print_unsigned_nbr(nb % 10);
	}
	else
		len += ft_printchar(nb + '0');
	//printf("\nlen dans print unsigned nbr : %u\n", len);
	return (len);
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
	int	len = 0;

	nb_cpy = nb;
	if (nb == 0)
	{
		write(1, "0", 1);
		len += 1;
	}
	else
	{
		len += ft_print_unsigned_nbr(nb);
		len += nb_u_len(nb_cpy);
	}
	return (len);
}

// PRINTS HEXA 

int	hexa_len(long long int nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		len++;
		nb = nb / 16;
	}
	return (len);
}


void	ft_print_hexabase(char type, long long int nb)
{
	char	*hexa;

	if (type == 'x')
		hexa = "0123456789abcdef";
	else if (type == 'X')
		hexa = "0123456789ABCDEF";
	if (nb <= 15)
		write(1, &hexa[nb], 1);
	if (nb > 15)
	{
		ft_print_hexabase(type, nb / 16);
		write(1, &hexa[nb % 16], 1);
	}
}

int	ft_hexa(char type, long long int nb)
{
	long long int	nb_cpy;
	int	len;

	nb_cpy = nb;
	if (nb == 0)
	{
		write(1, "0", 1);
		len = 1;
	}
	else
	{
		ft_print_hexabase(type, nb);
		len = hexa_len(nb_cpy);
	}
	return (len);
}

// VERIFIER LE TYPE A PRINT
int	ft_type(va_list params, char type)
{
	int	len;

	len = 1;
	if (type == 'c') // ok
		len = ft_printchar(va_arg(params, int));
	else if (type == 's')
		len = ft_printf_str(va_arg(params, char *));
	else if (type == 'd')
		len = ft_nbr(va_arg(params, int));
	else if (type == 'i')
		len = ft_nbr(va_arg(params, int));
	else if (type == 'u')
		len = ft_u_nbr(va_arg(params, unsigned int));
	else if (type == 'x' || type == 'X')
		len = ft_hexa(type, va_arg(params, long long int));	
	else if (type == 'p')
	 	len = ft_print_pointer(va_arg(params, unsigned long long int));
	else if (type == '%') // ok
		write(1, "%", 1);
	//printf("\nlen dans type : %u\n", len);
	return (len);
}

// "MAIN" FUNCTION retourner le nombre de caractere print en fin
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
		//	printf("\nlen dans print f : %u\n", len);
			i++;
			len += ft_type(params, v0[i]);
		}
		else
		{
			write(1, &v0[i], 1);
			len++;
		//	printf("\nlen dans type : %u\n", len);
		}
		i++;
	}
	va_end(params);
	return (len);
}

// int	main(void)
// {

// }

// int	main(void)
// {
// 	 ft_printf("This %p is even stranger", -1);
// 	 printf("This %p is even stranger", -1);
// }



// int main(void)
// {
// 	char *null_str = NULL;

// 	printf("%s", null_str);
// 	printf("%c", '\n');
// 	printf("%s everywhere", null_str);
// 	printf("%c", '\n');
// 	printf("everywhere %s", null_str);
// 	return (0);
// }


// {
// 	char *test = NULL;

// 	test = "abc";
// 	printf("%p\n", &test);
// 	ft_printf("%p", &test);
// 	return (0);
// }
// int main(void)
// {
// 	int i;
// 	int	j;

//  	j = ft_printf("%dxC is the lowest temperature in the universe", -273);
// 	write(1, "\n", 1);
// 	i = printf("%dxC is the lowest temperature in the universe", -273);
// 	write(1, "\n", 1);
// 	printf("Vrai pf return : %X\n", i);
//  	write(1, "\n", 1);
// 	printf("Mon pf return : %X\n", j);
// 	return (0);
// }

// int	main(void)
// {
// 	int i;
// 	int	j;
// 	i = ft_printf("%u\n", 2147483647);
// 	j = printf("%u\n", 2147483647);
// 	printf("%u\n", i);
// 	write(1, "\n", 1);
// 	printf("%u\n", j);
// 	return (0);
// }
// printf("%d", printf("TEST PRINT F\n"));
