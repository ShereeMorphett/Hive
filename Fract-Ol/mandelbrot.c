/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:39:20 by smorphet          #+#    #+#             */
/*   Updated: 2023/01/02 16:39:26 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

static void	mandelbrot_equation(t_visualizer *man)
{
	double x;
	double x_new;
	double y;

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

void	mandelbrot_visualizer(t_program *prog)
{
	t_visualizer	mandel;

	double fractal_w;
	double fractal_h;
	double start_x;
	double start_y;

	fractal_w = (X_MAX - X_MIN) / prog->zoom;
	fractal_h = (Y_MAX - Y_MIN) / prog->zoom;
	start_x = X_MIN + ((X_MAX - X_MIN) * 0.5) - (fractal_w * 0.5) + prog->pan_x;
 	start_y = Y_MIN + ((Y_MAX - Y_MIN) * 0.5) - (fractal_h * 0.5) + prog->pan_y;
	mandel.pixel_y = 0;

	while (mandel.pixel_y < WIN_HEIGHT)
	{
		double blend_y = (((double)mandel.pixel_y)/ (WIN_HEIGHT - 1));
		mandel.fractal_y = lerp(start_y, start_y + fractal_h, blend_y);
		mandel.pixel_x = 0;
		while (mandel.pixel_x < WIN_WIDTH)
		{
			double blend_x = ((double)mandel.pixel_x / (WIN_WIDTH - 1));
			mandel.fractal_x = lerp(start_x, start_x + fractal_w, blend_x) ;
			mandelbrot_equation(&mandel);
			place_pixel(&prog->image, mandel.pixel_x, mandel.pixel_y, fract_colour(&mandel, prog));
			mandel.pixel_x++;
		}	
		mandel.pixel_y++;
	}
}
