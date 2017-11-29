#ifndef FRACTOL_H
# define FRACTOL_H

# ifdef __linux__
#  include "../inc_linux/mlx.h"
#  define ESCAPE_KEY 65307
# endif

# ifdef __APPLE__
#  include "mlx.h"
#  define ESCAPE_KEY 53 
# endif

# include <fcntl.h>
# include <math.h>
# include "libft.h"

# define FRACTALS mandelbrot

typedef struct	s_data
{
	void		*mlx;
	void		*win;
	void		*image_id;
	char		*memory_area;
	char		*map_cpy;
	char		*fractal;
	int			bpp;
	int			x1;
	int			x2;
	int			y1;
	int			y2;
	int			width;
	int			height;
	int			zoom;
	int			max_iteration;
	int			cr;
	int			ci;
	int			zr;
	int			zi;
	int			i;
}				t_data;

/*
** data_structure.c
*/

t_data			*set_data_structure(char *arg);

/*
** delete_utils.c
*/

void			delete_data(t_data **data);

/*
** display_utils.c
*/

int				print_usage(void);

/*
** fractal.c
*/

void			display_fractal(t_data *data);

/*
** check_input.c
*/

int				is_an_error_input(int ac, char *arg);

#endif
