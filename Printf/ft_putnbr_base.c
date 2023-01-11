/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:56:59 by lduheron          #+#    #+#             */
/*   Updated: 2023/01/11 14:09:00 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <stdio.h>

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_strlen(char const *str)
{
	int	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

int	check(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ft_strlen(base) < 2)
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || ft_isprint(base[i]) == 0)
			return (0);
		j = i + 1;
		while (j < ft_strlen(base))
		{
			if (base[i] == base[j])
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_putnbr_base(int nb, char *base)
{
	long int nb_cpy;

	if (!check(base) || check(base) == 0)
		return (0);
	if (nb == 0)
	{
		ft_putchar(base[0]);
		//return (1);
	}
	nb_cpy = (long int)nb;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb != 0)
	{
		if ((nb / ft_strlen(base)) != 0)
		{
			ft_putnbr_base(nb_cpy / ft_strlen(base), base);
		}
		ft_putchar(base[nb_cpy % ft_strlen(base)]);
	}
	
	return (1);
}

int	main(void)
{
	ft_putnbr_base(40, "0123456789abcdef");
	write(1, "\n", 1);
	ft_putnbr_base(31, "0123456789abcdef");

	// // TEST CHECK BASE
	// printf("ABCDE : %d\n", check("abcde"));
	// printf("12345 : %d\n", check("12345"));
	// printf("AAAA : %d\n", check("AAAA"));
	// printf("A1A: %d\n", check("A1A"));
	// printf("123+ : %d\n", check("123+"));
	// // TEST FT_PUTNBR_BASE
// 	printf("28 : %d\n", ft_putnbr_base(40, "0123456789abcdef"));
// 	printf("1f : %d\n", ft_putnbr_base(31, "0123456789abcdef"));
// 	printf("1111 : %d\n", ft_putnbr_base(15, "01"));
// 	printf("-15 : %d\n", ft_putnbr_base(-15, "0123456789"));
// 	printf("-1000 : %d\n",ft_putnbr_base(-16, "01"));
// //$expected = '-15-10000';
// 	printf("-7fffffff-80000000: %d", ft_putnbr_base(2147483647, "0123456789abcdef"));
// 	printf(" last : %d", ft_putnbr_base(-2147483648, "0123456789abcdef"));
// //$expected = '7fffffff-80000000';
	return (0);
}


// {
// 	char	a;
// 	char	b;

// 	if (nb == -2147483648)
// 		write(fd, "-2147483648", 11);
// 	else
// 	{
// 		if (nb < 0)
// 		{
// 			write(fd, "-", 1);
// 			nb = -nb;
// 		}
// 		b = (nb % 10) + '0';
// 		if (nb < 10)
// 		{
// 			a = nb + '0';
// 			write(fd, &a, 1);
// 		}
// 		else
// 		{
// 			ft_putnbr_fd(nb / 10, fd);
// 			write(fd, &b, 1);
// 		}
// 	}
// }
// }