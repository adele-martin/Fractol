#include "fractol.h"

/*
int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

int get_color(int iter, int max_iter)
{
    int color;
    color = iter * 25;
	(void)max_iter;
	int r;
	int g;
	int b;
	r = get_r(color);
    g = get_g(color);
    b = get_b(color);

    // Increase brightness by scaling the RGB values
    //r = r + (255 - r) * 0.5;
    //g = g + (255 - g) * 0.5;
    b = b + (255 - b) * 0.5;

    return create_trgb(get_t(color), r, g, b);
	//return(create_trgb(get_t(color), get_r(color), get_g(color), get_b(color)));
}

	//int r = (int)(9 * (1 - t) * t * t * t * 255);
    //int g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
    //int b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
    //return create_trgb(0, r, g, b);
*/

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_red(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_green(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_blue(int trgb)
{
	return ((trgb & 0xFF));
}

int get_color(int iter)
{
	int color_intensity = iter * 25;
    int blue = color_intensity % 256; // Ensures red stays within the 0-255 range
    int white_blend = (color_intensity / 2) % 256; // Blend white with red
    int green = (color_intensity / 4) % 256; // Reduces green intensity
    int red = (color_intensity / 8) % 256; // Reduces blue intensity even more

    // Blend white with red component
    blue = (blue + white_blend) / 2;
	return create_trgb(0, red, green, blue);
	//return (create_trgb(0, get_red(color), get_green(color), get_blue(color)));
}