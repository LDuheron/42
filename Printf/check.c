/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:35:18 by lduheron          #+#    #+#             */
/*   Updated: 2023/01/11 13:40:47 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
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

int	main(void)
{
	printf("ABCDE : %d\n", check("abcde"));
	printf("12345 : %d\n", check("12345"));
	printf("AAAA : %d\n", check("AAAA"));
	printf("A1A: %d\n", check("A1A"));
	printf("123+ : %d\n", check("123+"));
	return (0);
}