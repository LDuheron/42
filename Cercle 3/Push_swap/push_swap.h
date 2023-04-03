/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 13:51:26 by lduheron          #+#    #+#             */
/*   Updated: 2023/04/01 20:33:40 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}				t_list;

typedef struct s_data
{
	int	size;
	int	highest;// highest content ever
	int	lowest;
	int	moves;
	float	rank_m;
}				t_data;

/// ACTIONS ///

void	ft_swap(t_list **stack_a);
void	ft_sa(t_list **stack_a, t_data *data);
void	ft_sb(t_list **stack_b, t_data *data);
void	ft_ss(t_list **stack_a, t_list **stack_b, t_data *data);

void	ft_pa(t_list **stack_a, t_list **stack_b, t_data *data);
void	ft_pb(t_list **stack_a, t_list **stack_b, t_data *data);

void	ft_ra(t_list **stack_a, t_data *data);
void	ft_rb(t_list **stack_b, t_data *data);
void	ft_rr(t_list **stack_a, t_list **stack_b, t_data *data);

void	ft_rra(t_list **stack_a, t_data *data);
void	ft_rrb(t_list **stack_b, t_data *data);
void	ft_rrr(t_list **stack_a, t_list **stack_b, t_data *data);

/// ACTIONS UTILS ///
void	ft_remove_first_node(t_list **stack);
void	ft_last_to_first(t_list **stack);
void	ft_remove_last_node(t_list **stack);

/// LIST UTILS ///

void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int content);

/// MAIN ///

int		sort_three(t_list **stack, t_data *data);

///  ERROR MANAGEMENT ///

void	error(t_list **stack);
void	ft_lstclear(t_list **lst);
void	ft_putstr2(char *s);

/// PUSH SWAP UTILS ///

void	ft_putstr(char *str);
void	ft_fill_stack(t_list **stack, char **argv, int argc);
void	print_list(t_list *tmp);
void	ft_print_both_list(t_list **stack_a, t_list **stack_b);
int		ft_is_sorted(t_list **stack_a, t_data *data);

/// ATOI ///

int		ft_atoi(const char *str);

/// SORT FIVE ///

void	ft_sort_before_push(t_list **stack_a, t_list **stack_b, t_data *data);
void	ft_insert_sort(t_list **stack_a, t_list **stack_b, t_data *data);
void	sort_five(t_list **stack_a, t_list **stack_b, t_data *data);

/// RANK ///

float	ft_find_rank_nb(t_data *data, int nb);
// float	ft_find_rank_last(t_list **stack);

/// POSITION ///

// void	find_top(t_list **stack, t_data *data);
// void	find_low(t_list **stack, t_data *data);
// void	find_low_pos(t_list **stack, t_data *data);
// void	find_top_pos(t_list **stack, t_data *data);
int		return_max(t_list **stack);
int		return_min(t_list **stack);

#endif
