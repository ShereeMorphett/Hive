#include "fract'ol.h"
#include "mlx.h"
#include "colours.h"

int julia_placeholder(t_program *fract)
{
	int count;

	while (count++ < 100)
		mlx_pixel_put(fract->mlx, fract->win, ((WINDOW_WIDTH / 2) + count), WINDOW_HEIGHT / 2, PINK);
	
	count = 0;
	while (count++ < 100)
		mlx_pixel_put(fract->mlx, fract->win, ((WINDOW_WIDTH / 3) + count), WINDOW_HEIGHT / 3, BLUE);
	
	count = 0;
	while (count++ < 100)
		mlx_pixel_put(fract->mlx, fract->win, ((WINDOW_WIDTH / 4) +  count), WINDOW_HEIGHT / 4, CYAN);
	
	count = 0;
	while (count++ < 100)
		mlx_pixel_put(fract->mlx, fract->win, ((WINDOW_WIDTH / 5) + count), WINDOW_HEIGHT / 5, MAGENTA);
	
	return (0);
}