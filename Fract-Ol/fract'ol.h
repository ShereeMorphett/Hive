# define WINDOW_WIDTH 1200
# define WINDOW_HEIGHT 800

#define MLX_ERROR 1

typedef struct  s_program
{
    void *mlx;
    void *win;
}               t_program;
 
 
int key_map(int keycode, t_program *vars);
int	prog_close(int keycode, t_program *vars);


//////////////////////DELETE THESE////////////////////////////////////  

int julia_placeholder(t_program *fract);
int mandelbrot_placeholder(t_program *fract);