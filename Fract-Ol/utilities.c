#include "fractol.h"
#include "stdio.h"
#include "math.h"

void	place_pixel(t_image *img, int x, int y, int color)
{
	char	*destination;

	destination = img->add + (y * img->line_length + x * (img->bpp/ 8));
	*(unsigned int*)destination = color;
}

int mouse_map(int keycode, int x, int y, t_program *prog)
{
	//fprintf(stdout, "key_map: %i, %i\n", x, y);
	if (keycode == 6)
		ft_putstr_fd("mouse motion\n", 1);
	if (keycode == 5)
	{	
		ft_putstr_fd("mouse wheel up\n", 1);
		prog->image_dirty = 1;
	}
	if	(keycode == 4)
	{
		ft_putstr_fd("mouse wheel down\n", 1);
		prog->image_dirty = 1;
	}
}

int key_map(int keycode, t_program *prog)
{
	//fprintf(stdout, "key_map: %i\n", keycode);
	if (keycode == 65307)
		cleanup_and_exit(prog, EXIT_SUCCESS);
	if (keycode == 49)
	{
		ft_putstr_fd("1 colour set\n", 1);
		prog->colour = 0;
		prog->image_dirty = 1;
	}
	if (keycode == 50)
	{
		ft_putstr_fd("2 colour set\n", 1);
		prog->colour = 1;
		prog->image_dirty = 1;
	}
	if (keycode == 51)
	{
		ft_putstr_fd("3 colour set\n", 1);
		prog->colour = 2;
		prog->image_dirty = 1;
	}
	if (keycode == 52)
	{
		ft_putstr_fd("4 colour set\n", 1);
		prog->colour = 3;
		prog->image_dirty = 1;
	}
	if (keycode == 65362)
	{
		prog->zoom += 0.25;
		prog->image_dirty = 1;
		ft_putstr_fd("Arrow key up\n", 1);
	}
	if	(keycode == 65364)
	{
		prog->zoom = fmax(prog->zoom - 0.25, 1.0);
		prog->image_dirty = 1;
		ft_putstr_fd("Arrow key down\n", 1);
	}
	if (keycode == 65363)
	{
		prog->pan_adjust -= fmax(prog->pan_adjust - 0.25, 1.0);
		prog->image_dirty = 1;

		ft_putstr_fd("Arrow key right\n", 1);
	}
	if	(keycode == 65361)
	{
		prog->pan_adjust += 0.25;
		prog->image_dirty = 1;
		ft_putstr_fd("Arrow key left\n", 1);
	}
	return (0);
}