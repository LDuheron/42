/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 19:08:47 by lduheron          #+#    #+#             */
/*   Updated: 2023/04/01 13:43:00 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	push(t_list **stack_a, t_list **stack_b)
// {
// 	t_list	*tmp;

// 	tmp = *stack_a;
// 	*stack_a = (*stack_a)->next;
// 	tmp->next = *stack_b;
// 	*stack_b = tmp;
// 	return ;
// }

void	ft_pa(t_list **stack_a, t_list **stack_b, t_data *data)
{
	t_list	*tmp;

	tmp = NULL;
	tmp = malloc(sizeof(t_list));
	tmp->content = (*stack_b)->content;
	tmp->next = NULL;
	ft_lstadd_front(stack_a, tmp);
	ft_remove_first_node(stack_b);
	ft_putstr("pa\n");
	data->moves += 1;
}

void	ft_pb(t_list **stack_a, t_list **stack_b, t_data *data)
{
	t_list	*tmp;

	tmp = NULL;
	tmp = malloc(sizeof(t_list));
	tmp->content = (*stack_a)->content;
	tmp->next = NULL;
	ft_lstadd_front(stack_b, tmp);
	ft_remove_first_node(stack_a);
	ft_putstr("pb\n");
	data->moves += 1;
}
