/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:32:41 by lduheron          #+#    #+#             */
/*   Updated: 2023/01/12 13:51:48 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

int		max_nb(int nb);
int		nb_len(int nb);
int		ft_nbr(int nb);
int		ft_print_c(char c);
int		ft_printf(const char *v0, ...);
int		ft_print_hexabase(char type, unsigned int nb);
int		ft_hexa_p(char type, size_t nb);
void	ft_print_nbr(int nb);
int		ft_print_p(size_t p);
int		ft_print_s(char *str);
int		ft_type(va_list params, char type);
int		nb_u_len(unsigned int nb);
void	ft_print_unsigned_nbr(unsigned int nb);
int		ft_u_nbr(unsigned int nb);

#endif
