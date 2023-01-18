/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:59:10 by smorphet          #+#    #+#             */
/*   Updated: 2023/01/17 17:26:38 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

static void	set_weight(t_program *prog)
{
	double	weights[4];

	weights[0] = 0.0;
	weights[1] = 0.05;
	weights[2] = 0.4;
	weights[3] = 1.0;
	prog->weight = weights;
}

void	set_palette(t_program *prog, t_visualizer *man)
{
	int	colours[4];

	colours[0] = 0x000000;
	colours[3] = 0x000000;
	if (prog->colour == 1)
	{
		colours[1] = 0x00FFFF;
		colours[2] = 0X9C4F96;
	}
	else if (prog->colour == 2)
	{
		colours[1] = 0xFF00FF;
		colours[2] = 0xFFFFFF;
	}
	else
	{
		colours[1] = 0xFF0000;
		colours[2] = 0x00FF00;
	}
	set_weight(prog);
	man->palette = colours;
	man->quantity = sizeof(colours) / sizeof(colours[0]);
}

int	fract_colour(t_visualizer *man, t_program *prog)
{
	double	bln;
	int		in;

	in = 0;
	set_palette(prog, man);
	if (man->iter >= MAX_ITER)
		return (man->palette[man->quantity - 1]);
	bln = (double)(man->iter - 1) / (MAX_ITER - 1);
	while (in < man->quantity)
	{
		if (prog->weight[in] <= bln)
			break ;
		in++;
	}
	if (in >= (man->quantity - 1))
		return (man->palette[man->quantity - 1]);
	bln = (bln - prog->weight[in]) / (prog->weight[in + 1] - prog->weight[in]);
	man->r = lerp(get_r(man->palette[in]), get_r(man->palette[in + 1]), bln);
	man->g = lerp(get_g(man->palette[in]), get_g(man->palette[in + 1]), bln);
	man->b = lerp(get_b(man->palette[in]), get_b(man->palette[in + 1]), bln);
	return ((int)create_trgb(0, man->r, man->g, man->b));
}
