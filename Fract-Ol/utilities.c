#include "fractol.h"


void	place_pixel(t_image *img, int x, int y, int color)
{
	char	*destination;

	destination = img->address + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)destination = color;
}

int	prog_close(int keycode, t_program *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		free(vars->mlx);
		exit (EXIT_SUCCESS);
	}
	return (0);
}

int key_map(int keycode, t_program *vars)
{
	if (keycode == 53)
		prog_close(keycode, vars);
	if (keycode == 5)
		ft_putstr_fd("mouse wheel up\n", 1);
	if	(keycode == 4)
	ft_putstr_fd("mouse wheel down\n", 1);
	return (0);
}