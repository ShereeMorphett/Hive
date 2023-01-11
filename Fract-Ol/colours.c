#include "colours.h"

t_palette	*get_palettes(void)
{
	static t_palette	array[5];

	array[0] =
		(t_palette){5, 0, {0x7F1637, 0x047878, 0xFFB733, 0xF57336, 0xC22121}};
	array[1] =
		(t_palette){5, 0, {0x0D1C33, 0x17373C, 0x2B6832, 0x4F9300, 0xA1D700}};
	array[2] =
		(t_palette){5, 0, {0x002F2F, 0x046380, 0xEFECCA, 0xA7A37E, 0xE6E2AF}};
	array[3] =
		(t_palette){7, 10, {0xFF0000, 0xFFFF00, 0x00FF00, 0x00FFFF,
			0x0000FF, 0xFF00FF, 0xFF0000}};
	array[4] = (t_palette){0, 0, {0}};
	return (array);
}

unsigned create_trgb(unsigned t, unsigned r, unsigned g, unsigned b)
{
	return ((t & 0xFF) << 24 | (r & 0xFF) << 16 | (g & 0xFF) << 8 | (b & 0xFF));
}

unsigned int	get_t(unsigned int trgb)
{
	return ((trgb >> 24) & 0xFFu);
}

unsigned int	get_r(unsigned int trgb)
{
	return ((trgb >> 16) & 0xFFu);
}

unsigned int	get_g(unsigned int trgb)
{
	return ((trgb >> 8) & 0xFFu);
}

unsigned int	get_b(unsigned int trgb)
{
	return (trgb & 0xFFu);
}

double lerp(double start, double end, double blend) 
{
    return (start * (1.0 - blend)) + (end * blend);
}
