/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:28:42 by lduheron          #+#    #+#             */
/*   Updated: 2023/03/27 13:36:32 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_list **stack_a, t_data *data)
{
	if ((*stack_a) && (*stack_a)->next)
	{
		ft_last_to_first(stack_a);
		ft_remove_last_node(stack_a);
		ft_putstr("rra\n");
		data->moves += 1;
	}
}

void	ft_rrb(t_list **stack_b, t_data *data)
{
	if ((*stack_b) && (*stack_b)->next)
	{
		ft_last_to_first(stack_b);
		ft_remove_last_node(stack_b);
		ft_putstr("rrb\n");
		data->moves += 1;
	}
}

void	ft_rrr(t_list **stack_a, t_list **stack_b, t_data *data)
{
	ft_last_to_first(stack_a);
	ft_remove_last_node(stack_a);
	ft_last_to_first(stack_b);
	ft_remove_last_node(stack_b);
	ft_putstr("rrr\n");
	data->moves += 1;
}
