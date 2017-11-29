#include "fractol.h"

static size_t	get_array_char_size(char **fractals)
{
	size_t	size;

	size = 0;
	while (fractals[size])
		size++;
	return (size);
}

static int		is_not_registered_fractal(char *arg)
{
	int		i;
	int		missing;

	i = 0;
	missing = 0;
	while (fractals[i])
	{
		if (!(ft_strcmp(arg, fractals[i])))
			missing = 1;
		i++;
	}
	return (missing);
}

int				is_an_error_input(int ac, char *arg)
{
	if (ac != 2 || is_not_registered_fractal(arg))
		return (1);
	return (0);
}
