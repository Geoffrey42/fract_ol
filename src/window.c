#include "fractol.h"

void		display_image_in_window(t_data *data)
{
	wait_for_escape_key_to_be_pressed(data);
	wait_for_cross_button_to_be_clicked(data);
	mlx_put_image_to_window(data->mlx, data->win, data->image_id, 0, 0);
	wait_for_mouse_wheel_to_be_scrolled(data);
	mlx_loop(data->mlx);
}
