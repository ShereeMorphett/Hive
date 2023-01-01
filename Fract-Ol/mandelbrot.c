#include "fractol.h"
#define MAX_ITERATIONS 100
# define	X_SCALE_MIN  -2.0
# define	X_SCALE_MAX  1.0
# define    Y_SCALE_MIN  -1.5
# define    Y_SCALE_MAX  1.5

int mandelbrot_placeholder(t_program *fract)
{
	t_image	img;
	img.image = mlx_new_image(fract->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	img.address = mlx_get_data_addr(img.image, &img.bits_per_pixel, &img.line_length, &img.endian);
	//////////////////////////////////////////////////////////////////////////////////////////////
	int pixel_x;
	int pixel_y = 0;
	int iteration = 0;
	while (pixel_y < WINDOW_HEIGHT)
	{ 
		double init_y = ((double)pixel_y / (WINDOW_HEIGHT - 1)); 
		init_y = Y_SCALE_MIN + init_y * (Y_SCALE_MAX - Y_SCALE_MIN);

		pixel_x = 0;
		while (pixel_x < WINDOW_WIDTH)
		{
			double init_x = ((double)pixel_x / (WINDOW_WIDTH - 1));
			init_x = X_SCALE_MIN + init_x * (X_SCALE_MAX - X_SCALE_MIN);
			double x = init_x;
			double y = init_y;

			iteration = 0;
			while ((x * x) + (y * y) < 4.0 && iteration < MAX_ITERATIONS)
			{
				y = 2.0 * x * y + init_y;
				x = (x * x) - (y * y) + init_x;
				iteration++;
			}
			if (iteration == 100)
				place_pixel(&img, pixel_x, pixel_y, PINK);
			else
				place_pixel(&img, pixel_x, pixel_y, GREEN);
		
			pixel_x++;
		}
		pixel_y++;
	}
	mlx_put_image_to_window(fract->mlx, fract->win, img.image, 0, 0);	
	return (0);
}