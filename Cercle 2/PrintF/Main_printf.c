#include <limits.h>

int main(void)
{
	int i;
	int j;
// TEST ADRESSE POINTEUR
	char *test = NULL;

	test = "abc";
	printf("%p\n", test);
	ft_printf("%p", test);

// BASES HEXA
	printf("TEST PRINT F BASE HEXA\n");
	
	i = printf("Vrai printf : %x\n", 0);
	ft_print_hexa_min(0);
	write(1, "\n", 1);
	j = ft_printf("Mon printf : %x", 0);
	printf("%d : %d\n", i, j);
	write(1, "\n", 1);
	printf("Vrai printf : %X\n", 0);
	ft_print_hexa_maj(0);
	write(1, "\n", 1);
	ft_printf("Mon printf : %X", 0);
	write(1, "\n", 1);

	printf("Vrai printf : %x\n", 3);
	ft_print_hexa_min(3);
	write(1, "\n", 1);
	ft_printf("Mon printf : %x", 3);
	write(1, "\n", 1);
	printf("Vrai printf : %X\n", 3);
	ft_print_hexa_maj(3);
	write(1, "\n", 1);
	ft_printf("Mon printf : %X", 3);
	write(1, "\n", 1);

	printf("Vrai printf : %x\n", 10);
	ft_print_hexa_min(10);
	write(1, "\n", 1);
	ft_printf("Mon printf : %x", 10);
	write(1, "\n", 1);
	printf("Vrai printf : %X\n", 10);
	ft_print_hexa_maj(10);
	write(1, "\n", 1);
	ft_printf("Mon printf : %X", 10);
	write(1, "\n", 1);

	printf("Vrai printf : %x\n", 30);
	ft_print_hexa_min(30);
	write(1, "\n", 1);
	ft_printf("Mon printf : %x", 30);
	write(1, "\n", 1);
	printf("Vrai printf : %X\n", 30);
	ft_print_hexa_maj(30);
	write(1, "\n", 1);
	ft_printf("Mon printf : %X", 30);
	write(1, "\n", 1);

	printf("Vrai printf : %x\n", 100);
	ft_print_hexa_min(100);
	write(1, "\n", 1);
	ft_printf("Mon printf : %x", 100);
	write(1, "\n", 1);
	printf("Vrai printf : %X\n", 100);
	ft_print_hexa_maj(100);
	write(1, "\n", 1);
	ft_printf("Mon printf : %X", 100);
	write(1, "\n", 1);

	printf("Vrai printf : %x\n", 150);
	ft_print_hexa_min(150);
	write(1, "\n", 1);
	ft_printf("Mon printf : %x", 150);
	write(1, "\n", 1);
	printf("Vrai printf : %X\n", 150);
	ft_print_hexa_maj(150);
	write(1, "\n", 1);
	ft_printf("Mon printf : %X", 150);
	write(1, "\n", 1);

	printf("Vrai printf : %x\n", 300);
	ft_print_hexa_min(300);
	write(1, "\n", 1);
	ft_printf("Mon printf : %x", 300);
	write(1, "\n", 1);
	printf("Vrai printf : %X\n", 300);
	ft_print_hexa_maj(300);
	write(1, "\n", 1);
	ft_printf("Mon printf : %X", 300);
	write(1, "\n", 1);

	// TEST POURCENTAGE
	printf("TEST PRINT F %\n");
	printf("%%");
	ft_printf("%%");

	return (0);
	
	int main() {
	ft_printf("%x\n", LONG_MIN+1);
	printf("%x\n", LONG_MIN+1);
}

// MAIN 


// int main(void)
// {
// 	int i;
// 	int j;
// // TEST ADRESSE POINTEUR
// 	char *test = NULL;

// 	test = "abc";
// 	printf("%p\n", (void *)-1);
// 	ft_printf("%p\n", (void *)-1);
// 	//i = ft_printf("This %p is even stranger", (void *)-1);
// 	//j = printf("This %p is even stranger", (void *)-1);

// 	return (0);
// }


	
}

