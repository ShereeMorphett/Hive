#include "fractol.h"
#define MAX_ITERATIONS 1000
# define	X_SCALE_MIN  -2.0
# define	X_SCALE_MAX  1.0
# define    Y_SCALE_MIN  -1.5
# define    Y_SCALE_MAX  1.5


int mandelbrot_placeholder(t_program *fract)
{
	int count;
	int offset;
	t_image	img;
	img.image = mlx_new_image(fract->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	img.address = mlx_get_data_addr(img.image, &img.bits_per_pixel, &img.line_length, &img.endian);

	//////////////////////////////////////////////////////////////////////////////////////////////

	double x;
	double y = 0;
	double x_square;
	double y_square;
	double x_scale = (X_SCALE_MAX - X_SCALE_MIN) / WINDOW_WIDTH;
	double y_scale = (Y_SCALE_MAX - Y_SCALE_MIN) / WINDOW_HEIGHT;
	int iteration = 0;



	while (y <= WINDOW_HEIGHT)
	{ 
		x = 0;
		while (x < WINDOW_WIDTH)
		{	
			iteration = 0;
			while (x_square + y_square <= 4 && iteration < MAX_ITERATIONS)
			{
				y = 2 * x * y_scale;
				x = x_square - y_square + x_scale;
				x_square = x * x;
				y_square = y * y;
				iteration++;
			}
			x++;
		}
		if (iteration == 100)
			place_pixel(&img, x, y, PINK);
		else
			place_pixel(&img, x, y, GREEN);
		y++;
		
	}

	mlx_put_image_to_window(fract->mlx, fract->win, img.image, 0, 0);	
	return (0);

}