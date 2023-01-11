#include "libftprintf.h"

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
	else if (type == 'd' || type == 'i')
		len = ft_print_nbr(va_arg(params, int));
	else if (type == 'u')
		len = ft_print_unsigned_nbr((unsigned int)va_arg(params, unsigned int));
	else if (type == 'x')
		len = ft_print_hexa_min(va_arg(params, int));
	else if (type == 'X')
		len = ft_print_hexa_maj(va_arg(params, int));
	else if (type == '%')
		len = printchar("%");
	return (len);
}

// "MAIN" FUNCTION retourner le nombre de caractere print en fin
int	ft_printf(const char *v0, ...)
{
	va_list	params;
	int		i;
	int		len;

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

int	main(void)
{
	return (0);
}
