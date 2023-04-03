/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:54:51 by lduheron          #+#    #+#             */
/*   Updated: 2023/04/01 13:20:33 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// return 

int	return_max(t_list **stack)
{
	t_list	*tmp;
	int		top;

	tmp = *stack;
	top = tmp->content;
	while (tmp->next)
	{
		if (tmp->next->content > top)
			top = tmp->next->content;
		tmp = tmp->next;
	}
	return (top);
}

int	return_min(t_list **stack)
{
	t_list	*tmp;
	int		low;

	tmp = *stack;
	low = tmp->content;
	while (tmp->next)
	{
		if (tmp->next->content < low)
			low = tmp->next->content;
		tmp = tmp->next;
	}
	return (low);
}

// // find pos

// void	find_low_pos(t_list **stack, t_data *data)
// {
// 	t_list	*tmp;

// 	tmp = *stack;
// 	data->lowest_pos = tmp->content;
// 	while (tmp->next)
// 	{
// 		if (tmp->next->content < data->lowest_pos)
// 			data->lowestest_pos = tmp->next->content;
// 		tmp = tmp->next;
// 	}
// 	// printf("Low pos = %i\n", data->lowest_pos);
// }

// void	find_top_pos(t_list **stack, t_data *data)
// {
// 	t_list	*tmp;

// 	tmp = *stack;
// 	data->top_pos = tmp->content;
// 	while (tmp->next)
// 	{
// 		if (tmp->next->content > data->top_pos)
// 			data->top_pos = tmp->next->content;
// 		tmp = tmp->next;
// 	}
// 	// printf("Top pos = %i\n", data->top_pos);
// }

// // classic find

// void	find_top(t_list **stack, t_data *data)
// {
// 	t_list	*tmp;

// 	tmp = *stack;
// 	data->highest = tmp->content;
// 	while (tmp->next)
// 	{
// 		if (tmp->next->content > data->highest)
// 			data->highest = tmp->next->content;
// 		tmp = tmp->next;
// 	}
// 	// printf("Top = %i\n", data->highest);
// }

// void	find_low(t_list **stack, t_data *data)
// {
// 	t_list	*tmp;

// 	tmp = *stack;
// 	data->lowest = tmp->content;
// 	while (tmp->next)
// 	{
// 		if (tmp->next->content < data->lowestest)
// 			data->lowestest = tmp->next->content;
// 		tmp = tmp->next;
// 	}
// 	// printf("Low = %i\n", data->lowest);
// }
