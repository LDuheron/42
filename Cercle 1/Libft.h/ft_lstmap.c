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

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*copy;
	t_list	*tmp;
	void	*content;

	if (!f)
		return (NULL);
	copy = NULL;
	while (lst)
	{
		content = f(lst->content);
		tmp = ft_lstnew(content);
		if (!tmp)
		{
			if (del)
				(*del)(content);
			ft_lstclear(&copy, del);
			return (NULL);
		}
		ft_lstadd_back(&copy, tmp);
		lst = lst->next;
	}
	return (copy);
}
