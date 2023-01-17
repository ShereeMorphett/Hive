/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:58:36 by smorphet          #+#    #+#             */
/*   Updated: 2023/01/17 12:58:40 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

static void	julia_equation(t_visualizer *julia, t_program *prog)
{
	double	x;
	double	x_new;
	double	y;

	julia->iter = 0;
	x = julia->fractal_x;
	y = julia->fractal_y;
	while ((x * x) + (y * y) <= 4.0 && julia->iter < MAX_ITER)
	{
		x_new = (x * x) - (y * y) + prog->c_x;
		y = 2.0 * x * y + prog->c_y;
		x = x_new;
		julia->iter++;
	}
}

void	julia_visualizer(t_program *prog)
{
	t_visualizer	julia;
	double			bln_x;
	double			blend_y;

	fract_initialize(prog, &julia);
	while (julia.pixel_y < WIN_HEIGHT)
	{
		blend_y = (((double) julia.pixel_y) / (WIN_HEIGHT - 1));
		julia.fractal_y = lerp(julia.start_y, \
		julia.start_y + julia.fract_h, blend_y);
		julia.pixel_x = 0;
		while (julia.pixel_x < WIN_WIDTH)
		{
			bln_x = ((double)julia.pixel_x / (WIN_WIDTH - 1));
			julia.fractal_x = lerp(julia.start_x, \
			julia.start_x + julia.fract_w, bln_x);
			julia_equation(&julia, prog);
			place_pixel(&prog->image, julia.pixel_x, julia.pixel_y, \
			fract_colour(&julia, prog));
			julia.pixel_x++;
		}	
		julia.pixel_y++;
	}
}
