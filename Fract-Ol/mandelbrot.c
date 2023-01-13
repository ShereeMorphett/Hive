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
#define MAX_ITER 200
# define	X_MIN  -2.0
# define	X_MAX  1.0
# define    Y_MIN  -1.5
# define    Y_MAX  1.5

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
 void set_palette(t_program *prog, t_visualizer *man)
{
	int colours[4];
	colours[0] = BLACK;
	colours[3] = BLACK;
	if (prog->colour == 1)
	{
		colours[1] = 0x0000FF; // blue
		colours[2] = 0X9C4F96; // berry
	}
	else
	{
		colours[1] = 0xFF0000;
		colours[2] = 0x00FF00;
	}
	double weights[4] = {0.0, 0.1, 0.2, 1.0};
	man->palette = colours;
	man->weight = weights;
	man->quantity = sizeof(colours) / sizeof(colours[0]);
}

static int	mandel_colour(t_visualizer *man, t_program *prog)
{
	double blend;
	int index;
	
	index = 0;
	set_palette(prog, man);
	if (man->iter >= MAX_ITER)
		return man->palette[man->quantity - 1]; 
	// [1, MAX_ITER] => [0.0, 1.0]
	blend = (double)(man->iter - 1) / (MAX_ITER - 1);
	while (index < man->quantity)
 	{
		if (man->weight[index] <= blend)
			break;
		index++;
	}
	if (index >= (man->quantity - 1))
		return man->palette[man->quantity-1];
	blend = (blend - man->weight[index])/(man->weight[index+1] - man->weight[index]);
	man->r = lerp(get_r(man->palette[index]), get_r(man->palette[index + 1]), blend);
	man->g = lerp(get_g(man->palette[index]), get_g(man->palette[index + 1]), blend);
	man->b = lerp(get_b(man->palette[index]), get_b(man->palette[index + 1]), blend);
	return ((int)create_trgb(0, man->r, man->g, man->b));
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
	start_x = X_MIN + ((X_MAX - X_MIN) * 0.5) - (fractal_w * 0.5) + prog->pan_adjust_x;
 	start_y = Y_MIN + ((Y_MAX - Y_MIN) * 0.5) - (fractal_h * 0.5) + prog->pan_adjust_y;
	mandel.pixel_y = 0;

	while (mandel.pixel_y < WINDOW_HEIGHT)
	{
		double blend_y = (((double)mandel.pixel_y)/ (WINDOW_HEIGHT - 1));
		mandel.fractal_y = lerp(start_y, start_y + fractal_h, blend_y);
		mandel.pixel_x = 0;
		while (mandel.pixel_x < WINDOW_WIDTH)
		{
			double blend_x = ((double)mandel.pixel_x / (WINDOW_WIDTH - 1));
			mandel.fractal_x = lerp(start_x, start_x + fractal_w, blend_x) ;
			mandelbrot_equation(&mandel);
			place_pixel(&prog->image, mandel.pixel_x, mandel.pixel_y, mandel_colour(&mandel, prog));
			mandel.pixel_x++;
		}	
		mandel.pixel_y++;
	}
}
