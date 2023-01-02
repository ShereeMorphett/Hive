#include "fractol.h"
#include "mlx.h"
#include "colours.h"

int julia_placeholder(t_program *fract)
{
	int count;
	t_image	img;

	int x = WINDOW_WIDTH;
	int y = WINDOW_HEIGHT;
	img.image = mlx_new_image(fract->mlx, x, y);
	img.add = mlx_get_data_addr(img.image, &img.bpp, &img.line_length, &img.endian);
	

	count = 600;

	place_pixel(&img, x - count, y - count, BLUE);

	while (count++ < 100)
		place_pixel(&img, ((WINDOW_WIDTH / 2) + count), WINDOW_HEIGHT / 2, RED);
	
	count = 0;
	while (count++ < 100)
		place_pixel(&img, ((WINDOW_WIDTH / 3) + count), WINDOW_HEIGHT / 3, BLUE);
	
	count = 0;
	while (count++ < 100)
		place_pixel(&img, ((WINDOW_WIDTH / 4) +  count), WINDOW_HEIGHT / 4, CYAN);
	
	count = 0;
	while (count++ < 100)
		place_pixel(&img, ((WINDOW_WIDTH / 5) + count), WINDOW_HEIGHT / 5, MAGENTA);
		
	mlx_put_image_to_window(fract->mlx, fract->win, img.image, 0, 0);
	return (0);
}