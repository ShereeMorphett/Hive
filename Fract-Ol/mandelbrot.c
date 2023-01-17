/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:39:20 by smorphet          #+#    #+#             */
/*   Updated: 2023/01/17 12:58:57 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

static void	mandelbrot_equation(t_visualizer *man)
{
	double	x;
	double	x_new;
	double	y;

	man->iter = 0;
	x = 0;
	y = 0;
	while ((x * x) + (y * y) <= 4.0 && man->iter < MAX_ITER)
	{
		x_new = (x * x) - (y * y) + man->fractal_x;
		y = 2.0 * x * y + man->fractal_y;
		x = x_new;
		man->iter++;
	}
}

void	fract_initialize(t_program *prog, t_visualizer *fract)
{
	fract->fract_w = (X_MAX - X_MIN) / prog->zoom;
	fract->fract_h = (Y_MAX - Y_MIN) / prog->zoom;
	fract->start_x = X_MIN + ((X_MAX - X_MIN) * 0.5) - \
	(fract->fract_w * 0.5) + prog->pan_x;
	fract->start_y = Y_MIN + ((Y_MAX - Y_MIN) * 0.5) - \
	(fract->fract_h * 0.5) + prog->pan_y;
	fract->pixel_y = 0;
}

void	mandelbrot_visualizer(t_program *prog)
{
	t_visualizer	man;
	double			bln_x;
	double			blend_y;

	fract_initialize(prog, &man);
	while (man.pixel_y < WIN_HEIGHT)
	{
		blend_y = (((double)man.pixel_y) / (WIN_HEIGHT - 1));
		man.fractal_y = lerp(man.start_y, man.start_y + man.fract_h, blend_y);
		man.pixel_x = 0;
		while (man.pixel_x < WIN_WIDTH)
		{
			bln_x = ((double)man.pixel_x / (WIN_WIDTH - 1));
			man.fractal_x = lerp(man.start_x, man.start_x + man.fract_w, bln_x);
			mandelbrot_equation(&man);
			place_pixel(&prog->image, man.pixel_x, man.pixel_y, \
						fract_colour(&man, prog));
			man.pixel_x++;
		}	
		man.pixel_y++;
	}
}
