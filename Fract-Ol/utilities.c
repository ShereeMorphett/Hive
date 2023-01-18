/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:59:41 by smorphet          #+#    #+#             */
/*   Updated: 2023/01/17 16:04:37 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	cleanup_and_exit(t_program *program, int result)
{
	cleanup(program);
	exit(result);
}

void	cleanup(t_program *program)
{
	if (!program)
		return ;
	if (program->mlx)
	{
		if (program->image.handle)
		{
			mlx_destroy_image(program->mlx, program->image.handle);
			program->image.handle = NULL;
			program->image.add = NULL;
		}
		if (program->win)
		{
			mlx_destroy_window(program->mlx, program->win);
			program->win = NULL;
		}
		program->weight = NULL;
		program->mlx = NULL;
	}
}

void	place_pixel(t_image *img, int x, int y, int color)
{
	char	*destination;

	destination = img->add + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)destination = color;
}

double	lerp(double start, double end, double blend)
{
	return ((start * (1.0 - blend)) + (end * blend));
}
