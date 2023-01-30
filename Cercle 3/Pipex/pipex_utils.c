
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <limits.h>
# include <stdint.h>



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

static char	*ftdup(char const *s, char c)
{
	long	len;
	char	*scopy;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	scopy = malloc(len + 1);
	if (!scopy)
		return (NULL);
	scopy[len] = 0;
	while (len > 0)
	{
		scopy[len - 1] = s[len - 1];
		len -= 1;
	}
	return (scopy);
}

static void	ftfree(char **buffer, long i)
{
	while (i)
	{
		free (buffer[i]);
		i--;
	}
	free (buffer);
}

char	**ft_split(char const *s, char c)
{
	char	**buffer;
	long	i;

	i = 0;
	buffer = malloc((wdcount(s, c) + 1) * sizeof (char *));
	if (!buffer)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (!(*s))
			break ;
		buffer[i++] = ftdup(s, c);
		if (!buffer[i - 1])
		{
			ftfree(buffer, i);
			return (buffer);
		}
		while (*s && *s != c)
			s++;
	}
	buffer[i] = NULL;
	return (buffer);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < (n - 1))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
