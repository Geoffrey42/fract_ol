#include "fractol.h"

static int		check_key(int keycode, t_data *data)
{
	if (keycode == ESCAPE_KEY)
	{
		delete_data(&data);
		exit(1);
	}
	return (0);
}

static int		close_window(void)
{
	exit(1);
}

void			wait_for_escape_key_to_be_pressed(t_data *data)
{
	mlx_key_hook(data->win, check_key, data);
}

void			wait_for_cross_button_to_be_clicked(t_data *data)
{
	mlx_hook(data->win, 17, 0L, close_window, data);
}
