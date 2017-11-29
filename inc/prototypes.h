#ifndef PROTOTYPES_H
# define PROTOTYPES_H

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

#endif
