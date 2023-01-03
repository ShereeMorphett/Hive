
#define	PINK 	0xff80ed
#define	RED		0xFF0000
#define	GREEN	0x00FF00
#define	BLUE	0x0000FF
#define	YELLOW	0xFFFF00
#define	CYAN	0x00FFFF
#define	MAGENTA	0xFF00FF
#define BLACK 	0x000000
#define WHITE 	0xFFFFFF


// typedef struct  struct_gradient
// {
// 	int		quantity;
//     int     *colours[4];
//     double  *weights[4];
//     }               t_gradient;

unsigned create_trgb(unsigned t, unsigned r, unsigned g, unsigned b);
unsigned int	get_t(unsigned int trgb);
unsigned int	get_r(unsigned int trgb);
unsigned int	get_g(unsigned int trgb);
unsigned int	get_b(unsigned int trgb);


// lerp
