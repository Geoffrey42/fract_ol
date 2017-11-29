#include "fractol.h"

static void		set_z_value(t_data *d)
{
	int		tmp;

	tmp = d->zr;
	while ((d->zr * d->zr) + (d->zi * d->zi) < 4 && d->i < d->max_iteration)
	{
		d->zr = (d->zr * d->zr) - (d->zi * d->zi) + d->cr;
		d->zi = 2 * d->zi * tmp + d->ci;
		d->i++;
	}
}

void			draw_mandelbrot(t_data *d)
{
	while (d->x < d->width)
	{
		while (d->y < d->height)
		{
			set_z_value(d);
			d->y++;
		}
		d->x++;
	}
	if (d->i == d->max_iteration)
		draw_pixel_in_image(d, RED);
	else
		draw_pixel_in_image(d, GREEN);
}
