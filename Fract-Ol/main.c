#include <stdlib.h>
#include "fractol.h"

static void cleanup(t_program* program)
{
	if (!program)
		return;
	if (program->mlx)
	{
		if (program->image.handle)
		{
			mlx_destroy_image(program->mlx, program->image.handle);
			program->image.handle = NULL;
		}
		if (program->win)
		{
			mlx_destroy_window(program->mlx, program->win);
			program->win = NULL;
		}
		free(program->mlx);
		program->mlx = NULL;
	}
}

int cleanup_and_exit(t_program *program, int result)
{
	cleanup(program);
	exit(result);
}

static void initialize(t_program *prog)
{
	ft_memset(prog, 0, sizeof(t_program));
	prog->mlx = mlx_init();
	if (prog->mlx == NULL)
	{
		ft_putstr_fd ("Error mlx did not initialize.\n", 1);
		cleanup_and_exit(prog, EXIT_FAILURE);
	}
	prog->win = mlx_new_window(prog->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Fract'ol");
	if (prog->win == NULL)
	{
		ft_putstr_fd ("Error window was not created.\n", 1);
		cleanup_and_exit(prog, EXIT_FAILURE);
	}

	prog->image.handle = mlx_new_image(prog->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	prog->image.add = mlx_get_data_addr(prog->image.handle, &prog->image.bpp, \
		 &prog->image.line_length, &prog->image.endian);
	prog->image_dirty = 1;
	prog->colour = 0;
	prog->pan_x = 0;
	prog->pan_y = 0;
	prog->zoom = 1.0;
}

static int	render_next_frame(t_program *prog)
{
	if (prog->image_dirty)
	{
		mandelbrot_visualizer(prog);
		prog->image_dirty = 0;
	}
	mlx_put_image_to_window(prog->mlx, prog->win, prog->image.handle, 0, 0);
	
	return (0);
}

void main(int argc, char *argv[])
{
	t_program	prog;

	if (argc <= 1)	 
	{
		ft_putstr_fd("./fract'ol  [julia, mandelbrot]", 1);
		return EXIT_FAILURE;
	}
	/*
	if (ft_strncmp(argv[1], "julia", 5) == 0)
	{
		julia_visualizer(t_program *prog, argv[]);
		cleanup_and_exit(&prog, 69);
	}
	else if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
		mandelbrot_visualizer(&prog);
	else
	{
		ft_putstr_fd("./fract'ol  [julia, mandelbrot]\n", 1);
		cleanup_and_exit(&prog, EXIT_FAILURE);
	}
	*/
	initialize(&prog);
	mlx_key_hook(prog.win, key_map, &prog);
	mlx_mouse_hook(prog.win, mouse_map, &prog);
	mlx_hook(prog.win, DESTROY_NOTIFY, 0, cleanup_and_exit, &prog);
	mlx_loop_hook(prog.mlx, render_next_frame, &prog);	
	mlx_loop(prog.mlx);
	cleanup(&prog);
	
	exit (EXIT_SUCCESS);
}