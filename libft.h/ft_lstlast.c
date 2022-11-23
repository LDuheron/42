/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:57:24 by lduheron          #+#    #+#             */
/*   Updated: 2022/11/23 17:29:08 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list *ft_lstlast(t_list *lst)
{
	t_list *tmp=NULL;

	if (!(lst))
		return (NULL);
	tmp=lst;
	while (tmp->next != NULL)
		tmp=tmp->next;
	return (tmp);
}

//tmp->content = lst;

/*


	if (!(lst))
		return (NULL);
	else
		while (lst->next != NULL)
			*lst=*lst->next;
		return (lst);
*/