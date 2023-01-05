#include <stdlib.h>
#include "fractol.h"
#include <stdio.h>

static int	cross_close(int keycode, t_program *vars)
{
	exit(EXIT_SUCCESS);
}

void input_check_initialize(int argc, char *argv[], t_program *fract)
{
	if (fract->mlx == NULL)
	{
		ft_putstr_fd ("Error mlx did not initialize.\n", 1);
		exit (EXIT_FAILURE);
	}
	fract->win = mlx_new_window(fract->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Fract'ol");
	fract->zoom = 0;
	fract->pan_adjust = 0;
	fract->colour = 0;
	if (fract->win == NULL)
	{
		ft_putstr_fd ("Error window was not created.\n", 1);
		exit (EXIT_FAILURE);
	}
}

int	render_next_frame(t_program *fract)
{
	mlx_put_image_to_window(fract->mlx, fract->win, fract->image, 0, 0);
	//ft_putstr_fd("entered rendering\n", 1);
}

int main(int argc, char *argv[])
{
	t_program	fract;
	int *x;
	int *y;

	if (argc <= 1)	 
	{
		ft_putstr_fd("./fract'ol  [julia, mandelbrot]", 1);
		exit (EXIT_FAILURE);
	}
	fract.mlx = mlx_init();
	fract.win = mlx_new_window(fract.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Fract'ol");
	input_check_initialize(argc, argv, &fract);
	if (ft_strncmp(argv[1], "julia", 5) == 0)
		julia_placeholder(&fract);
	else if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
		mandelbrot_visualizer(&fract);
	else
	{
		ft_putstr_fd("./fract'ol  [julia, mandelbrot]\n", 1);
		exit (EXIT_FAILURE);
	}
	mlx_hook(fract.win, 2, KEY_PRESS, key_map, &fract);
	mlx_hook(fract.win, ON_MOUSEDOWN, 0, key_map, &fract);
	mlx_hook(fract.win, DESTROY_NOTIFY, 0, cross_close, &fract);
	
	mlx_loop_hook(fract.mlx, render_next_frame, &fract);	
	mlx_loop(fract.mlx);
	free(fract.mlx);
	return (0);
}