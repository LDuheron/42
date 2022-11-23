/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:56:28 by lduheron          #+#    #+#             */
/*   Updated: 2022/11/23 17:59:40 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

int	check(char const *s1, char const *set, int v)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (s1[v] == set[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*copies1;
	size_t	i;
	int		j;
	size_t	len;

	i = 0;
	j = 0;
	len = ft_strlen(s1);
	if (check(s1, set, (len - 1)))
		len--;
	if (check(s1, set, 0) == 1)
	{
		len--;
		i++;
	}
	copies1 = malloc((len + 1) * sizeof(int));
	if (!(copies1))
		return ("NULL");
	while (i <= (len) && s1[i])
	{
		copies1[j] = s1[i];
		j++;
		i++;
	}
	return (copies1);
}
