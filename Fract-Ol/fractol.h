#include "libft.h"
#include "colours.h"
#include "mlx.h"
#define DESTROY_NOTIFY		17
# define WINDOW_WIDTH 500
# define WINDOW_HEIGHT 200


typedef struct  struct_image
{
	void	*handle;
	char	*add;
	int		bpp;
	int		line_length;
	int		endian;
}               t_image;

typedef struct  struct_visualizer
{
  double	fractal_x;
  double	fractal_y;
  int pixel_x;
  int pixel_y;
  int iter;
  int r;
  int g;
  int b;
  int *weight;
  int *palette;

}               t_visualizer;


typedef struct  s_program
{
    void *mlx;
    void *win;
    double zoom;
    double pan_adjust;
    int colour;
    t_image image;
    int image_dirty;


}               t_program;

void cleanup_and_exit(t_program *program, int result);
void mandelbrot_visualizer(t_program *fract);
int key_map(int keycode, t_program *vars);
int mouse_map(int keycode, int x, int y, t_program *prog);
void	place_pixel(t_image *img, int x, int y, int color);


//////////////////////DELETE THESE////////////////////////////////////  
int julia_placeholder(t_program *fract);
