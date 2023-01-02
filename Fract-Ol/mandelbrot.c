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
#define MAX_ITER 1000

void	mandelbrot_equation(t_visualizer *man)
{
	man->iter = 0;
	while ((man->x * man->x) + (man->y * man->y) <= 4.0 && man->iter < MAX_ITER)
	{
		man->x_new = (man->x * man->x) - (man->y * man->y) + man->init_x;
		man->y = 2.0 * man->x * man->y + man->init_y;
		man->x = man->x_new;
		man->iter++;
	}
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
			mandel.x = 0;
			mandel.y = 0;
			mandelbrot_equation(&mandel);
			if (mandel.iter < MAX_ITER)
				place_pixel(&img, mandel.pixel_x, mandel.pixel_y, WHITE);
			else
				place_pixel(&img, mandel.pixel_x, mandel.pixel_y, BLACK);
			mandel.pixel_x++;
		}	
		mandel.pixel_y++;
	}
	mlx_put_image_to_window(fract->mlx, fract->win, img.image, 0, 0);
}
