/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_limits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 15:47:30 by ggane             #+#    #+#             */
/*   Updated: 2017/12/07 15:47:32 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		is_not_below_minimal_limits(t_data *d)
{
	if (d->x1 >= FRACTAL_MINIMAL_LIMIT && d->y1 >= FRACTAL_MINIMAL_LIMIT)
		return (1);
	return (0);
}

static int		is_not_above_maximal_limits(t_data *d)
{
	if (d->x2 >= FRACTAL_MAXIMAL_LIMIT && d->y2 >= FRACTAL_MAXIMAL_LIMIT)
		return (1);
	return (0);
}

int				is_not_beyond_limits(t_data *data)
{
	if (is_not_below_minimal_limits(data) && is_not_above_maximal_limits(data))
		return (1);
	return (0);
}
