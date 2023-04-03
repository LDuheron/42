/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 19:07:43 by lduheron          #+#    #+#             */
/*   Updated: 2023/03/10 19:16:29 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_remove_first_node(t_list **stack)
{
	t_list	*head;

	head = NULL;
	head = *stack;
	if (stack)
		*stack = (*stack)->next;
	free(head);
}

void	ft_last_to_first(t_list **stack)
{
	t_list	*tmp;

	tmp = NULL;
	if ((*stack) && (*stack)->next)
	{
		tmp = *stack;
		while (tmp->next != NULL)
			tmp = tmp->next;
		ft_lstadd_front(stack, ft_lstnew(tmp->content));
	}
}

void	ft_remove_last_node(t_list **stack)
{
	t_list	*tmp;		

	tmp = NULL;
	tmp = *stack;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	free(tmp->next);
	tmp->next = NULL;
}
