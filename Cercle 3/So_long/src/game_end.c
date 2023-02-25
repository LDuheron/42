/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:57:19 by lduheron          #+#    #+#             */
/*   Updated: 2023/02/25 17:30:57 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./utils/gnl/get_next_line.h"
#include "./utils/PrintF/ft_printf.h"
#include "./utils/minilibx-linux/mlx.h"

void	game_end(t_data *d)
{
	ft_putstr2("Error\nPlease compile with a single arg in .ber format.\n");
	ft_game_invalid(d);
	mlx_destroy_display(d->ptr);
	free(d->ptr);
	d->ptr = NULL;
	(void) d;
	exit(0);
}

void	game_end_before_win(t_data *d)
{
	ft_game_invalid(d);
	free_image(d);
	if (d->map_f != NULL)
		free_map(d);
	mlx_destroy_display(d->ptr);
	free(d->ptr);
	d->ptr = NULL;
	(void) d;
	exit(0);
}

void	game_end_after_win(t_data *d)
{
	ft_game_invalid(d);
	if (d->map_f != NULL)
		free_map(d);
	if (d->win != NULL)
		mlx_destroy_window(d->ptr, d->win);
	mlx_destroy_display(d->ptr);
	free(d->ptr);
	d->win = NULL;
	d->ptr = NULL;
	(void) d;
	exit(0);
}

void	game_end_full_erase(t_data *d)
{
	ft_game_invalid(d);
	free_image(d);
	if (d->map_f != NULL)
		free_map(d);
	if (d->reachable != NULL)
		ft_map_destroyer_int(d->reachable, d);
	if (d->win != NULL)
		mlx_destroy_window(d->ptr, d->win);
	mlx_destroy_display(d->ptr);
	free(d->ptr);
	d->win = NULL;
	d->ptr = NULL;
	(void) d;
	exit(0);
}

void	game_end_win(t_data *d)
{
	ft_game_win(d);
	free_image(d);
	free_map(d);
	ft_map_destroyer_int(d->reachable, d);
	mlx_destroy_window(d->ptr, d->win);
	mlx_destroy_display(d->ptr);
	free(d->ptr);
	d->win = NULL;
	d->ptr = NULL;
	(void) d;
	exit(0);
}
