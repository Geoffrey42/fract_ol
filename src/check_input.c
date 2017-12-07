/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 15:47:07 by ggane             #+#    #+#             */
/*   Updated: 2017/12/07 15:47:11 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		is_not_registered_fractal(char *arg)
{
	int		i;
	int		missing;
	char	**fractals;

	i = 0;
	missing = 1;
	fractals = create_fractals_array();
	while (fractals[i])
	{
		if (!(ft_strcmp(arg, fractals[i])))
			missing = 0;
		i++;
	}
	erase_char_array(fractals);
	return (missing);
}

int				is_an_error_input(int ac, char *arg)
{
	if (ac != 2 || is_not_registered_fractal(arg))
		return (1);
	return (0);
}
