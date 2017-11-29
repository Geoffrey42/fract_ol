#include "fractol.h"

static void		reset_complex_values(t_data *d)
{
	d->cr = d->x / d->zoom + d->x1;
	d->cr = d->y / d->zoom + d->y1;
	d->zr = 0;
	d->zi = 0;
	d->i = 0;
}

static void		set_complex_number_value(t_data *d)
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
			reset_complex_values(d);
			set_complex_number_value(d);
			d->y++;
		}
		d->y = 0;
		d->x++;
	}
	if (d->i == d->max_iteration)
	{
		ft_putendl("dessine pixel RED");
		draw_pixel_in_image(d, RED);
	}
	else
	{
		ft_putendl("dessine pixel GREEN");
		draw_pixel_in_image(d, GREEN);
	}
}
