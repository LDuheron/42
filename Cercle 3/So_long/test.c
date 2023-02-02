#include "minilibx-linux/mlx.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <X11/keysym.h>

// ./So_long

///// UTILS /////

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

size_t	ft_strlen(char const *str)
{
	int	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

void	ft_putstr(char *s)
{
	if (s != NULL)
		write(1, s, ft_strlen(s));
}

////  VARIABLES ////

typedef struct s_image {
	void *wall;
	void *floor;
	void *perso;
	void *collectible;
	void *exit;
}			t_image;

typedef struct s_data {
	void *mlx_ptr;
	void *mlx_win;
}			t_data;

//// GESTION DES EVENTS CLAVIER //// #include <X11/keysym.h>

int	key(int key, void *param)
{
	if (key == XK_Escape)
	{
		ft_putstr("Escape\n");
		// gameclose(map test);
		// return(0)
	}
	if (key == 'w' || key == XK_Up)
		ft_putstr("Haut\n");
	if (key == 's' || key == XK_Down)
		ft_putstr("Bas\n");
	if (key == 'a' || key == XK_Left)
		ft_putstr("Gauche\n");
	if (key == 'd' || key == XK_Right)
		ft_putstr("Droit\n");
	return (0);
}

///// INITIALISATION IMAGE /////

void	ft_image(t_data *data, t_image *image)
{
	int	img_width = 200;
	int	img_height = 200;
	char *path_wall = "./xpm/wall2.xpm";
	char *path_floor = "./xpm/floorv2.xpm";
	char *path_perso = "./xpm/persov2.xpm";
	char *path_collectible = "./xpm/key2.xpm";
	char *path_exit = "./xpm/exit2.xpm";
	
	image->floor = mlx_xpm_file_to_image(data->mlx_ptr, path_floor, &img_width, &img_height);
	image->perso = mlx_xpm_file_to_image(data->mlx_ptr, path_perso, &img_width, &img_height);
	image->collectible = mlx_xpm_file_to_image(data->mlx_ptr, path_collectible, &img_width, &img_height);
	image->wall = mlx_xpm_file_to_image(data->mlx_ptr, path_wall, &img_width, &img_height);
	image->exit = mlx_xpm_file_to_image(data->mlx_ptr, path_exit, &img_width, &img_height);

}

///// INITIALISATION WINDOW /////

int window_init(t_data *data, t_image *image)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (0); // error
	data->mlx_win = mlx_new_window(data->mlx_ptr, 1500, 900, "Window");
	if (data->mlx_win == NULL)
	{
		free(data->mlx_win);
		return(0); //error
	}
	ft_image(data, image);
	return (1);
}


///// MAIN /////

int	main(int argc, char **argv)
{
	t_image	image;
	t_data data;
	// if (argc != 1)
	// 	return (0);	//error
	window_init(&data, &image);
	mlx_key_hook(data.mlx_win, key, (void *)0);
	mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, image.perso, 0, 0);
	mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, image.floor, 150, 0);
	mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, image.collectible, 300, 0);
	mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, image.exit, 450, 0);
	mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, image.wall, 600, 0);
	mlx_loop(data.mlx_ptr);
}