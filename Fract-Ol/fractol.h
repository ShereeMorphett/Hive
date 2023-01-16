#include "../libft/libft.h"
#include "colours.h"
#include "mlx.h"
#include "math.h"
#include "stdio.h"
#include "stdlib.h"
#define DESTROY_NOTIFY		17
#define MAX_ITER 1000
# define WIN_WIDTH 800
# define WIN_HEIGHT 480
# define	X_MIN  -2.0
# define	X_MAX  1.0
# define    Y_MIN  -1.5
# define    Y_MAX  1.5

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
  int quantity;
  double *weight;
  int *palette;

}               t_visualizer;

typedef struct  s_program
{
    void *mlx;
    void *win;
    int fract;
    double zoom;
    double c_x;
    double c_y;
    double pan_x;
    double pan_y;
    int colour;
    t_image image;
    int image_dirty;


}               t_program;

int cleanup_and_exit(t_program *program, int result);
void	cleanup(t_program *program);
void mandelbrot_visualizer(t_program *fract);
int key_map(int keycode, t_program *vars);
int mouse_map(int keycode, int x, int y, t_program *prog);
void	place_pixel(t_image *img, int x, int y, int color);
double lerp(double start, double end, double blend);
void	julia_visualizer(t_program *prog);
void set_palette(t_program *prog, t_visualizer *man);
int	fract_colour(t_visualizer *man, t_program *prog);