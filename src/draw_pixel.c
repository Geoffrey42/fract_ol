#include "fractol.h"

int		draw_pixel_in_image(t_data *data, int color)
{
	int		size;

	if (d->endian == 0)
	{
		size = ((d->y * d->size_line) + (d->x * d->bpp / 8));
		d->memory_area[size] = mlx_get_color_value(d->mlx, color);
		d->memory_area[size + 1] = mlx_get_color_value(d->mlx, color >> 8);
		d->memory_area[size + 2] = mlx_get_color_value(d->mlx, color >> 16);
	}
	else
	{
		size = ((d->y * d->size_line) + (d->x * d->bpp / 8));
		d->memory_area[size] = mlx_get_color_value(d->mlx, color >> 16);
		d->memory_area[size + 1] = mlx_get_color_value(d->mlx, color >> 8);
		d->memory_area[size + 2] = mlx_get_color_value(d->mlx, color);
	}
	return (0);
}