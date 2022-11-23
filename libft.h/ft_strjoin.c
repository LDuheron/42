/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 12:03:47 by lduheron          #+#    #+#             */
/*   Updated: 2022/11/13 12:03:49 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_taille(int size, char **strs, char *sep)
{
	int	i;
	int	res;
	int	total;

	i = 0;
	res = 0;
	while (i < size)
	{
		res = res + ft_strlen(strs[i]);
		i++;
	}
	total = (size - 1) * ft_strlen(sep) + res + 1;
	return (total);
}

char	*ft_tabl(int size, char **strs, char *sep, char *tab)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			tab[k++] = strs[i][j++];
		j = 0;
		while (sep[j] && i + 1 < size)
			tab[k++] = sep[j++];
		i++;
	}
	tab[k] = '\0';
	return (tab);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*tab;

	if (size == 0)
	{
		tab = malloc(sizeof(char));
		return (tab);
	}
	tab = malloc(sizeof(char) * ft_taille(size, strs, sep));
	if (tab == NULL)
		return (NULL);
	return (ft_tabl(size, strs, sep, tab));
}
