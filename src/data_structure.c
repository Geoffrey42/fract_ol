#include "fractol.h"

/*
** This function manages t_data structure settings
*/

void		get_memory_area(t_data *data)
{
	data->memory_area = mlx_get_data_addr(data->image_id, &data->bpp,\
			&data->size_line, &data->endian);
}

t_data		*set_data_structure(char *arg)
{
	t_data	*new;

	if (!(new = (t_data *)malloc(sizeof(t_data))))
		return (NULL);
	new->mlx = mlx_init();
	new->x = 0;
	new->y = 0;
	new->i = 0;
	new->x1 = FRACTAL_MINIMAL_LIMIT;
	new->x2 = FRACTAL_MAXIMAL_LIMIT;
	new->y1 = FRACTAL_MINIMAL_LIMIT;
	new->y2 = FRACTAL_MAXIMAL_LIMIT;
	new->zoom = 125;
	new->max_iteration = 50;
	new->color = rand();
	new->width = (new->x2 - new->x1) * new->zoom;
	new->height = (new->y2 - new->y1) * new->zoom;
	new->fractal = ft_strdup(arg);
	new->win = mlx_new_window(new->mlx, WIDTH, HEIGHT, new->fractal);
	new->image_id = mlx_new_image(new->mlx, WIDTH, HEIGHT);
	get_memory_area(new);
	return (new);
}
