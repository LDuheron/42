/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 12:03:34 by lduheron          #+#    #+#             */
/*   Updated: 2022/11/28 18:35:03 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	no_sep(char const *s, char c)
{
	long	i;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (!(*s))
			break ;
		i++;
		while (*s && *s != c)
			s++;
	}
	return (i);
}

static char	*asdup(char const *s, char c)
{
	long	len;
	char	*sa;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	sa = malloc(len + 1);
	if (!sa)
		return (NULL);
	sa[len] = 0;
	while (len > 0)
	{
		sa[len - 1] = s[len - 1];
		len -= 1;
	}
	return (sa);
}

static void	lefree(char **aos, long i)
{
	while (i)
	{
		free (aos[i]);
		i--;
	}
	free (aos);
}

char	**ft_split(char const *s, char c)
{
	char	**aos;
	long	n;

	n = 0;
	aos = malloc((no_sep (s, c) + 1) * sizeof (char *));
	if (!aos)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (!(*s))
			break ;
		aos[n++] = asdup(s, c);
		if (!aos[n - 1])
		{
			lefree(aos, n);
			return (aos);
		}
		while (*s && *s != c)
			s++;
	}
	aos[n] = NULL;
	return (aos);
}

/*
int	wdcount(char const *s, char c)
{
	int	i;
	int	cpt;

	i = 0;
	cpt = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			cpt++;
			i++;
		}
		while (s[i] != c && s[i])
			i++;
	}
	return (cpt);
}

char	*ftdup(char const *src, char c)
{
	int		i;
	char	*dest;
	int		cpt;

	i = 0;
	cpt= 0;
	while (src[i] != c)
	{
		cpt++;
		i++;
	}
	dest = malloc(sizeof(char) * cpt + 1);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i != cpt)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static void	frees(char **buffer, int i)
{
	while (i != '\0')
	{
		free (buffer[i]);
		i--;
	}
	free (buffer);
}

char	**ft_split(char const *s, char c)
{
	char	**buffer;
	int		i;
	int a;
	i = wdcount(s, c);
	a = 0;
//	printf("%s\n","okwd");
	a = ft_strlen(s);
	buffer = malloc(ft_strlen(s + 1) * sizeof(char *));
	//	printf("%s\n","okbuff");
	if (!buffer)
		return (NULL);
	//printf("%s\n","okpro");
	while (i<a)
	{
			//printf("%s\n","okboucle");
		while (s[i] == c && s[i])
			i++;
		if (!s)
			break;
		buffer[i] = ftdup(s, c);
			//printf("%s\n","okbuff2");
		if (!buffer[i])
		{
			//	printf("%s\n","okfree");
			frees(buffer, i);
		//	printf("%s\n","oksortiefree");
			return (buffer);
		}
	//	printf("%s\n","okpreboucle");
		while (s[i] != c && s[i])
			i++;
			//printf("%s\n","okboucleeee");
	}
	//printf("%s\n","oksortie");
	*buffer[i] = '\0';
	//printf("%s\n","oksortie2");
	return (buffer);
}


int    ft_strlen(char const *str)
{
    int    len;

    len = 0;
    while (str[len])
    {
        len++;
    }
    return (len);
}

int    wdcount(char const *s, char c)
{
    int    i;
    int    cpt;

    i = 0;
    cpt = 0;
    while (s[i])
    {
        while (s[i] == c)
            i++;
        if (s[i] != c && s[i])
        {
            cpt++;
            i++;
        }
        while (s[i] != c && s[i])
            i++;
    }
    return (cpt);
}

char    *ftdup(char const *src, char c)
{
    int        i;
    char    *dest;
    int        cpt;

    i = 0;
    cpt= 0;
    while (src[i] != c)
    {
        cpt++;
        i++;
    }
    dest = malloc(sizeof(char) * cpt + 1);
    if (dest == NULL)
        return (NULL);
    i = 0;
    while (i != cpt)
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

static void    frees(char **buffer, int i)
{
    while (i != '\0')
    {
        free (buffer[i]);
        i--;
    }
    free (buffer);
}

char    **ft_split(char const *s, char c)
{
    char    **buffer;
    int        i;

    i = wdcount(s, c);
    printf("%s\n","okwd");
    buffer = malloc(ft_strlen(s + 1) * sizeof(char *));
    printf("%s\n","okbuff");
    if (!buffer)
        return (NULL);
    printf("%s\n","okpro");
    while (s[i] && s)
    {
        printf("%s\n","okboucle");
        while (s[i] == c && s[i])
            i++;
        if (!s)
            break;
        buffer[i] = ftdup(s, c);
        printf("%s\n","okbuff2");
        if (!buffer[i])
        {
          printf("%s\n","okfree");
          frees(buffer, i);
          printf("%s\n","oksortiefree");
          return (buffer);
        }
        printf("%s\n","okpreboucle");
        while (s[i] != c && s[i])
            i++;
        printf("%s\n","okboucleeee");
    }
    printf("%s\n","oksortie");
    *buffer[i] = '\0';
    printf("%s\n","oksortie2");
    return (buffer);
}

int main(void)
{
    ft_split("ceci est uniti",'i');
    return(0);
}









int main(void)
{
	ft_split("ceci est uni testi de sepqrti",'i');
	return(0);
}
		// tant que sep -> avance
		// si ! sep -> strlen( du mot, !! separateurs)
		// malloc de ce strlen
		// si echec attention
		// return tes mallocs
		/// i + ft_strlen(strdup());
	
if (!buffer[i - 1])
		{
				//printf("%s\n","okfree");
			frees(buffer, i);
			//printf("%s\n","oksortiefree");
			return (buffer);
		}

char	**ft_split(char const *s, char c)
{
	char	**buffer;
	int		i;

	i = wdcount(s, c);
//	printf("%s\n","okwd");
	buffer = malloc(ft_strlen(s+1) * sizeof(char *));
	//	printf("%s\n","okbuff");
	if (!buffer)
		return (NULL);
	//printf("%s\n","okprot");
	while (i < ft_strlen(s))
	{
			//printf("%s\n","okboucle");
		while (s[i] == c && s[i])
			i++;
		if (!s)
			break;
		buffer[i] = ftdup(s, c);
			printf("%s\n","okbuff2");
		if (!buffer[i])
		{
				printf("%s\n","okfree");
			frees(buffer, i);
			printf("%s\n","oksortiefree");
			return (buffer);
		}
		printf("%s\n","okpreboucle");
		while (s[i] != c && s[i])
			i++;
		printf("%s\n","okboucleeee");
	}
	printf("%s\n","oksortie");
	*buffer[i] = '\0';
	printf("%s\n","oksortie2");
	return (buffer);
}
*/
