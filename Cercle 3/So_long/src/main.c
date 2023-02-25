/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 19:43:48 by lduheron          #+#    #+#             */
/*   Updated: 2023/02/25 18:16:36 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./utils/gnl/get_next_line.h"
#include "./utils/PrintF/ft_printf.h"
#include "./utils/minilibx-linux/mlx.h"

void	map_creation(t_data *d, char *file)
{
	char	*fichier;
	char	*backup;
	char	*mapp;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		map_error(1, d);
	mapp = ft_strdup("");
	fichier = get_next_line(fd);
	while (fichier)
	{
		if (!fichier)
			map_error(1, d);
		backup = mapp;
		mapp = ft_strjoin(backup, fichier);
		free(fichier);
		fichier = get_next_line(fd);
		d->nb_lin++;
	}
	d->map_f = ft_split(mapp, '\n');
	free(mapp);
	close(fd);
}

void	map_init(t_data *d, char *file)
{
	int	img;

	img = 64;
	d->cpt_p = 0;
	d->cpt_e = 0;
	d->cpt_c = 0;
	d->nb_lin = 0;
	d->nb_col = 0;
	d->map_f = NULL;
	d->reachable = NULL;
	d->r_exit = 0;
	d->collected = 0;
	d->moves = 0;
	d->unlock = 0;
	d->flr = mlx_xpm_file_to_image(d->ptr, "./xpm/floor.xpm", &img, &img);
	d->p_left = mlx_xpm_file_to_image(d->ptr, "./xpm/p_left.xpm", &img, &img);
	d->p_right = mlx_xpm_file_to_image(d->ptr, "./xpm/p_right.xpm", &img, &img);
	d->c = mlx_xpm_file_to_image(d->ptr, "./xpm/collectible.xpm", &img, &img);
	d->wa = mlx_xpm_file_to_image(d->ptr, "./xpm/wall.xpm", &img, &img);
	d->ex = mlx_xpm_file_to_image(d->ptr, "./xpm/exit.xpm", &img, &img);
	d->e_c = mlx_xpm_file_to_image(d->ptr, "./xpm/exit_closed.xpm", &img, &img);
	d->p = d->p_left;
	map_creation(d, file);
}

int	ft_move_player(t_data *d)
{
	if (d->map_f[d->n_py][d->n_px] != '1')
	{
		ft_moves(d);
		if (d->unlock == 1 && d->map_f[d->n_py][d->n_px] == 'E')
			game_end_win(d);
		if (d->map_f[d->n_py][d->n_px] == 'C')
			d->collected += 1;
		if (d->moves > 0 && d->map_f[d->n_py][d->n_px] != '1' && \
			d->map_f[d->n_py][d->n_px] != 'E' && d->n_px > 0 && d->n_py > 0)
			ft_put_image(d);
	}
	d->n_px = d->p_x;
	d->n_py = d->p_y;
	if (d->collected == d->cpt_c && d->unlock == 0)
	{
		mlx_put_image_to_window(d->ptr, d->win, d->ex, \
			d->ex_x * 64, d->ex_y * 64);
		d->unlock = 1;
	}
	return (1);
}

int	key(int key, t_data *d)
{
	if (key == XK_Escape)
		close_window(d);
	if (key == 'w' || key == XK_Up)
	{
		d->n_py = d->p_y - 1;
		ft_move_player(d);
	}
	if (key == 's' || key == XK_Down)
	{
		d->n_py = d->p_y + 1;
		ft_move_player(d);
	}
	if (key == 'a' || key == XK_Left)
	{
		d->n_px = d->p_x - 1;
		d->p = d->p_left;
		ft_move_player(d);
	}
	if (key == 'd' || key == XK_Right)
	{
		d->n_px = d->p_x + 1;
		d->p = d->p_right;
		ft_move_player(d);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	d;

	ft_game_start(0);
	d.ptr = mlx_init();
	if (!d.ptr || d.ptr == (void *)0)
		game_end(&d);
	if (argc != 2 || check_ber(argv[1]) != 1)
		game_end(&d);
	map_init(&d, argv[1]);
	d.nb_col = ft_strlen(d.map_f[0]) - 1;
	d.x = (d.nb_col + 1) * 64;
	d.y = d.nb_lin * 64;
	if (d.x > 2500 || d.y > 1300)
		map_error(3, &d);
	d.win = mlx_new_window(d.ptr, d.x, d.y + 32, "So long");
	if (d.win == (void *)0)
		map_error(3, &d);
	if (format(&d) == 1)
		ft_put_all_image(&d);
	mlx_hook(d.win, 2, 1L << 0, key, &d);
	mlx_hook(d.win, 17, 1L << 17, close_window, &d);
	mlx_loop(d.ptr);
	return (0);
}
