/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 15:49:18 by ggane             #+#    #+#             */
/*   Updated: 2017/12/07 15:49:21 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		reset_complex_values(t_data *d)
{
	d->cr = d->x / d->zoom + d->x1;
	d->ci = d->y / d->zoom + d->y1;
	d->zr = 0;
	d->zi = 0;
	d->i = 0;
}

static void		set_complex_number_value(t_data *d)
{
	double	tmp;

	while ((d->zr * d->zr) + (d->zi * d->zi) < 4 && d->i < d->max_iteration)
	{
		tmp = d->zr;
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
			if (d->i == d->max_iteration)
				draw_pixel_in_image(d, RED);
			else
				draw_pixel_in_image(d, GREEN);
			d->y++;
		}
		d->y = 0;
		d->x++;
	}
}
