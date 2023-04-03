/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:13:29 by lduheron          #+#    #+#             */
/*   Updated: 2023/03/27 13:37:23 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **stack)
{
	int	tmp;

	if (stack && (*stack)->next)
	{
		tmp = (*stack)->content;
		(*stack)->content = (*stack)->next->content;
		(*stack)->next->content = tmp;
	}
}

void	ft_sa(t_list **stack_a, t_data *data)
{
	ft_swap(stack_a);
	ft_putstr("sa\n");
	data->moves += 1;
}

void	ft_sb(t_list **stack_b, t_data *data)
{
	ft_swap(stack_b);
	ft_putstr("sb\n");
	data->moves += 1;
}

void	ft_ss(t_list **stack_a, t_list **stack_b, t_data *data)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	ft_putstr("ss\n");
	data->moves += 1;
}
