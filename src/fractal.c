#include "fractol.h"

static char		**create_fractals_array(void)
{
	return (ft_strsplit("mandelbrot", ','));
}

void			display_fractal(t_data *data)
{
	static int	(*display_fractal[])(t_data *) = {FRACTALS};
	char		**fractals;
	int			i;

	i = 0;
	fractals = create_fractals_array();
	while (fractals[i])
	{
		if (!(ft_strcmp(data->fractal, fractals[i])))
			break ;
		i++;
	}
	erase_char_array(fractals);
	display_fractal[i](data);
}
