#include "fractol.h"
#include "stdio.h"

void	place_pixel(t_image *img, int x, int y, int color)
{
	char	*destination;

	destination = img->add + (y * img->line_length + x * (img->bpp/ 8));
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

int key_map(int keycode, t_program *fract)
{
	if (keycode == 53)
		prog_close(keycode, fract);
	if (keycode == 6)
		ft_putstr_fd("mouse motion\n", 1);
	if (keycode == 18)
	{
		ft_putstr_fd("1 colour set\n", 1);
		fract->colour = 0;
	}
	if (keycode == 19)
	{
		ft_putstr_fd("2 colour set\n", 1);
		fract->colour = 1;
	}
	if (keycode == 20)
	{
		ft_putstr_fd("3 colour set\n", 1);
		fract->colour = 2;
	}
	if (keycode == 21)
	{
		ft_putstr_fd("4 colour set\n", 1);
		fract->colour = 3;
	}
	if (keycode == 126)
	{
		fract->zoom += 1;
		ft_putstr_fd("Arrow key up\n", 1);
	}
	if	(keycode == 125)
	{
		fract->zoom -= 1;
		ft_putstr_fd("Arrow key down\n", 1);
	}
	if (keycode == 124)
	{
		fract->pan_adjust += 1;
		ft_putstr_fd("Arrow key right\n", 1);
	}
	if	(keycode == 123)
	{
		fract->pan_adjust -= 1;
		ft_putstr_fd("Arrow key left\n", 1);
	}
	if (keycode == 5)
	{	
		ft_putstr_fd("mouse wheel up\n", 1);
	}
	if	(keycode == 4)
	{
		ft_putstr_fd("mouse wheel down\n", 1);

	}
	return (0);
}