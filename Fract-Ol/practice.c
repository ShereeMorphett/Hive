#include <stdlib.h>
#include <mlx.h>

typedef struct  s_program
{
    void *mlx;
    void *win;
}               t_program;

int main()
{
	t_program	fract;

	fract.mlx = mlx_init();
	fract.win = mlx_new_window(fract.mlx, 2000, 1040, "Fract'ol");
	mlx_loop(fract.mlx);
	
	mlx_destroy_window(fract.mlx, fract.win);
	free(fract.mlx);


}