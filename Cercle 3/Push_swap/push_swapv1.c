/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 13:52:16 by lduheron          #+#    #+#             */
/*   Updated: 2023/01/21 18:19:31 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


char *push_swap(char *a, char *b, char **argv)
{
	int tmp;

	i = 0;
	j = 0;
	tmp = stack[i];
	while (stack[i])
	{
		if (stack[j]) 
		{
			tmp = *a;
			*a = *b;
			*b = tmp;
			j++;
		}
		i++;
	}
	return (stack_cpy)
}

if (argv = "sa")
{
	tmp = a[0];
	a[0] = a[1];
	a[1] = tmp;
}
if (argv = "sb")
{
	tmp = b[0];
	b[0] = b[1];
	b[1] = tmp;
}
if (argv = "ra")
{
	i = 0;
	tmp = a[0];
	while (a[i + 1])
		a[i] = a[i + 1];
	a[i] = tmp;
}
if (argv = "rb")
{
	i = 0;
	tmp = b[0];
	while (b[i + 1])
		b[i] = b[i + 1];
	b[i] = tmp;
}

int	main(argc, argv)
{
	char *a;
	char *b;
	int	i;

	a = "";
	b = NULL;
	i = 2;
	if argc != 2
		return (NULL);
	while (argc[i] != NULL)
	{
		ft_push_swap(argv[i]);
		i++;
	}
	return (0);
}