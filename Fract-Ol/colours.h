#ifndef FRACTOL_H
# define FRACTOL_H

#define	PINK 	0xff80ed
#define	RED		0xFF0000
#define	GREEN	0x00FF00
#define	BLUE	0x0000FF
#define	YELLOW	0xFFFF00
#define	CYAN	0x00FFFF
#define	MAGENTA	0xFF00FF
#define BLACK 	0x000000
#define WHITE 	0xFFFFFF
#define BERRY 	0X9C4F96
#define SUN_ORANGE 0xFF6355
#define YEL_ORANGE 0xFBA949
#define YEL_PALE 0xFAE442
#define KIWI 0x8BD448
#define BUT_BLUE 0x2AA8F2


double lerp(double start, double end, double blend);
unsigned create_trgb(unsigned t, unsigned r, unsigned g, unsigned b);
unsigned int	get_t(unsigned int trgb);
unsigned int	get_r(unsigned int trgb);
unsigned int	get_g(unsigned int trgb);
unsigned int	get_b(unsigned int trgb);

#endif