 #include "fractol.h"
 
 void set_palette(t_program *prog, t_visualizer *man)
{
	int colours[4];
	colours[0] = BLACK;
	colours[3] = BLACK;
	if (prog->colour == 1)
	{
		colours[1] = 0x0000FF; // blue
		colours[2] = 0X9C4F96; // berry
	}
	else if (prog->colour == 2)
	{
		colours[1] = 0xFF00FF;
		colours[2] = 0xFFFFFF;
	}
	else
	{
		colours[1] = 0xFF0000;
		colours[2] = 0x00FF00;
	}
	double weights[4] = {0.0, 0.1, 0.2, 1.0};
	man->palette = colours;
	man->weight = weights;
	man->quantity = sizeof(colours) / sizeof(colours[0]);
}

int	fract_colour(t_visualizer *man, t_program *prog)
{
	double blend;
	int index;
	
	index = 0;
	set_palette(prog, man);
	if (man->iter >= MAX_ITER)
		return man->palette[man->quantity - 1]; 
	// [1, MAX_ITER] => [0.0, 1.0]
	blend = (double)(man->iter - 1) / (MAX_ITER - 1);
	while (index < man->quantity)
 	{
		if (man->weight[index] <= blend)
			break;
		index++;
	}
	if (index >= (man->quantity - 1))
		return man->palette[man->quantity-1];
	blend = (blend - man->weight[index])/(man->weight[index+1] - man->weight[index]);
	man->r = lerp(get_r(man->palette[index]), get_r(man->palette[index + 1]), blend);
	man->g = lerp(get_g(man->palette[index]), get_g(man->palette[index + 1]), blend);
	man->b = lerp(get_b(man->palette[index]), get_b(man->palette[index + 1]), blend);
	return ((int)create_trgb(0, man->r, man->g, man->b));
}