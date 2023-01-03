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

void	mandelbrot_equation(t_visualizer *man)
{
	man->iter = 0;
	man->x = 0;
	man->y = 0;
	while ((man->x * man->x) + (man->y * man->y) <= 4.0 && man->iter < MAX_ITER)
	{
		man->x_new = (man->x * man->x) - (man->y * man->y) + man->init_x;
		man->y = 2.0 * man->x * man->y + man->init_y;
		man->x = man->x_new;
		man->iter++;
	}
}

double lerp(double start, double end, double blend) 
{
    return (start * (1.0 - blend)) + (end * blend);
}

int	mandel_colour(int iter)
{
	double blend;
	double r;
	double g;
	double b;

	int colours[] = {BLACK, RED, BLACK};
	double weights[] = {0.0, 0.3, 1.0};
	int quantity = sizeof(colours) / sizeof(colours[0]);

	if (iter >= MAX_ITER)
		return colours[quantity - 1]; 

	// [1, MAX_ITER] => [0.0, 1.0]
	blend = (double)(iter - 1) / (MAX_ITER - 1);

	int index = 0;
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

	r = lerp(get_r(colours[index]), get_r(colours[index + 1]), blend);
	g = lerp(get_g(colours[index]), get_g(colours[index + 1]), blend);
	b = lerp(get_b(colours[index]), get_b(colours[index + 1]), blend);

	return ((int)create_trgb(0, r, g, b));
}

void	mandelbrot_visualizer(t_program *fract)
{
	t_image			img;
	t_visualizer	mandel;

	mandel.pixel_y = 0;
	img.image = mlx_new_image(fract->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	img.add = mlx_get_data_addr(img.image, &img.bpp, &img.line_length, &img.endian);
	while (mandel.pixel_y < WINDOW_HEIGHT)
	{
		mandel.init_y = ((double)mandel.pixel_y / (WINDOW_HEIGHT - 1));
		mandel.init_y = Y_MIN + mandel.init_y * (Y_MAX - Y_MIN);
		mandel.pixel_x = 0;
		while (mandel.pixel_x < WINDOW_WIDTH)
		{
			mandel.init_x = ((double)mandel.pixel_x / (WINDOW_WIDTH - 1));
			mandel.init_x = X_MIN + mandel.init_x * (X_MAX - X_MIN);
			mandelbrot_equation(&mandel);
			place_pixel(&img, mandel.pixel_x, mandel.pixel_y, mandel_colour(mandel.iter));
			mandel.pixel_x++;
		}	
		mandel.pixel_y++;
	}
	mlx_put_image_to_window(fract->mlx, fract->win, img.image, 0, 0);
}
