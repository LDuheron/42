/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:53:57 by lduheron          #+#    #+#             */
/*   Updated: 2022/11/27 17:57:25 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*p;
	t_list	*tmp;
	void	*content;

	if (!f)
		return (NULL);
	p = NULL;
	while (lst)
	{
		content = f(lst->content);
		tmp = ft_lstnew(content);
		if (!tmp)
		{
			if (del)
				(*del)(content);
			ft_lstclear(&p, del);
			return (NULL);
		}
		ft_lstadd_back(&p, tmp);
		lst = lst->next;
	}
	return (p);
}

/*
	t_list	*copie=NULL;
	t_list	*new=NULL;

	if (!f || !lst)
		return (NULL);
	while (lst)
	{
		ft_lstadd_back(&copie, &new);
		new = f(lst->content);
		if (new == NULL)
		{	ft_lstclear(&new, del);
			return (NULL);
		}
		new = new->next;
	} 
	return (copie);
}

	if (del)
			(*del)(lst->content);
	while (lst) //lsiter
	{
			ft_lstclear(&copie, &lst);
			copie = f(lst->content);
			lst = lst->next;
	}
	free(lst);
	return (copie);

clude "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*p;
	t_list	*tmp;
	void	*content;

	if (!f)
		return (NULL);
	p = NULL;
	while (lst)
	{
		content = f(lst->content);
		tmp = ft_lstnew(content);
		if (!tmp)
		{
			if (del)
				(*del)(content);
			ft_lstclear(&p, del);
			return (NULL);
		}
		ft_lstadd_back(&p, tmp);
		lst = lst->next;
	}
	return (p);

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *copie=NULL;

	while (lst)
	{
		ft_lstadd_back(&copie, (copie -> next = f(lst->content));
		copie = f(lst->content);
		if (copie == NULL)
			ft_lstclear(&lst, del);
		lst = lst->next;
	}
	return(copie);
}

{
	t_list *copie;

	copie = malloc(sizeof(lst));
	if (!lst || !del)
		return (NULL);
	while (lst)
	{
			ft_lstclear(&copie, del);
			copie = f(lst->content);
			lst = lst->next;
	}
	return (copie);
}


void ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *tmp;

	while (*lst && lst)
	{
		tmp=(*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
}



t_list *new_list;
	t_list	*tmp;
	t_list	*content;
	
	if (!tmp)
	{
		if (del)
			(*del)(content);
		while (lst)
			ft_lstclear(&new_list, tmp);
			lst = lst->next;
	}
	return (new_list);
	
	
	
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *copie=NULL;

	copie = malloc(sizeof(lst));
	if (!lst || !del)
		return (NULL);
	if (del)
			(*del)(lst->content);
	while (lst) //lsiter
	{
			ft_lstclear(&copie, &lst);
			copie = f(lst->content);
			lst = lst->next;
	}
	free(lst);
	return (copie);
	
	
	
	
void ft_lstiter(t_list *lst, void (*f)(void *))
{
		while (lst)
		{
			f(lst->content);
			lst = lst->next;
		}
}
	
	
	
	*/

