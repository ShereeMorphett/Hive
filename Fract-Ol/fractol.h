#include "libft.h"
#include "colours.h"
#include "mlx.h"
#include "key_maps.h"
# define WINDOW_WIDTH 500
# define WINDOW_HEIGHT 200
# define	X_MIN  -2.0
# define	X_MAX  1.0
# define    Y_MIN  -1.5
# define    Y_MAX  1.5

typedef struct  struct_image
{
	void	*image;
	char	*add;
	int		bpp;
	int		line_length;
	int		endian;
}               t_image;

typedef struct  struct_visualizer
{
  double	init_y;
  double	init_x;
  double x;
  double y;
  int iter;
  int pixel_x;
  int pixel_y;
  double x_new;
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
    void  *image;
    int zoom;
    double pan_adjust;
    int colour;


}               t_program;


int	render_next_frame(t_program *fract);
void mandelbrot_visualizer(t_program *fract);
int key_map(int keycode, t_program *vars);
int	prog_close(int keycode, t_program *vars);
static int	cross_close(int keycode, t_program *vars);
void	place_pixel(t_image *img, int x, int y, int color);
int key_map(int keycode, t_program *vars);


//////////////////////DELETE THESE////////////////////////////////////  
int julia_placeholder(t_program *fract);
