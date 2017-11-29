#include "fractol.h"

static char		**create_fractals_array(void)
{
	return (ft_strsplit("mandelbrot", ','));
}

void			display_fractal(t_data *data)
{
	static int	(*display_fractal[])(t_data *) = {FRACTALS};
	char		**fractals;

	fractals = create_fractals_array();
	erase_char_array(fractals);
}
