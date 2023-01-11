
// PRINTS HEXA 

#include "ft_printf.h"

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