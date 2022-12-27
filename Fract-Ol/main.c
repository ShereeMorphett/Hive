#include <stdlib.h>
#include "/usr/X11/include/mlx.h"
#include "fract'ol.h"

int	close(int keycode, t_program *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	free(vars->win);
	free(vars->mlx);
	return (0);
}

int main()
{
	t_program	fract;

	fract.mlx = mlx_init();
	fract.win = mlx_new_window(fract.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Fract'ol");
	mlx_hook(fract.win, 1, 1L<<0, close, &fract);
	mlx_loop(fract.mlx);
	return (0);
}