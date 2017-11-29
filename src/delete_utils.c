#include "fractol.h"

void	delete_data(t_data **data)
{
	mlx_destroy_image((*data)->mlx, (*data)->image_id);
	mlx_destroy_window((*data)->mlx, (*data)->win);
	ft_strdel(&(*data)->fractal);
	if (*data)
	{
		free(*data);
		*data = NULL;
	}
}
