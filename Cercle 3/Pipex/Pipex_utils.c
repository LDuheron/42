void	*ft_memset(void *s, int value, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = ((unsigned char)value);
		i++;
	}
	return (s);
}

ajouter un strdup 
