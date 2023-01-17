/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:04:52 by smorphet          #+#    #+#             */
/*   Updated: 2023/01/17 16:04:59 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	mouse_map(int keycode, int x, int y, t_program *prog)
{
	if (keycode == 5)
	{	
		prog->zoom += 0.25;
		prog->image_dirty = 1;
	}
	else if (keycode == 4)
	{
		prog->zoom = fmax(prog->zoom - 0.25, 0.001);
		prog->image_dirty = 1;
	}
	return (0);
}

static int	zoom(int keycode, t_program *prog)
{
	if (keycode == 61 || keycode == 24)
	{
		prog->zoom += 0.75;
		prog->image_dirty = 1;
	}
	else if (keycode == 45 || keycode == 27)
	{
		prog->zoom = fmax(prog->zoom - 0.75, 0.01);
		prog->image_dirty = 1;
	}
	return (0);
}

static int	panning(int keycode, t_program *prog)
{
	if (keycode == 125)
	{
		prog->pan_y -= 0.25;
		prog->image_dirty = 1;
	}
	else if (keycode == 126)
	{
		prog->pan_y += 0.25;
		prog->image_dirty = 1;
	}
	else if (keycode == 124)
	{
		prog->pan_x -= 0.25;
		prog->image_dirty = 1;
	}
	else if (keycode == 123)
	{
		prog->pan_x += 0.25;
		prog->image_dirty = 1;
	}
	return (0);
}

int	key_map(int keycode, t_program *prog)
{
	if (keycode == 53)
		cleanup_and_exit(prog, EXIT_SUCCESS);
	else if (keycode == 24 || keycode == 27)
		zoom(keycode, prog);
	else if (keycode == 125 || keycode == 126 || keycode == 124 \
			|| keycode == 123)
		panning(keycode, prog);
	else if (keycode == 18 || keycode == 49)
	{
		prog->image_dirty = 1;
		prog->colour = 0;
	}
	else if (keycode == 19 || keycode == 50)
	{
		prog->colour = 1;
		prog->image_dirty = 1;
	}
	else if (keycode == 20 || keycode == 51)
	{
		prog->colour = 2;
		prog->image_dirty = 1;
	}
	return (0);
}
