/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:40:45 by lduheron          #+#    #+#             */
/*   Updated: 2022/11/22 19:01:20 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL)
		*lst=new;
	new->next = *lst;
	*lst=new;
}
