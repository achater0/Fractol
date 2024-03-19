/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achater <achater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 03:46:30 by achater           #+#    #+#             */
/*   Updated: 2024/03/18 22:39:11 by achater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void julia_mandelbrot(t_complex *c, t_complex *z, t_fractol fractol)
{
	if (ft_strncmp(fractol.name, "julia", 5) == 0 )
	{
		c->a = fractol.julia_x;
		c->b = fractol.julia_y;
	}
	else
	{
		c->a = z->a;
		c->b = z->b;
	}
}
void change_color(t_fractol *fractol)
{
	fractol->color.r = (fractol->color.b * 3 + 20) % 255;
	if (fractol->color.r == 0)
		fractol->color.r = 0;
	fractol->color.g = (fractol->color.r * 3 + 20) % 255;
	if (fractol->color.g == 0)
		fractol->color.g = 255;
	fractol->color.b = (fractol->color.g * 3 + 20) % 255;
	if (fractol->color.b == 0)
		fractol->color.b = 255;
}

unsigned int smooth_color(int i, t_fractol fractol)
{
	int r;
	int g;
	int b;

	b = (i * fractol.color.b / 25);
	g = (i * fractol.color.g / 25);
	r = (i *  fractol.color.r / 25);
	return (r << 16) | (g << 8) | b;
}

void	color_the_pixel(int x, int y, int i, t_fractol fractol)
{
	int	offset;

	offset = (x * fractol.img.bpp / 8) + (y * fractol.img.size_line);
	*(unsigned int *)(fractol.img.pixels_ptr + offset) = smooth_color(i, fractol);
}

void	handl_pixel(int x, int y, t_fractol fractol)
{
	t_complex c;
	t_complex z;
	int	i;
	int	offset;

	i = -1;
	z.a = scale(fractol.x_max,fractol.x_min , x, 800)  + fractol.shifting.x  * fractol.shifting.zoom;
	z.b = scale(fractol.y_max,fractol.y_min , y, 800)  + fractol.shifting.y * fractol.shifting.zoom;
	julia_mandelbrot(&c, &z, fractol);
	while (++i < (30 + fractol.iteration ))
	{
		burning_ship_or_mandelbort(&c, &z, fractol);
		if (z.a * z.a + z.b * z.b > 4)
		{
			color_the_pixel(x, y, i, fractol);
			return ;
		}
		else
		{
			offset = (x * fractol.img.bpp / 8) + (y * fractol.img.size_line);
			*(unsigned int *)(fractol.img.pixels_ptr + offset) = 0;
		}
	}
}
