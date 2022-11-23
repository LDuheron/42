/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:42:54 by lduheron          #+#    #+#             */
/*   Updated: 2022/11/23 17:48:23 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"
#include <stdlib.h>

void ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst)
	{
		*lst->content=del(lst);
		free(lst);
	}
}

//	del(lst)->content;