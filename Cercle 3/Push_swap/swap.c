/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:32:10 by lduheron          #+#    #+#             */
/*   Updated: 2023/03/06 19:29:33 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

t_list	*ft_lstprint(t_list *stack_a)
{
	t_list	*tmp;

	tmp = NULL;
	if (!(stack_a))
		return (NULL);
	tmp = stack_a;
	printf("entree ft lst print\n");
	while (tmp->next != NULL)
	{
		write(1, &tmp, 1);
		printf("Entree boucle while\n");
		tmp = tmp->next;
	}
	return (tmp);
}

t_list	ft_fill_stack_a(int argc, char **argv)
{
	t_list	*stack;
	int		i;

	i = 1;
	printf("search segfault");
	stack = malloc (sizeof(t_list));
	// if (!stack)
	// 	return (NULL);
	while (i + 1 < argc)
	{
		stack->content = &argv[i];
		//printf("argv %i %i : %d\n", i, argv[i], stack);
		stack->next = NULL;
	//	stack = stack->next;
		i++;
	}
	printf("ENTREE FT_FIlL STACK A\n");
	//ft_lstprint(stack);
	//printf("SEARCH SEGFAULT\n");
	return (*stack);
}

		// stack_a->content = argv[i];
		// stack_a->next = NULL;
		// tmp = stack_a -> content;
		// write(1, tmp, 1);
		// // printf("argv %i %i : %d\n", i, argv[i], stack_a);
		// // stack_a = stack_a->next;


//creer une variable ou ranger la head de ma liste chainee pour ne pas la perdre 
int	main(int argc, char **argv)
{
	t_list	**stack_a = NULL;
	// t_list	*tmp = NULL;
	int	i;
	// t_list	*stack_b = NULL;

	i = 2;
	if (argc == 1)
		return (0);
	else if (argc == 2)
	{
		printf("%s", argv[1]);
		return (0);
	}
	stack_a = malloc(sizeof(t_list));
	if (!stack_a)
		return (0);
	*stack_a->content = ft_lstnew(argv[1]);
	while (argv[i])
	{
		*stack_a->content = ft_lstnew(argv[i]);
		*stack_a->next = NULL;
		*stack_a = stack_a->next;
		i++;
	}
	// while (argv[i])
	// stack_a->content = argv[1];
	// stack_a->next = NULL;
	// stack_a = stack_a->next;
	// stack_a->content = argv[2];
	// stack_a->next = NULL;
	// while (argv[i])
	// {
	// 	stack_a->content = argv[i];
	// 	stack_a->next = NULL;
	// 	stack_a = stack_a->next;
	// 	i++;
	// }
	// while (stack_a)
	// {
	// 	printf("%s", (char *) stack_a->content);
	// 	stack_a = stack_a->next;
	// }
	// while (argv[i])
	// {
	// 	tmp = ft_lstnew(argv[i]);
	// 	ft_lstadd_back(stack_a, tmp);
	// 	free(tmp);
	// 	printf("argv %i %i : %d\n", i, argv[i], stack_a);
	// 	i++;
	// }
	// *tmp = *stack_a;
	// while (tmp != NULL)
	// {
	// 	// write(1, tmp->content, 1);
	// 	// printf("%s", (char *)tmp->content);
	// 	tmp = tmp->next;
	// 	printf("%d", tmp->content);
	// 	// (*tmp) = (*tmp)->next;
	// }
	return (1);
}

	// write(1, tmp->content, 1);
	// 	// printf("%d", tmp->content);
	// 	(*tmp) = (*tmp)->next;
