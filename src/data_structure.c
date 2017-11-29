#include "fractol.h"

/*
** This function manages t_data structure settings
*/

t_data		*set_data_structure(char *arg)
{
	t_data	*new;

	if (!(new = (t_data *)malloc(sizeof(t_data))))
		return (NULL);
	new->mlx = mlx_init();
	new->x = 0;
	new->y = 0;
	new->i = 0;
	new->x1 = -2.1;
	new->x2 = 0.6;
	new->y1 = -1.2;
	new->y2 = 1.2;
	new->zoom = 100;
	new->max_iteration = 50;
	new->width = (new->x2 - new->x1) * new->zoom;
	new->height = (new->y2 - new->y1) * new->zoom;
	new->fractal = ft_strdup(arg);
	new->win = mlx_new_window(new->mlx, new->width, new->height, new->fractal);
	new->image_id = mlx_new_image(new->mlx, new->width, new->height);
	new->memory_area = mlx_get_data_addr(new->image_id, &new->bpp,\
			&new->size_line, &new->endian);
	return (new);
}
