
#include "ft_printf.h"
// fonctons autorisees : malloc, free, write, va_start, va_arg, va_copy, va_end

// POINTEUR 
// int	ft_print_pointer(void const *p)
// {
// 	int				len;
// 	//unsigned long long		adress;

// 	len = 2;
// //	adress = (unsigned long long) p;
// 	if ((unsigned long long) p == 0)
// 	{
// 		write(1, "(nil)", 5);
// 		return (5);
// 	}
// 	write(1, "0x", 2);
// 	len += ft_print_hexa('x',(unsigned long long)p);
// 	return (len);
// }
	// else if (type == 'p')
	// 	len = ft_print_pointer(va_arg(params, void const *));


// HEXA

int	hexa_len(unsigned int nb)
{
	int	len;

	len = 0;
//printf("nb : %d\n", nb);
	while (nb != 0)
	{
		len++;
		nb = nb / 16;
		//printf("len : %d\n", len);
	}
	return (len);
}


void	ft_print_hexabase(char type, int nb)
{
	char	*hexa;

	if (type == 'x')
		hexa = "0123456789abcdef";
	else if (type == 'X')
		hexa = "0123456789ABCDEF";
	// if (nb <= 9)
	// 	write(1, &hexa[nb], 1);
	if (nb <= 15)
		write(1, &hexa[nb], 1);
	if (nb > 15)
	{
		ft_print_hexabase(type, nb / 16);
		write(1, &hexa[nb % 16], 1);
	}
}

int	ft_hexa(char type, int nb)
{
	int	nb_cpy;
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

// LES PRINTS
int	ft_printchar(char c)
{
	int	len;

	len = 1;
	write(1, &c, 1);
	return (len);
}

int	ft_printf_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

// PRINT NBR


int	max_nb(int nb)
{
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	return (11);
}

int	ft_print_nbr(int nb)
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
			ft_printchar(nb + '0');
	}
	return (0);
}

int	ft_print_unsigned_nbr(unsigned int nb)
{
	if (nb >= 10)
	{
		ft_print_unsigned_nbr(nb / 10);
		ft_print_unsigned_nbr(nb % 10);
	}
	else
		ft_printchar(nb + '0');
	//printf("\nlen dans print unsigned nbr : %u\n", len);
	return (0);
}

int	ft_nbr(int nb)
{
	int	nb_cpy;
	int	len;

	nb_cpy = nb;
	// if (nb == 0)
	// {
	// 	write(1, "0", 1);
	// 	len = 1;
	// }
	ft_print_nbr(nb);
	len = hexa_len(nb_cpy);
	return (len);
}


// VERIFIER LE TYPE A PRINT
int	ft_type(va_list params, char type)
{
	int	len;
	int	nb_cpy;
	
	len = 1;
	if (type == 'c') // ok
		len = ft_printchar(va_arg(params, int));
	else if (type == 's')
		len = ft_printf_str(va_arg(params, char *));
	else if (type == 'd' || type == 'i')
	{
		nb_cpy = va_arg(params, int);
		ft_print_nbr(va_arg(params, int));	
		len = hexa_len(nb_cpy);
	}
	else if (type == 'u')
	{
		nb_cpy = va_arg(params, unsigned int);
		ft_print_unsigned_nbr((unsigned int)va_arg(params, unsigned int));
		len = hexa_len(nb_cpy);
	}
	else if (type == 'x' || type == 'X')
	{
		len = ft_hexa(type, va_arg(params, unsigned int));	
	}
	else if (type == '%') // ok
		write(1, "%", 1);
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
