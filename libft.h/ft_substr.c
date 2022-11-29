/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:13:03 by lduheron          #+#    #+#             */
/*   Updated: 2022/11/29 12:15:11 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	const size_t	len_s = ft_strlen(s);
	size_t			new_len;
	char			*nchain;

	if (s == NULL)
		nchain = NULL;
	else
	{
		if (start <= len_s)
			new_len = get_min(len_s - start, len);
		else
			new_len = 0;
		nchain = malloc((new_len + 1) * sizeof(char));
		if (nchain != NULL)
			ft_strlcpy(nchain, s + start, new_len + 1);
	}
	return (nchain);
}
