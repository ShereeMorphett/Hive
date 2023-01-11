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
#include <stdio.h>
#define MAX_ITER 1000
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
// int set_palette(t_visualizer *mandel, t_program *fract)
// {
// 	int colours[] = {BLACK, YELLOW, BLACK};
// 	double weights[] = {0.0, 0.05, 1.0};

// 	mandel->weight = weights;
// 	mandel->palette = colours;

// }

static int	mandel_colour(t_visualizer *mandel)
{
	double blend;

	int colours[] = {WHITE, BLACK};
	double weights[] = {0.0, 1.0};

	// if (fract->colour == 0)	
	// {
	// 	colours[] = {WHITE, GREEN, BLACK};
	// 	weights[] = {0.0, 0.05, 1.0};
	// }

	// else if (fract->colour == 1)
	// {
	// 	colours[] = {BLACK, GREEN, YELLOW, BLACK};
	// 	weights[] = {0.0, 0.1, 0.3, 1.0};

	// }
	mandel->palette = colours;
	mandel->weight = weights;

	int quantity = sizeof(colours) / sizeof(colours[0]);
	int index = 0;
	if (mandel->iter >= MAX_ITER)
		return colours[quantity - 1]; 
	// [1, MAX_ITER] => [0.0, 1.0]
	blend = (double)(mandel->iter - 1) / (MAX_ITER - 1);
	while (index < quantity)
 	{
		if (weights[index] <= blend)
			break;
		index++;
	}
	if (index >= quantity-1)
		return colours[quantity-1];
	blend = (blend - weights[index])/(weights[index+1] - weights[index]);
	//recalculate blend then LERP
	mandel->r = lerp(get_r(colours[index]), get_r(colours[index + 1]), blend);
	mandel->g = lerp(get_g(colours[index]), get_g(colours[index + 1]), blend);
	mandel->b = lerp(get_b(colours[index]), get_b(colours[index + 1]), blend);
	return ((int)create_trgb(0, mandel->r, mandel->g, mandel->b));
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
	start_x = X_MIN + ((X_MAX - X_MIN) * 0.5) - (fractal_w * 0.5) + prog->pan_adjust;
 	start_y = Y_MIN + ((Y_MAX - Y_MIN) * 0.5) - (fractal_h * 0.5);



//blend = amount through each axis (0.0 - 1.0 (%))
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
			place_pixel(&prog->image, mandel.pixel_x, mandel.pixel_y, mandel_colour(&mandel));
			mandel.pixel_x++;
		}	
		mandel.pixel_y++;
	}
}
