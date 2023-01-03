#include "colours.h"

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