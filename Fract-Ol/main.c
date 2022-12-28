#include <stdlib.h>
#include "mlx.h"
#include "key_maps.h"
#include "fract'ol.h"
#include "colours.h"
#include <stdio.h>
#include "libft.h"

int key_map(int keycode, t_program *vars)
{
	if (keycode == 53)
		prog_close(keycode, vars);
	return (0);
}

static int	cross_close(int keycode, t_program *vars)
{
	exit(EXIT_SUCCESS);
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

void input_check_initialize(int argc, char *argv[], t_program *fract)
{
	int valid;

	valid = 0;
	if (fract->mlx == NULL)
	{
		ft_putstr_fd ("Error mlx did not initialize.\n", 1);
		exit (EXIT_FAILURE);
	}
	fract->win = mlx_new_window(fract->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Fract'ol");
	if (fract->win == NULL)
	{
		ft_putstr_fd ("Error window was not created.\n", 1);
		exit (EXIT_FAILURE);
	}
}


int main(int argc, char *argv[])
{
	t_program	fract;

	if (argc <= 1)	 
	{
		ft_putstr_fd("./fract'ol  [julia, mandelbrot]", 1);
		exit (EXIT_FAILURE);
	}
	fract.mlx = mlx_init();
	input_check_initialize(argc, argv, &fract);
	if (ft_strncmp(argv[1], "julia", 5) == 0)
		julia_placeholder(&fract);
	else if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
		mandelbrot_placeholder(&fract);
	else
	{
		ft_putstr_fd("./fract'ol  [julia, mandelbrot]", 1);
		exit (EXIT_FAILURE);
	}
	
	mlx_hook(fract.win, 2, 1L<<0, key_map, &fract);
	mlx_hook(fract.win, 17, 0, cross_close, &fract);
	
	
	mlx_loop(fract.mlx);
	free(fract.mlx);
	return (0);
}