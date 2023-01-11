// TEST HEXABASE
//#include "ft_printf.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>


int	hexa_len(unsigned int nb)
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


// void	ft_print_hexa_maj(int nb)
// {
// 	char	*hexa;

// 	hexa = "0123456789ABCDEF";
// 	if (nb <= 15)
// 	{
// 		write(1, &hexa[nb], 1);
// 	}
// 	if (nb > 15)
// 	{
// 		ft_print_hexa_maj(nb / 16);
// 		write(1, &hexa[nb % 16], 1);
// 	}
// }

// char	ft_hexabase(char type, int nb)
// {
// 	char	*hexa = NULL;
// 	char	str[12];
//  	int		i = 0;

// 	printf("\nentree dans hexa min");
// 	if (type == 'x')
// 		hexa = "0123456789abcdef";
// 	else if (type == 'X')
// 		hexa = "0123456789ABCDEF";
// 	if (nb < 15)
// 	{
// 		str[i] = hexa[nb];
// 		i++;
// 	}
// 	if (nb >= 15)
// 	{
// 		ft_hexabase(type, (nb / 16));
// 		str[i] = hexa[nb % 16];
// 		i++;
// 	}
// 	return (*str);
// }

void	ft_print_hexabase(char type, int nb)
{
	char	*hexa;

	if (type == 'x')
		hexa = "0123456789abcdef";
	else if (type == 'X')
		hexa = "0123456789ABCDEF";
	if (nb <= 15)
	{
		write(1, &hexa[nb], 1);
	}
	if (nb > 15)
	{
		ft_print_hexabase(type, nb / 16);
		write(1, &hexa[nb % 16], 1);
	}
}


int	hexaprint(int nb)
{
	ft_print_hexa_maj(nb);
	return (hexa_len(nb));
}

int	main(void)
{
	hexaprint(158);
	printf("\nvrai printf : %X", 158); 
	//ft_hexabase('x', 158);
	return (0);
}

// int	ft_print_hexa(char type, int nb)
// {
// 	char	*str = NULL;
// 	int		len;

// 	str = ft_hexabase(type, nb);
// 	len = ft_printf_str(str);
// 	return (len);
// }


// // VERIFIER LE TYPE A PRINT
// int	ft_type(va_list params, char type)
// {
// 	static int	len;
// 	int i = 0;;

// 	len = 1;

// 	if (type == 'x' || type == 'X')
// 		len = ft_print_hexa(type, va_arg(params, int));
// 	i = len;
// 	len = 0;
// 	return (i);
// }

// // "MAIN" FUNCTION retourner le nombre de caractere print en fin
// int	ft_printf(const char *v0, ...)
// {
// 	va_list	params;
// 	int		i;
// 	int		len;

// 	i = 0;
// 	len = 0;
// 	va_start(params, v0);
// 	while (v0[i] != '\0')
// 	{
// 		if (v0[i] == '%')
// 		{
// 		//	printf("\nlen dans print f : %u\n", len);
// 			i++;
// 			len += ft_type(params, v0[i]);
// 		}
// 		else
// 		{
// 			write(1, &v0[i], 1);
// 			len++;
// 		//	printf("\nlen dans type : %u\n", len);
// 		}
// 		i++;
// 	}
// 	va_end(params);
// 	return (len);
// }

// int	main(void)
// // {
// // 	printf("Vrai printf : %x", 158);
// // 	ft_printf("Mon printf : %x", 158);
// 	return (0);
// }