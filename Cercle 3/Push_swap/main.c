/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:32:10 by lduheron          #+#    #+#             */
/*   Updated: 2023/04/02 19:06:22 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//// list ** modifie la liste
// list * ne modifie pas la liste, itere sur une copie
/// interdiction aux doublons

void	ft_sort_before_push(t_list **stack_a, t_list **stack_b, t_data *data)
{
	t_list	*tmp;
	float	rank_nb;

	rank_nb = 0;
	tmp = *stack_a;
	while (ft_lstsize(*stack_a) != 3)
	{
		rank_nb = ft_find_rank_nb(data, tmp->content);
		printf("float : %f", rank_nb);
		if (rank_nb < data->rank_m)
		{
			if (tmp->content > tmp->next->content)
				ft_sa(stack_a, data);
			tmp = *stack_a;
			ft_pb(stack_a, stack_b, data);
		}
		else
		{
			if (tmp->content > tmp->next->content)
				ft_ra(stack_a, data);
			ft_pb(stack_a, stack_b, data);
		}
		tmp = *stack_a;
	}
}

int	sort_three(t_list **stack, t_data *data)
{
	t_list	*tmp;
	int		min;
	int		max;

	tmp = *stack;
	min = return_min(stack);
	max = return_max(stack);
	if (ft_is_sorted(stack, data) == 0)
	{
		tmp = *stack;
		if (tmp->content == max)
			ft_ra(stack, data);
		else if (tmp->next->content == max)
			ft_rra(stack, data);
		tmp = *stack;
		if (tmp->content > tmp->next->content)
			ft_sa(stack, data);
	}
	return (1);
}

void	push_swap(t_list **stack_a, t_list **stack_b, t_data *data)
{
	if (data->size <= 2 && ft_is_sorted(stack_a, data) == 0)
		ft_sa(stack_a, data);
	else if (data->size == 3)
		sort_three(stack_a, data);
	else
		sort_five(stack_a, stack_b, data);
}

void	ft_init_structure_data(t_data *data, t_list **stack_a, int argc)
{
	data->highest = return_max(stack_a);
	data->lowest = return_min(stack_a);
	data->moves = 0;
	data->size = argc - 1;
	data->rank_m = (data->highest - (float)data->lowest) / ((float)data->highest - (float)data->lowest + 1) / 2;
	printf("data rank m in init %f\n", data->rank_m);
}

int	main(int argc, char **argv)
{
	int			i;
	t_list		*stack_a;
	t_list		*stack_b;
	t_data		data;

	i = 1;
	if (argc >= 1)
	{
		stack_a = NULL;
		stack_b = NULL;
		ft_fill_stack(&stack_a, argv, argc);
		ft_init_structure_data(&data, &stack_a, argc);
		if (ft_is_sorted(&stack_a, &data) == 0)
			push_swap(&stack_a, &stack_b, &data);
		ft_print_both_list(&stack_a, &stack_b);
		ft_lstclear(&stack_a);
		ft_lstclear(&stack_b);
		printf("Moves : %d", data.moves);
	}
	return (0);
}
