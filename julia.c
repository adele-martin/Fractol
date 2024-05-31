#include "fractol.hs"

void julia(t_complex *comp, t_fractal *fractal)
{
	t_complex z;
	t_complex c;
	double temp;

	z.x = comp->x;
	z.y = comp->y;
	c.x = fractal->param_x; // c is the point in plane which corresponds to pixel
	c.y = fractal->param_y;
	fractal->iter = 0;
	while (++fractal->iter < fractal->max_iter)
	{
		temp = (z.x * z.x) - (z.y * z.y) + c.x;
		z.y = 2 * z.x * z.y + c.y;
		z.x = temp;
		if ((z.x * z.x) + (z.y * z.y) >= 4)
			break ; //this means the point escapes to infinity and is outside the set
	}
}