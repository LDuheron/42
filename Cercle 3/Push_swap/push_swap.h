/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 13:51:26 by lduheron          #+#    #+#             */
/*   Updated: 2023/03/06 14:44:44 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

// ACTIONS //

int		swap(t_list *stack);
void	ft_sa(t_list *stack);
void	ft_sb(t_list *stack);
void	ft_ss(t_list *stack_a, t_list *stack_b);

// List utils //

int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstnew(char *content);

// swap.c ///

void	ft_putstr(char *str);
t_list	*ft_lstprint(t_list *stack_a);
t_list	ft_fill_stack_a(int argc, char **argv);

#endif