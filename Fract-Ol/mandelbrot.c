#include "mlx.h"
#include "key_maps.h"
#include "fract'ol.h"
#include "colours.h"
#include <math.h>

int mandelbrot_plotting(t_program *fract)
{
	// z = f(z) = pow(z, 2) + c;
	int point;
	int complex;

	mlx_pixel_put(fract->mlx, fract->win, WINDOW_WIDTH / 4, WINDOW_HEIGHT / 4, RED);


	
}


int mandelbrot_placeholder(t_program *fract)
{
	int count;
	
	count = 0;

	while (count++ < 100)
		mlx_pixel_put(fract->mlx, fract->win, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 + count, YELLOW);
	
	count = 0;
	while (count++ < 100)
		mlx_pixel_put(fract->mlx, fract->win, WINDOW_WIDTH / 3, WINDOW_HEIGHT / 3 + count, GREEN);
	
	count = 0;
	while (count++ < 100)
		mlx_pixel_put(fract->mlx, fract->win, WINDOW_WIDTH / 4, WINDOW_HEIGHT / 4 + count, RED);
	
	count = 0;
	while (count++ < 100)
		mlx_pixel_put(fract->mlx, fract->win, WINDOW_WIDTH / 5, WINDOW_HEIGHT / 5 + count, BLUE);
	
	return (0);
}