/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:50:23 by lduheron          #+#    #+#             */
/*   Updated: 2023/04/03 16:31:11 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// rank moyen = ((max - (float)min) / (((float)max - (float)min) + 1)) / 2;
//rank du nb = (("content" - (float)min) / (((float)max - (float)min) + 1));
// proteger dans inert sort && tmp->content && tmp->next->content

void	ft_insert_sort2(t_list **stack_a, t_list **stack_b, t_data *data)
{
	t_list	*tmp;
	float	rank_nb;
	float	rank_next;
	int	i;
	// int j;

	rank_nb = 0;
	rank_next = 0;
	ft_pa(stack_a, stack_b, data);
	tmp = *stack_a;
	if (tmp->content > data->lowest)
	{
		if (tmp->content > ft_lstlast(*stack_a)->content)
			ft_ra(stack_a, data);
		rank_nb = ft_find_rank_nb(data, tmp->content);
		rank_next = ft_find_rank_nb(data, tmp->next->content);
		printf("RANK DANS SORT FIVE : %f\n", rank_nb);
		i = 0;
		if (rank_nb >= data->rank_m)
		{
			while (rank_nb > rank_next)
			{
				ft_rra(stack_a, data);
				tmp = *stack_a;
				// ft_sa(stack_a, data);
				i++;
			}
			while (i > 0)
			{
				ft_ra(stack_a, data);
				tmp = *stack_a;
				i--;
			}
		}
		else if (rank_nb < data->rank_m)
		{
			ft_sa(stack_a, data);
			while (tmp->content > tmp->next->content)
			{
				ft_ra(stack_a, data);
				tmp = *stack_a;
				ft_sa(stack_a, data);
				tmp = *stack_a;
				i++;
			}
			while (i > 0)
			{
				ft_rra(stack_a, data);
				tmp = *stack_a;
				i--;
			}
		}
		// j = i;
		// while (j > 0)
		// {
		// 	if (i > ft_lstsize(*stack_a))
		// 		ft_rra(stack_a, data);
		// 	ft_ra(stack_a, data);
		// 	tmp = *stack_a;
		// 	j--;
		// }
	}
}

/////////////////////////////////////////////////////////////////////////
// abandonner les rank pour la mediane ?

// void	insert_sort_five_v2(t_list **stack_a, t_list **stack_b, t_data *data)
// {
// 	int		i;
// 	t_list	*tmp;

// 	i = 0;
// 	tmp = *stack_a;
// 	ft_pa(stack_a, stack_b, data);
// 	if (ft_is_sorted(stack_a, data) == 0)
// 	{
// 		if (tmp->content > ft_lstlast(stack_a)->content)
// 			ft_ra(stack_a, data);
// 		if (ft_find_rank_nb(data, tmp->content) < data->rank_m)
// 			ft_sa(stack_a, data);
// 	}
// }

/////////////////////////////////////////////////////////////////////////


void	ft_sort_inf(t_list **stack_a, t_data *data)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *stack_a;
	while (tmp->content && tmp->content > tmp->next->content)
	{
		ft_ra(stack_a, data);
		tmp = *stack_a;
		ft_sa(stack_a, data);
		tmp = *stack_a;
		i++;
	}
	i++;
	while (i > 0)
	{
		ft_rra(stack_a, data);
		tmp = *stack_a;
		i--;
	}
}

void	ft_sort_sup(t_list **stack_a, t_data *data)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *stack_a;
	while (tmp->content && tmp->content > tmp->next->content)
	{
		ft_rra(stack_a, data);
		tmp = *stack_a;
		ft_sa(stack_a, data);
		tmp = *stack_a;
		i++;
	}
	ft_sa(stack_a, data);
	i++;
	while (i > 0)
	{
		ft_ra(stack_a, data);
		tmp = *stack_a;
		i--;
	}
}


void	insert_sort_five(t_list **stack_a, t_list **stack_b, t_data *data)
{
	t_list	*tmp;
	int		i;

	i = 0;
	ft_pa(stack_a, stack_b, data);
	tmp = *stack_a;
	if (ft_is_sorted(stack_a, data) == 0)
	{
		if (tmp->content == data->highest)
			ft_ra(stack_a, data);
		if (tmp->content > tmp->next->content && tmp->content < tmp->next->next->content)
			ft_sa(stack_a, data);
		else if (ft_find_rank_nb(data, tmp->content) < data->rank_m)
		{
			ft_sa(stack_a, data);
			if (ft_is_sorted(stack_a, data) == 0)
				ft_sort_inf(stack_a, data);
		}
		else
		{
			if (ft_is_sorted(stack_a, data) == 0)
				ft_sort_sup(stack_a, data);
		}
	}
}

/////////////////////////////////////////////////////////////////////////

void	sort_five(t_list **stack_a, t_list **stack_b, t_data *data)
{
	ft_sort_before_push(stack_a, stack_b, data);
	ft_print_both_list(stack_a, stack_b);
	sort_three(stack_a, data);
	ft_print_both_list(stack_a, stack_b);
	while (ft_lstsize(*stack_b) != 0)
	{
		// ft_insert_sort2(stack_a, stack_b, data);
		insert_sort_five(stack_a, stack_b, data);
		ft_print_both_list(stack_a, stack_b);
	}
	// if (ft_is_sorted(stack_a, data) != 1)
	// 	ft_insert_sort2(stack_a, stack_b, data);
}
