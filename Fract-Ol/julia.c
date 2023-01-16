#include "fractol.h"


static void	julia_equation(t_visualizer *julia, t_program *prog)
{
	double x;
	double x_new;
	double y;

	julia->iter = 0;
	x = julia->fractal_x;
	y = julia->fractal_y;
	while ((x * x) + (y * y) <= 4.0 && julia->iter < MAX_ITER)
	{
		x_new = (x * x) - (y * y) + prog->c_x;
		y = 2.0 * x * y + prog->c_y;
		x = x_new;
		julia->iter++;
	}
}

void	julia_visualizer(t_program *prog)
{
	t_visualizer	julia;

	double fractal_w;
	double fractal_h;
	double start_x;
	double start_y;

	fractal_w = (X_MAX - X_MIN) / prog->zoom;
	fractal_h = (Y_MAX - Y_MIN) / prog->zoom;
	start_x = X_MIN + ((X_MAX - X_MIN) * 0.5) - (fractal_w * 0.5) + prog->pan_x;
 	start_y = Y_MIN + ((Y_MAX - Y_MIN) * 0.5) - (fractal_h * 0.5) + prog->pan_y;
	julia.pixel_y = 0;

	while (julia.pixel_y < WIN_HEIGHT)
	{
		double blend_y = (((double)julia.pixel_y)/ (WIN_HEIGHT - 1));
		julia.fractal_y = lerp(start_y, start_y + fractal_h, blend_y);
		julia.pixel_x = 0;
		while (julia.pixel_x < WIN_WIDTH)
		{
			double blend_x = ((double)julia.pixel_x / (WIN_WIDTH - 1));
			julia.fractal_x = lerp(start_x, start_x + fractal_w, blend_x) ;
			julia_equation(&julia, prog);
			place_pixel(&prog->image, julia.pixel_x, julia.pixel_y, fract_colour(&julia, prog));
			julia.pixel_x++;
		}	
		julia.pixel_y++;
	}
}