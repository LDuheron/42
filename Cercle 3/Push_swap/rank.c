/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:05:27 by lduheron          #+#    #+#             */
/*   Updated: 2023/04/01 15:51:07 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	ft_find_rank_nb(t_data *data, int nb)
{
	float	rank_nb;

	rank_nb = ((float)nb - (float)data->lowest) / ((float)data->highest - (float)data->lowest + 1);
	return (rank_nb);
}

// float	ft_find_rank_last(t_list **stack)
// {
// 	t_list	*tmp;
// 	int		min;
// 	int		max;
// 	float	rank;

// 	min = return_min(stack);
// 	max = return_max(stack);
// 	tmp = *stack;
// 	while (tmp->next)
// 		tmp = tmp->next;
// 	rank = (tmp->content - min) / (max - min + 1);
// 	return (rank);

// }
