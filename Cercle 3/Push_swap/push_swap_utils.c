/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:40:06 by lduheron          #+#    #+#             */
/*   Updated: 2023/03/28 18:06:36 by lduheron         ###   ########.fr       */
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

void	ft_fill_stack(t_list **stack, char **argv, int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		ft_lstadd_back(stack, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
}

void	print_list(t_list *tmp)
{
	while (tmp != NULL)
	{
		printf("%d ", tmp->content);
		tmp = tmp->next;
	}
}

void	ft_print_both_list(t_list **stack_a, t_list **stack_b)
{
	t_list		*tmp;

	tmp = *stack_a;
	printf("PRINT STACK A : \n");
	print_list(tmp);
	tmp = *stack_b;
	printf("\nPRINT STACK B : \n");
	print_list(tmp);
}

int	ft_is_sorted(t_list **stack_a, t_data *data)
{
	t_list	*tmp;

	if (data->size < 1)
		return (0);
	tmp = *stack_a;
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
		{
			// printf("tmp->content : %d\n", tmp->content);
			// printf("tmp->next->content : %d\n", tmp->next->content);
			printf("The list is not sorted.\n");
			return (0);
		}
		tmp = tmp->next;
	}
	printf("The list is sorted.\n");
	return (1);
}
