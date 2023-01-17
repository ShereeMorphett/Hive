/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:58:06 by smorphet          #+#    #+#             */
/*   Updated: 2023/01/17 13:43:06 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/libft.h"
# include "mlx.h"
# include "math.h"
# define DESTROY_NOTIFY  17
# define MAX_ITER        250
# define WIN_WIDTH       800
# define WIN_HEIGHT      480
# define X_MIN           -2.0
# define X_MAX           1.0
# define Y_MIN           -1.5
# define Y_MAX           1.5

typedef struct struct_image
{
	void	*handle;
	char	*add;
	int		bpp;
	int		line_length;
	int		endian;
}	t_image;

typedef struct struct_visualizer
{
	double	fractal_x;
	double	fractal_y;
	int		pixel_x;
	int		pixel_y;
	double	fract_w;
	double	fract_h;
	int		iter;
	int		r;
	int		g;
	int		b;
	int		quantity;
	double	start_x;
	double	start_y;
	int		*palette;
}	t_visualizer;

typedef struct s_program
{
	void	*mlx;
	void	*win;
	int		fract;
	double	zoom;
	double	c_x;
	double	c_y;
	double	pan_x;
	double	pan_y;
	int		colour;
	double	*weight;
	t_image	image;
	int		image_dirty;
}	t_program;

int				cleanup_and_exit(t_program *program, int result);
void			cleanup(t_program *program);
void			mandelbrot_visualizer(t_program *fract);
int				key_map(int keycode, t_program *vars);
int				mouse_map(int keycode, int x, int y, t_program *prog);
void			place_pixel(t_image *img, int x, int y, int color);
double			lerp(double start, double end, double blend);
void			julia_visualizer(t_program *prog);
void			set_palette(t_program *prog, t_visualizer *man);
int				fract_colour(t_visualizer *man, t_program *prog);
unsigned int	create_trgb(unsigned t, unsigned r, unsigned g, unsigned b);
unsigned int	get_t(unsigned int trgb);
unsigned int	get_r(unsigned int trgb);
unsigned int	get_g(unsigned int trgb);
unsigned int	get_b(unsigned int trgb);
void			fract_initialize(t_program *prog, t_visualizer *fract);
#endif
