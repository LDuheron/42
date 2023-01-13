/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainPrintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 07:50:08 by lduheron          #+#    #+#             */
/*   Updated: 2023/01/13 07:50:10 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

cc Main_printf.c.c -L. -lftprintf

#include "ft_printf.h"

int main()
{
	int i = printf("  %p %p %u %s aaaa %u %% \n", NULL, (void*)256, -1, "Lol", -2147483648);
	int j = ft_printf("  %p %p %u %s aaaa %u %% \n", NULL, (void*)256, -1, "Lol", -2147483648);

	printf("ret: %d %d\n", i, j);
}
