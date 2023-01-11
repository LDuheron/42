#include "libft.h"

int	ft_print_hexa_min(int nb)
{
	char	*hexa;
	char	storage[17];
	int		len;

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
	char	*hexa;
	char	storage[17];
	int		len;

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
