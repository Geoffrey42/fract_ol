/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 15:47:39 by ggane             #+#    #+#             */
/*   Updated: 2017/12/07 15:47:41 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	delete_data(t_data **data)
{
	mlx_destroy_image((*data)->mlx, (*data)->image_id);
	mlx_destroy_window((*data)->mlx, (*data)->win);
	ft_strdel(&(*data)->fractal);
	if (*data)
	{
		free(*data);
		*data = NULL;
	}
}
