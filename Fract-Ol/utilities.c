#include "fractol.h"


void	place_pixel(t_image *img, int x, int y, int color)
{
	char	*destination;

	destination = img->add + (y * img->line_length + x * (img->bpp/ 8));
	*(unsigned int*)destination = color;
}

int mouse_map(int keycode, int x, int y, t_program *prog)
{
	//fprintf(stdout, "key_map: %i, %i\n", x, y)
	if (keycode == 5)
	{	
		prog->zoom += 0.25;
		prog->image_dirty = 1;
	}
	else if (keycode == 4)
	{
		prog->zoom = fmax(prog->zoom - 0.25, 1.0);
		prog->image_dirty = 1;
	}
	return (0);
}


int key_map(int keycode, t_program *prog)
{
	//fprintf(stdout, "key_map: %i\n", keycode);
	if (keycode == 65307 || keycode == 53)
		cleanup_and_exit(prog, EXIT_SUCCESS);
	else if (keycode == 18)
	{
		ft_putstr_fd("1 colour set\n", 1);
		prog->image_dirty = 1;
		prog->colour = 0;
	}
	else if (keycode == 19)
	{
		ft_putstr_fd("2 colour set\n", 1);
		prog->colour = 1;
		prog->image_dirty = 1;
	}
	else if (keycode == 20)
	{
		ft_putstr_fd("3 colour set\n", 1);
		prog->colour = 2;
		prog->image_dirty = 1;
	}
	else if (keycode == 52)
	{
		ft_putstr_fd("4 colour set\n", 1);
		prog->image_dirty = 1;
		prog->colour = 3;
	}
	else if (keycode == 65362 ||keycode == 126)
	{
		prog->zoom += 0.75;
		prog->image_dirty = 1;
	}
	else if	(keycode == 65364 || keycode == 125)
	{
		prog->zoom = fmax(prog->zoom - 0.75, 1.0);
		prog->image_dirty = 1;
	}
	else if (keycode == 65363 || keycode == 124)
	{
		prog->pan_adjust -= 0.25;
		prog->image_dirty = 1;
	}
	else if(keycode == 65361 || keycode == 123)
	{
		prog->pan_adjust += 0.25;
		prog->image_dirty = 1;
	}
	return (0);
}