#include "fractol.h"

static void		set_scroll_up_limits(t_data *data)
{
	double		gap;

	data->zoom *= 1.1;
	gap = (data->x2 - data->x1) - (HEIGHT / data->zoom);
	data->x1 += ((double)data->x / HEIGHT) * gap;
	data->x2 -= ((HEIGHT - (double)data->x) / HEIGHT) * gap;
	data->y1 += ((double)data->y / WIDTH) * gap;
	data->y2 -= ((HEIGHT - (double)data->y) / WIDTH) * gap;
}

static void		set_scroll_down_limits(t_data *data)
{
	double		gap;

	data->zoom /= 1.1;
	gap = (HEIGHT / data->zoom) + (data->x2 + data->x1);
	data->x1 -= ((double)data->x / HEIGHT) * gap;
	data->x2 += ((HEIGHT - (double)data->x) / HEIGHT) * gap;
	data->y1 -= ((double)data->y / WIDTH) * gap;
	data->y2 += ((HEIGHT - (double)data->y) / WIDTH) * gap;
}

static int		check_mouse_scroll(int mousecode, t_data *data)
{
	if (mousecode == SCROLL_UP)
		set_scroll_up_limits(data);
	else if (mousecode == SCROLL_DOWN && is_not_beyond_limits(data))
		set_scroll_down_limits(data);
	ft_bzero(data->memory_area, HEIGHT * WIDTH * 4);
	display_fractal(data);
	//mlx_put_image_to_window(data->mlx, data->win, data->image_id, 0, 0);
	return (0);
}

void			wait_for_mouse_wheel_to_be_scrolled(t_data *data)
{
	mlx_mouse_hook(data->win, check_mouse_scroll, data);
}
