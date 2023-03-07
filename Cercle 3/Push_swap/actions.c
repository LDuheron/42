/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:28:42 by lduheron          #+#    #+#             */
/*   Updated: 2023/03/06 14:36:45 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_list *stack)
{
	t_list	tmp;

	if (!stack || !stack->next)
		return (0);
	tmp = *stack;
	stack = stack->next;
	*stack->next = tmp;
	// free (tmp);
	return (1);
}

void	ft_sa(t_list *stack)
{
	swap(stack);
	ft_putstr("sa\n");
}

void	ft_sb(t_list *stack)
{
	swap(stack);
	ft_putstr("sb\n");
}


void	ft_ss(t_list *stack_a, t_list *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putstr("ss\n");
}

/// push /// 

// void	ft_pa(char *stack_a, char *stack_b)
// {
// 	int	tmp;
// 	int	i;
// 	if (stack_a[0] && stack_b[0])
// 	{
// 		while (stack_a[i])
// 		{
// 			i++;
// 		}
// 		i++;
// 		while (i != 0)
// 		(
// 			stack_a[i] = stack_a[i - 1];
// 			i--;
// 		)
// 		stack_a[0] = stack_b[0]
// 		i = 0;
// 		while (stack_b[i])
// 		{
// 			stack[i] = stack[i+ 1];
// 			i++;
// 		}
// 		printf("sa\n");
// 	}
// }