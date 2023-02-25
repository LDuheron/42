/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 20:26:41 by lduheron          #+#    #+#             */
/*   Updated: 2023/02/25 18:51:42 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./utils/gnl/get_next_line.h"
#include "./utils/PrintF/ft_printf.h"
#include "./utils/minilibx-linux/mlx.h"

void	ft_moves(t_data *d)
{
	d->moves += 1;
	write(1, "\nMoves :", 8);
	ft_putnbr_fd(d->moves, 1);
	write(1, "\n", 1);
}

void	ft_game_start(int nb)
{
	nb = nb + 1;
	ft_printf(YEL"================================");
	ft_printf("===============================\n");
	ft_printf("=======================  Jurassic swim  ==");
	ft_printf("=====================\n");
	ft_printf("=======================================");
	ft_printf("========================\n"COLOR_RESET);
	ft_printf(GRN"\n========================= Good luck ! ");
	ft_printf("=========================\n"COLOR_RESET);
}

void	ft_game_win(t_data *d)
{
	write(1, "\n", 1);
	ft_printf(YEL"================================");
	ft_printf("===============================\n");
	ft_printf("======================  CONGRATULATION !  ==");
	ft_printf("===================\n");
	ft_printf("========================================");
	ft_printf("=======================\n"COLOR_RESET);
	ft_printf(GRN"\n======================= TOTAL MOVES : %i ====", d->moves);
	ft_printf("===================\n"COLOR_RESET);
}

void	ft_game_invalid(t_data *d)
{
	(void) d;
	write(1, "\n", 1);
	ft_printf(YEL"================================");
	ft_printf("===============================\n");
	ft_printf("========================  MAP INVALID  ====");
	ft_printf("====================\n");
	ft_printf("=======================================");
	ft_printf("========================\n"COLOR_RESET);
	ft_printf(GRN"\n======================== Try again! ==========");
	ft_printf("=================\n\n"COLOR_RESET);
}

int	close_window(t_data *d)
{
	ft_printf(YEL"\n================================");
	ft_printf("===============================\n");
	ft_printf("=========================  GOODBYE !  ==");
	ft_printf("=======================\n");
	ft_printf("=======================================");
	ft_printf("========================\n"COLOR_RESET);
	ft_printf(GRN"\n======================= TOTAL MOVES : %i ====", d->moves);
	ft_printf("===================\n"COLOR_RESET);
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
