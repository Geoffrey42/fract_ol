#include "fractol.h"

void		display_image_in_window(t_data *data)
{
	if (escape_key_is_pressed(data) || close_button_is_clicked(data))
		return ;
	mlx_put_image_to_window(data->mlx, data->win, data->image_id, 0, 0);
	mlx_loop(data->mlx);
}
