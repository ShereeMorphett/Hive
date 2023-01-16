#include "fractol.h"

int cleanup_and_exit(t_program *program, int result)
{
	cleanup(program);
	exit(result);
}

void	place_pixel(t_image *img, int x, int y, int color)
{
	char	*destination;

	destination = img->add + (y * img->line_length + x * (img->bpp/ 8));
	*(unsigned int*)destination = color;
}

double lerp(double start, double end, double blend) 
{
    return (start * (1.0 - blend)) + (end * blend);
}

int mouse_map(int keycode, int x, int y, t_program *prog)
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

int key_map(int keycode, t_program *prog)
{
	if (keycode == 65307 || keycode == 53)
		cleanup_and_exit(prog, EXIT_SUCCESS);
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
	else if (keycode == 61 || keycode == 24)
	{
		prog->zoom += 0.75;
		prog->image_dirty = 1;
	}
	else if	(keycode == 45 || keycode == 27)
	{
		prog->zoom = fmax(prog->zoom - 0.75, 0.01);
		prog->image_dirty = 1;
	}
		else if (keycode == 65364 || keycode == 125)
	{
		prog->pan_y -= 0.25;
		prog->image_dirty = 1;
	}
	else if(keycode == 65362 || keycode == 126)
	{
		prog->pan_y += 0.25;
		prog->image_dirty = 1;
	}
	else if (keycode == 65363 || keycode == 124)
	{
		prog->pan_x -= 0.25;
		prog->image_dirty = 1;
	}
	else if(keycode == 65361 || keycode == 123)
	{
		prog->pan_x += 0.25;
		prog->image_dirty = 1;
	}
	return (0);
}