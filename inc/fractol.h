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

# include "libft.h"
# include <fcntl.h>
# include <math.h>
# include "prototypes.h"
# include "data_structure.h"

# define FRACTALS mandelbrot

#endif
