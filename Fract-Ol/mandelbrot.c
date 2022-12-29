#include "fractol.h"
#define MAX_ITERATIONS 50;

int mandelbrot_placeholder(t_program *fract)
{
	int count;
	int offset;
	t_image	img;
	int x = WINDOW_WIDTH;
	int y = WINDOW_HEIGHT;

	img.image = mlx_new_image(fract->mlx, x, y);
	img.address = mlx_get_data_addr(img.image, &img.bits_per_pixel, &img.line_length, &img.endian);
	 offset = (y * img.line_length + x * (img.bits_per_pixel / 8));

	count = 600;
	while (count != 0)
	{
		place_pixel(&img, x - count, y - count, BLUE);
		count--;
	}
	mlx_put_image_to_window(fract->mlx, fract->win, img.image, 0, 0);
	
	return (0);
}