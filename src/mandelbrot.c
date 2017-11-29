#include "fractol.h"

static void		set_z_value(t_data *d)
{
	int		tmp;

	tmp = d->zr;
	while ((d->zr * d->zr) + (d->zi * d->zi) < 4 && d->i < d->max_iteration)
	{
		d->zr = (d->zr * d->zr) - (d->zi * d->zi) + d->cr;
		d->zi = 2 * d->zi * tmp + d->ci;
		i++;
	}
}

void			draw_mandelbrot(t_data *data)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (x < data->width)
	{
		while (y < data->height)
		{
			set_z_value(data);
			y++;
		}
		x++;
	}
	if (data->i == data->max_iteration)
		draw_pixel_in_image(data, RED);
	else
		draw_pixel_in_image(data, GREEN);
}
