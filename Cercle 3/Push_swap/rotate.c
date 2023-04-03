/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 19:10:15 by lduheron          #+#    #+#             */
/*   Updated: 2023/03/27 13:36:34 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_list **stack_a, t_data *data)
{
	t_list	*tmp;

	tmp = NULL;
	if ((*stack_a) && (*stack_a)->next)
	{
		tmp = malloc(sizeof(t_list));
		tmp->content = (*stack_a)->content;
		tmp->next = NULL;
		ft_lstadd_back(stack_a, tmp);
		ft_remove_first_node(stack_a);
		ft_putstr("ra\n");
		data->moves += 1;
	}
}

void	ft_rb(t_list **stack_b, t_data *data)
{
	t_list	*tmp;

	tmp = NULL;
	if ((*stack_b) && (*stack_b)->next)
	{
		tmp = malloc(sizeof(t_list));
		tmp->content = (*stack_b)->content;
		tmp->next = NULL;
		ft_lstadd_back(stack_b, tmp);
		ft_remove_first_node(stack_b);
		ft_putstr("rb\n");
		data->moves += 1;
	}
}

void	ft_rr(t_list **stack_a, t_list **stack_b, t_data *data)
{
	t_list	*tmp;

	tmp = NULL;
	if ((*stack_a) && (*stack_a)->next)
	{
		tmp = malloc(sizeof(t_list));
		tmp->content = (*stack_a)->content;
		tmp->next = NULL;
		ft_lstadd_back(stack_a, tmp);
		ft_remove_first_node(stack_a);
	}
	tmp = NULL;
	if ((*stack_b) && (*stack_b)->next)
	{
		tmp = malloc(sizeof(t_list));
		tmp->content = (*stack_b)->content;
		tmp->next = NULL;
		ft_lstadd_back(stack_b, tmp);
		ft_remove_first_node(stack_b);
	}
	ft_putstr("rr\n");
	data->moves += 1;
}
