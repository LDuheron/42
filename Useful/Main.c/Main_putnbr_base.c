int	main(void)
{
	// TEST CHECK BASE
	printf("ABCDE : %d\n", check("abcde"));
	printf("12345 : %d\n", check("12345"));
	printf("AAAA : %d\n", check("AAAA"));
	printf("A1A: %d\n", check("A1A"));
	printf("123+ : %d\n", check("123+"));
	
	// TEST FT_PUTNBR_BASE
	printf("28 : %d", ft_putnbr_base(40, "0123456789abcdef"));
	printf("1f : %d", ft_putnbr_base(31, "0123456789abcdef"));
	printf("1111 : %d", ft_putnbr_base(15, "01"));

	printf("-15 : %d", ft_putnbr_base(-15, "0123456789"));
	printf("-1000 : %d",ft_putnbr_base(-16, "01"));

//$expected = '-15-10000';
	printf("-7fffffff-80000000: %d"ft_putnbr_base(2147483647, "0123456789abcdef");
	printf(" last : %d", ft_putnbr_base(-2147483648, "0123456789abcdef");

//$expected = '7fffffff-80000000';

	return (0);
}
