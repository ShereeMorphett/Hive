#include "libft.h"
#include "colours.h"
#include "mlx.h"
#include "key_maps.h"
# define WINDOW_WIDTH 1080
# define WINDOW_HEIGHT 900

typedef struct		struct_complex_num
{
	double		real;
	double		imaginary;
}					t_complex_num;

typedef struct  struct_image
{
	void	*image;
	char	*address;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}               t_image;


typedef struct		s_visual
{
	double		xmin;
	double		xmax;
	double		ymin;
	double		ymax;
	double		zoom;
	double		offx;
	double		offy;
	long		max;
	t_complex_num	mouse;
}					t_visual;

typedef struct  s_program
{
    void *mlx;
    void *win;
    t_image	image;

}               t_program;


 


void mandelbrot_plotting(t_program *fract);
int key_map(int keycode, t_program *vars);
int	prog_close(int keycode, t_program *vars);
static int	cross_close(int keycode, t_program *vars);
void	place_pixel(t_image *img, int x, int y, int color);
int key_map(int keycode, t_program *vars);


//////////////////////DELETE THESE////////////////////////////////////  
int julia_placeholder(t_program *fract);
int mandelbrot_placeholder(t_program *fract);

////////////colours////////////////
int	create_trgb(int t, int r, int g, int b);
int	get_transp(int trgb);
int	get_red(int trgb);
int	get_green(int trgb);
int	get_blue(int trgb);
