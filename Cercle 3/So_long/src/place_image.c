/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 20:01:11 by lduheron          #+#    #+#             */
/*   Updated: 2023/02/25 18:57:10 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./utils/gnl/get_next_line.h"
#include "./utils/PrintF/ft_printf.h"
#include "./utils/minilibx-linux/mlx.h"

char	*ft_strjointext(char *s1, char *s2)
{
	char	*join;
	int		i;
	int		j;

	j = -1;
	i = -1;
	if (s1 == NULL)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	join = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (join != NULL)
	{
		while (s1[++i] != '\0' && s1 != NULL)
			join[i] = s1[++j];
		j = -1;
		while (s2[++j] != '\0')
			join[i++] = s2[j];
		join[i] = '\0';
	}
	return (join);
}

void	put_text(t_data *d)
{	
	char	*str;
	char	*number;

	number = ft_itoa(d->moves - 1);
	str = ft_strjointext("MOVES : ", number);
	mlx_set_font(d->ptr, d->win, "9x15bold");
	mlx_string_put(d->ptr, d->win, d->x / 2, d->y + 16, 0x000000, str);
	free(str);
	free(number);
	str = NULL;
	number = NULL;
	number = ft_itoa(d->moves);
	str = ft_strjointext("MOVES : ", number);
	mlx_string_put(d->ptr, d->win, d->x / 2, d->y + 16, 0xffffff, str);
	free(str);
	free(number);
}

int	ft_put_all_image(t_data *d)
{
	int	x;
	int	y;

	y = 0;
	while (y < d->nb_lin)
	{
		x = 0;
		while (x < d->nb_col + 1)
		{
			if (d->map_f[y][x] == 'P')
				mlx_put_image_to_window(d->ptr, d->win, d->p, x * 64, y * 64);
			else if (d->map_f[y][x] == '0')
				mlx_put_image_to_window(d->ptr, d->win, d->flr, x * 64, y * 64);
			else if (d->map_f[y][x] == 'C')
				mlx_put_image_to_window(d->ptr, d->win, d->c, x * 64, y * 64);
			else if (d->map_f[y][x] == '1')
				mlx_put_image_to_window(d->ptr, d->win, d->wa, x * 64, y * 64);
			else if (d->map_f[y][x] == 'E')
				mlx_put_image_to_window(d->ptr, d->win, d->e_c, x * 64, y * 64);
			x++;
		}
		y++;
	}
	put_text(d);
	return (1);
}

int	ft_put_image(t_data *d)
{
	int	x;
	int	y;

	x = d->n_px;
	y = d->n_py;
	d->map_f[d->n_py][d->n_px] = 'P';
	d->map_f[d->p_y][d->p_x] = '0';
	mlx_put_image_to_window(d->ptr, d->win, d->flr, d->p_x * 64, d->p_y * 64);
	mlx_put_image_to_window(d->ptr, d->win, d->p, (x * 64), (y * 64));
	d->p_x = d->n_px;
	d->p_y = d->n_py;
	put_text(d);
	return (0);
}
