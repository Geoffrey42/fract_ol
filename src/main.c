/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 15:48:35 by ggane             #+#    #+#             */
/*   Updated: 2017/12/07 15:48:39 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int ac, char **av)
{
	t_data		*data;

	if (is_an_error_input(ac, av[1]))
		return (print_usage());
	data = set_data_structure(av[1]);
	display_fractal(data);
	display_image_in_window(data);
	delete_data(&data);
	return (0);
}
