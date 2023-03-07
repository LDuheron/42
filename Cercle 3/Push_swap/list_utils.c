/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:30:00 by lduheron          #+#    #+#             */
/*   Updated: 2023/03/06 19:11:55 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	if (!(lst))
		return (0);
	i = 0;
	while (lst)
	{
		lst = lst-> next;
		i++;
	}
	return (i);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;

	tmp = NULL;
	if (!(lst))
		return (NULL);
	tmp = lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}


void	ft_lstadd_back_libft(t_list **lst, t_list *new)
{
	t_list	*tmp;

	tmp = *lst;
	if (!*lst)
		*lst = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	tmp = *lst;
	if (!*lst)
		*lst = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL)
		*lst = new;
	new->next = *lst;
	*lst = new;
}

t_list	*ft_lstnew(char *content)
{
	t_list	*new_elem;

	new_elem = malloc (sizeof(t_list));
	if (!new_elem)
		return (NULL);
	new_elem->content = content;
	new_elem->next = NULL;
	return (new_elem);
}

// Alloue (avec malloc(3)) et renvoie un nouvel
// élément. La variable membre ’content’ est
// initialisée à l’aide de la valeur du paramètre
// ’content’. La variable ’next’ est initialisée à
// NULL
