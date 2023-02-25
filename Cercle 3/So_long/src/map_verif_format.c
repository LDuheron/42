/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verif_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 19:54:58 by lduheron          #+#    #+#             */
/*   Updated: 2023/02/25 17:31:19 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./utils/gnl/get_next_line.h"
#include "./utils/PrintF/ft_printf.h"
#include "./utils/minilibx-linux/mlx.h"

int	check_ber(char *file)
{
	int	len;

	len = ft_strlen(file) - 1;
	if (file[len - 3] == '.')
	{
		if (file[len - 2] == 'b')
		{
			if (file[len - 1] == 'e')
			{
				if (file[len] == 'r')
					return (1);
			}
		}
	}
	return (0);
}

void	count_c(t_data *d, char c, int y, int x)
{
	if (c == 'P')
	{
		d->cpt_p += 1;
		d->p_x = x;
		d->p_y = y;
	}
	else if (c == 'E')
		d->cpt_e += 1;
	else if (c == 'C')
		d->cpt_c += 1;
}

int	check_c_and_len(t_data *d)
{
	int	i;
	int	j;

	i = 0;
	while (i < d->nb_lin - 1)
	{
		j = 0;
		while (d->map_f[i][j])
		{
			count_c(d, d->map_f[i][j], i, j);
			j++;
		}
		i++;
	}
	if (d->cpt_p == 1 && d->cpt_e == 1 && d->cpt_c >= 1)
	{
		return (1);
	}
	map_error(4, d);
	return (0);
}

int	check_frame(t_data *d)
{
	int	i;

	i = 0;
	while (i < (d->nb_col))
	{
		if (d->map_f[0][i] != '1' || d->map_f[d->nb_lin - 1][i] != '1')
			map_error(4, d);
		i++;
	}
	i = 0;
	while (i < d->nb_lin - 1)
	{
		if (d->map_f[i][0] != '1' || d->map_f[i][d->nb_col] != '1')
			map_error(4, d);
		i++;
	}
	return (1);
}

int	check_rectangle(t_data *d)
{
	if (d->nb_col <= 2 || d->nb_lin <= 2 \
		|| d->nb_lin > d->nb_col - 1)
		map_error(4, d);
	return (1);
}
