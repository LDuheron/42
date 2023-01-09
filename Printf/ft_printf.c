// fonctons autorisees : malloc, free, write, va_start, va_arg, va_copy, va_end
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

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

int max_nb(int nb)
{
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	return (11);
}

int	ft_print_nbr(int nb)
{
	static int	len;

	len = 0;
	if (nb == -2147483648)
		max_nb(nb);
	else
	{
		if (nb < 0)
		{
			write(1, "-", 1);
			len++;
			nb = -nb;
		}
		if (nb >= 10)
		{
			ft_print_nbr(nb / 10);
			ft_print_nbr(nb % 10);
		}
		else 
			len += ft_printchar(nb + '0');
	}
	return (len);
}

int	ft_print_unsigned_nbr(unsigned int nb)
{
	static int	len;

	len = 0;
	if (nb >= 10)
	{
		ft_print_unsigned_nbr(nb / 10);
		ft_print_unsigned_nbr(nb % 10);
	}
	else 
		len += ft_printchar(nb + '0');
	return (len);
}


// PRINT HEXA 
int	ft_print_hexa_min(int nb)
{
	char *hexa;
	char storage[17];
	int	len;

	hexa = "0123456789abcdef";
	if (nb < 15)
	{
		write(1, &hexa[nb], 1);
		len++;
	}
	if (nb >= 15)
	{
		ft_print_hexa_min(nb / 16);
		write(1, &hexa[nb % 16], 1);
		len++;
	}
	return (len);
}

int	ft_print_hexa_maj(int nb)
{
	char *hexa;
	char storage[17];
	int	len;

	hexa = "0123456789ABCDEF";
	if (nb < 15)
	{
		write(1, &hexa[nb], 1);
		len++;
	}
	if (nb >= 15)
	{
		ft_print_hexa_maj(nb / 16);
		write(1, &hexa[nb % 16], 1);
		len++;
	}
	return (len);
}

int ft_print_pointer(void const *p)
{
	int len;
	unsigned long long adress;

	len = 2;
	if (&adress == NULL)
		write(1, "nil", 3);
		return (3);
	write(1, "0x", 2);
	adress = (unsigned long long) p;
	len += ft_print_hexa_min(adress);
	return (len);
}

// VERIFIER LE TYPE A PRINT
int	ft_type(va_list params, char type)
{
	int	len;
	
	len = 0;
	if (type == 'c')
		len = ft_printchar(va_arg(params, int));
	else if (type == 's')
		len = ft_printf_str(va_arg(params, char *));
	else if (type == 'p')
		len = ft_print_pointer(va_arg(params, void const *));
	else if (type == 'd'|| type == 'i')
		len = ft_print_nbr(va_arg(params, int));
	//
	else if (type == 'u')
		len = ft_print_nbr(va_arg(params, int));
	//
	else if (type == 'x')
		len = ft_print_hexa_min(va_arg(params, int));
	else if (type == 'X')
		len = ft_print_hexa_maj(va_arg(params, int));
	else if (type == '%')
		len = printchar("%")
	return (len);
}

// "MAIN" FUNCTION (retourner le nombre de caractere print en fin)
int ft_printf(const char *v0, ...)
{
	va_list params;
	int i;
	int	len;

	i = 0;
	va_start(params, v0);
	while (v0[i] != '\0')
	{
		if (v0[i] == '%')
		{
			i++;
			len += ft_type(params, v0[i]);
		}
		else 
			write(1, &v0[i], 1);
			len++;
		i++;
	}
	va_end(params);
	return (len);
}

int main(void)
{
	//printf("%d", printf("TEST PRINT F\n"));
	return (0);
}

// null renvoie nill
