/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:07:15 by lduheron          #+#    #+#             */
/*   Updated: 2023/03/06 14:35:45 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// int find_smallest()
// {
// 	int smallest;

// 	while (stack[a]!= smallest)
// 	{
// 		ra;
// 		i++;
// 	}
// 	rra autant que de ra;
// }
// while
// {
// 	rra ; 
// 	j++;
// }
// comparer i et j, voir ce qui est le plus petit ;
// if (i > j)
// return (1);
// return (0);

////////////////////////// UTILS C ////////////////////////////

/////////////////////// UTILS LISTE /////////////////////////////

int	ft_lstsize(t_list *lst)
{
	int	size;

	if (!(lst))
		return (0);
	i = 0;
	while (lst)
	{
		lst = lst-> next;
		size++;
	}
	return (size);
}

/////////////////////// ALLOWED ACTIONS /////////////////////////


//// rotate ////

// ft_lst add fromt -> ajoute lelelemnt new au debut de la liste

// lst add back -> ajoute lelement nez=w a la fin de la liste 
/////////////////////////////////////////////////



int	ft_trois(char *stack_a, char *stack_b)
{
	if (argv[2] > argv[1] > argv[3])
	{
		ft_sa;
	}
	else if (argv[1] > argv[3] > argv[2])
	{
		ft_sa; 
		argv[3] > argv[1] > argv[2];
		ft_ra;
	}
	else if (argv[3] > argv[2] > argv[1])
	{
		ft_sa;
		argv[2] > argv[3] > argv[1]
		ft_rra;
	}
	else if (argv[2] > argv[3] > argv[1])
	{
		ft_rra;
	}
	else if (argv[3] > argv[1] > argv[2])
	{
		ft_ra;
	}
	return (0);
}

//////////MAIN ///////////////////////

t_list	ft_fill_stack_a(int argc, char **argv)
{
	t_list	*stack;
	int	i;

	i = 1;
	
	stack = malloc (sizeof(t_list));
	// if (!stack)
	//	return (NULL);	
	while (i + 1 < argc)
	{
		stack->content = &argv[i];
		//printf("argv %i %i : %d\n", i, argv[i], stack);
		stack->next = NULL;	
		stack->content = stack->next;
		i++;
	}
	printf("SEARCH SEGFAULT\n");
	return (*stack);
}


int main(int argc, char **argv)
{
	t_list	*stack_a = NULL;
	t_list	*tmp = NULL;
	//t_list *stack_b;
	int	i;

	i = 1;
	if (argc == 1)
		return (0);
	else if (argc == 2)
	{
		printf("%s", argv[1]);
		return (0);
	}
	// *stack_a = ft_fill_stack_a(argc, argv);
	//*stack_b = NULL;

	stack_a = malloc (sizeof(t_list));
	// if (!stack)
	// 	return (NULL);	
	// while (i++ < argc - 1)
	while (argv[i])
	{
			stack_a->content = argv[i];
			stack_a->next = NULL;
			tmp = stack_a -> content;
			write(1, tmp, 1);
			// printf("argv %i %i : %d\n", i, argv[i], stack_a);
			stack_a = stack_a->next;
			i++;
	}
	return (1);
}