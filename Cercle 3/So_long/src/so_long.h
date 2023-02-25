/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:12:00 by lduheron          #+#    #+#             */
/*   Updated: 2023/02/25 18:04:25 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stddef.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <X11/keysym.h>
# include <string.h>
# include <limits.h>
# include <stdint.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h> 
# include "./utils/gnl/get_next_line.h"

# define COLOR_RESET "\e[0m"
# define RED "\e[0;31m"
# define GRN "\e[0;32m"
# define YEL "\e[0;33m"
# define MAG "\e[0;35m"
# define BLU "\e[0;34m"

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct s_d {
	int		moves;
	int		unlock;
	int		cpt_p;
	int		cpt_e;
	int		cpt_c;	
	int		x;
	int		y;
	int		p_x;
	int		p_y;
	int		n_px;
	int		n_py;
	int		collected;
	int		r_exit;
	int		ex_x;
	int		ex_y;
	int		nb_lin;
	int		nb_col;
	char	**map_f;
	int		**reachable;
	void	*ptr;
	void	*win;
	void	*wa;
	void	*flr;
	void	*p;
	void	*p_right;
	void	*p_left;
	void	*c;
	void	*ex;
	void	*e_c;
}	t_data;

int		all(t_data *d);
int		backtracking(t_data *d, int x, int y);
int		check_ber(char *file);
int		check_c_and_len(t_data *d);
int		check_frame(t_data *d);
int		check_rectangle(t_data *d);
int		close_window(t_data *d);
void	count_c(t_data *d, char c, int y, int x);
int		format(t_data *d);
void	ft_game_invalid(t_data *d);
void	ft_game_start(int nb);
void	ft_game_win(t_data *d);
void	ft_putchar(char c);
int		ft_put_all_image(t_data *d);
int		ft_put_image(t_data *d);

void	ft_putstr2(char *s);
void	ft_putnbr_fd(int nb, int fd);
char	*ft_itoa(int n);
int		key(int key, t_data *d);
void	map_creation(t_data *d, char *file);
void	map_error(int error, t_data *d);
void	map_init(t_data *d, char *file);
void	ft_moves(t_data *d);
// static size_t	nblen(int n);
int		ft_move_player(t_data *d);
int		**reachable_init(t_data *d);
char	**ft_split(char *s, char c);
char	*ft_strdup(char *src);
int		wdcount(char const *s, char c);
void	game_end(t_data *d);
void	game_end_before_win(t_data *d);
void	game_end_after_win(t_data *d);
void	game_end_full_erase(t_data *d);
void	free_image(t_data *d);
void	free_map(t_data *d);
void	ft_map_destroyer_int(int **map, t_data *d);
void	game_end_win(t_data *d);

#endif
