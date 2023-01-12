/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:56:28 by lduheron          #+#    #+#             */
/*   Updated: 2022/11/28 20:04:19 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check(char const *set, const char curr_c)
{
	if (curr_c != '\0' && ft_strchr(set, curr_c) != NULL)
		return (1);
	return (0);
}

char	*ft_strtrim(char const *s, char const *set)
{
	char			*copy;
	size_t			i;
	size_t			len;
	size_t			start;

	len = ft_strlen(s);
	start = 0;
	i = 0;
	if (len > 0)
	{
		while (check(set, s[start]) == 1)
			++start;
		while (i < len && check(set, s[len - i - 1]) == 1)
			++i;
	}
	copy = ft_substr(s, start, (len - i - start));
	if (copy == NULL)
		return (NULL);
	return (copy);
}
