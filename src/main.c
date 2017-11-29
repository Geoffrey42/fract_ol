#include "fractol.h"

int		main(int ac, char **av)
{
	t_data		*data;

	if (is_an_error_input(ac, av))
		return (print_usage());
	data = set_data_structure(av[1]);
	display_fractal(data);
	delete_data(&data);
	return (0);
}
