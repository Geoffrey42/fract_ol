#include "fractol.h"

static int		is_not_below_minimal_limits(t_data *d)
{
	if (d->x1 >= FRACTAL_MINIMAL_LIMIT && d->y1 >= FRACTAL_MINIMAL_LIMIT)
		return (1);
	return (0);
}

static int		is_not_above_maximal_limits(t_data *d)
{
	if (d->x2 >= FRACTAL_MAXIMAL_LIMIT && d->y2 >= FRACTAL_MAXIMAL_LIMIT)
		return (1);
	return (0);
}

static int		is_not_beyond_limits(t_data *data)
{
	if (is_not_below_minimal_limits(data) && is_not_above_maximal_limits(data))
		return (1);
	return (0);
}

int				check_mouse_scroll(int mousecode, t_data *data)
{
	double		gap;

	if (mousecode == SCROLL_UP)
	{
		data->zoom *= 1.1;
		gap = (data->x2 - data->x1) - (HEIGHT / data->zoom);
		data->x1 += ((double)data->x / HEIGHT) * gap;
		data->x2 -= ((HEIGHT - (double)data->x) / HEIGHT) * gap;
		data->y1 += ((double)data->y / WIDTH) * gap;
		data->y2 -= ((HEIGHT - (double)data->y) / WIDTH) * gap;
	}
	else if (mousecode == SCROLL_DOWN && is_not_beyond_limits(data))
	{
		data->zoom /= 1.1;
		gap = (HEIGHT / data->zoom) + (data->x2 + data->x1);
		data->x1 -= ((double)data->x / HEIGHT) * gap;
		data->x2 += ((HEIGHT - (double)data->x) / HEIGHT) * gap;
		data->y1 -= ((double)data->y / WIDTH) * gap;
		data->y2 += ((HEIGHT - (double)data->y) / WIDTH) * gap;
	}
	return (0);
}
