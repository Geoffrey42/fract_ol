#ifndef DATA_STRUCTURE_H
# define DATA_STRUCTURE_H

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

#endif
