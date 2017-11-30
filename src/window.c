#include "fractol.h"
// don't forget to delete debug

void		display_image_in_window(t_data *data)
{
	ft_putendl("start display_image_in_window()");
	wait_for_escape_key_to_be_pressed(data);
	wait_for_cross_button_to_be_clicked(data);
	wait_for_mouse_wheel_to_be_scrolled(data);
	ft_putendl("wait_for_mouse_wheel_to_be_scrolled() ok");
	mlx_put_image_to_window(data->mlx, data->win, data->image_id, 0, 0);
	ft_putendl("mlx_put_image_to_window() ok");
	mlx_loop(data->mlx);
}
