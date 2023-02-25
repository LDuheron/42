/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:18:00 by lduheron          #+#    #+#             */
/*   Updated: 2023/02/25 17:41:13 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./utils/gnl/get_next_line.h"
#include "./utils/PrintF/ft_printf.h"
#include "./utils/minilibx-linux/mlx.h"

void	ft_map_destroyer_int(int **map, t_data *d)
{
	int	i;

	i = 0;
	while (i < d->nb_lin)
	{
		free (map[i]);
		i++;
	}
	free(map);
}

void	free_image(t_data *d)
{
	if (d->flr)
		mlx_destroy_image(d->ptr, d->flr);
	if (d->c)
		mlx_destroy_image(d->ptr, d->c);
	if (d->wa)
		mlx_destroy_image(d->ptr, d->wa);
	if (d->e_c)
		mlx_destroy_image(d->ptr, d->e_c);
	if (d->ex)
		mlx_destroy_image(d->ptr, d->ex);
	if (d->p == d->p_right)
		mlx_destroy_image(d->ptr, d->p_left);
	if (d->p == d->p_left)
		mlx_destroy_image(d->ptr, d->p_right);
	if (d->p)
		mlx_destroy_image(d->ptr, d->p);
}

void	free_map(t_data *d)
{
	int	j;

	j = 0;
	while (d->map_f[j])
	{
		free(d->map_f[j]);
		j++;
	}
	free(d->map_f);
}

void	map_error(int error, t_data *d)
{
	if (error == 0)
		game_end(d);
	else if (error == 1)
	{
		ft_putstr2("Error\nError occured during map's initialisation.\n");
		game_end_before_win(d);
	}
	else if (error == 2)
	{
		ft_putstr2("Error\nError occured during the backtracking.\n");
		game_end_full_erase(d);
	}
	else if (error == 3)
	{
		ft_putstr2("Error\nThe map is too big.\n");
		game_end_before_win(d);
	}
	ft_putstr2("Error\nThe map format is wrong.\n");
	if (error == 4)
	{
		free_image(d);
		game_end_after_win(d);
	}
	else if (error == 5)
		game_end_full_erase(d);
}
