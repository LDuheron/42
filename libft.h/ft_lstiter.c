/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:25:08 by lduheron          #+#    #+#             */
/*   Updated: 2022/11/23 18:52:04 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void ft_lstiter(t_list *lst, void (*f)(void *))
{
		while (lst)
		{
			f(lst->content);
			lst = lst->next;
		}
}
