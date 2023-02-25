/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 20:59:24 by lduheron          #+#    #+#             */
/*   Updated: 2023/02/25 17:40:03 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./utils/gnl/get_next_line.h"
#include "./utils/PrintF/ft_printf.h"
#include "./utils/minilibx-linux/mlx.h"

int	**reachable_init(t_data *d)
{
	int	x;
	int	y;

	y = 0;
	d->reachable = malloc(sizeof(int *) * (d->nb_lin) + 1);
	if (!d->reachable)
		map_error(2, d);
	while (y < d->nb_lin)
	{
		d->reachable[y] = malloc(sizeof(int *) * d->nb_col + 2);
		x = 0;
		while (x < d->nb_col + 1)
		{
			d->reachable[y][x] = 0;
			x++;
		}
		y++;
	}
	return (d->reachable);
}

int	backtracking(t_data *d, int x, int y)
{
	if (!(y > 0 && y < d->nb_lin - 1 && x > 0 && x < d->nb_col))
		return (0);
	if (d->map_f[y][x] == 'E' )
	{
		d->r_exit = 1;
		d->ex_x = x;
		d->ex_y = y;
		d->reachable[y][x] = 2;
	}	
	if (d->map_f[y][x] == 'C' && d->reachable[y][x] != 1 \
			&& d->collected != d->cpt_c)
		d->collected += 1;
	if (!(d->map_f[y][x] != '1' && d->map_f[y][x] != 'E'))
		return (0);
	if (d->collected == d->cpt_c && d->r_exit == 1)
		return (0);
	if (d->reachable[y][x] == 1)
		return (0);
	d->reachable[y][x] = 1;
	backtracking(d, x, y + 1);
	backtracking(d, x + 1, y);
	backtracking(d, x, y - 1);
	backtracking(d, x - 1, y);
	return (0);
}

int	format(t_data *d)
{
	if (check_c_and_len(d) == 1)
	{
		if (check_rectangle(d) == 1)
		{
			if (check_frame(d) == 1)
			{
				reachable_init(d);
				backtracking(d, d->p_x, d->p_y);
				if (d->r_exit == 1)
				{
					if (d->collected == d->cpt_c)
					{
						d->collected = 0;
						d->n_px = d->p_x;
						d->n_py = d->p_y;
						return (1);
					}
				}
				map_error(5, d);
			}
		}
	}
	map_error(4, d);
	return (0);
}
