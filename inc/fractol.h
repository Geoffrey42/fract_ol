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

# define FRACTALS &draw_mandelbrot
# define PINK 0x00FF358B
# define WHITE 0x00FFFFFF
# define RED 0x008E3557
# define BLUE 0x004BB5C1
# define BROWN 0x00BD8D46
# define GREEN 0x0096CA2D
# define ORANGE 0x00FEB201
# define YELLOW 0x00F2E203

typedef struct	s_data
{
	void		*mlx;
	void		*win;
	void		*image_id;
	char		*memory_area;
	char		*map_cpy;
	char		*fractal;
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	double		width;
	int			endian;
	int			bpp;
	int			size_line;
	int			x;
	int			y;
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
** draw_pixel.c
*/

int				draw_pixel_in_image(t_data *data, int color);

/*
** mandelbrot.c
*/

void			draw_mandelbrot(t_data *d);

/*
** fractal.c
*/

char			**create_fractals_array(void);
void			display_fractal(t_data *data);

/*
** events.c
*/

int				check_key(int keycode, t_data *data);
int				close_button_is_clicked(t_data *data);
int				escape_key_is_pressed(t_data *data);

/*
** window.c
*/

void			display_image_in_window(t_data *data);

/*
** check_input.c
*/

int				is_an_error_input(int ac, char *arg);

#endif
