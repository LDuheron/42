/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:39:19 by lduheron          #+#    #+#             */
/*   Updated: 2022/12/07 16:04:51 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


size_t	ft_strlen(char const *str)
{
	int	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, unsigned int size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && (i + 1) < size)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

char	*ft_strchr(const char *s, int c)
{
	const unsigned char	cpy_c = (unsigned char)c;
	size_t				i;

	i = 0;
	while (s[i] != cpy_c && s[i] != '\0')
		++i;
	if (s[i] == cpy_c)
		return ((char *)(s + i));
	return (NULL);
}

size_t	get_min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			len_s;
	size_t			new_len;
	char			*nchain;

	if (s == NULL)
		nchain = NULL;
	else
	{
		len_s = ft_strlen(s);
		new_len = 0;
		if (start <= len_s)
			new_len = get_min(len_s - start, len);
		else
			start = len_s;
		nchain = malloc((new_len + 1) * sizeof(char));
		if (nchain != NULL)
			ft_strlcpy(nchain, s + start, new_len + 1);
	}
	return (nchain);
}

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
	
	if (!s && !set)
		return (NULL);
	len = ft_strlen(s);
	start = 0;
	i = 0;
	//printf(" STRTRIM ");
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
	//printf("test copy");
	//printf("%s", copy);
	return (copy);
}
