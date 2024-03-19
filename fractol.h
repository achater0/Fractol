/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achater <achater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:11:49 by achater           #+#    #+#             */
/*   Updated: 2024/03/17 01:47:55 by achater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

typedef struct s_complex
{
	double	a;
	double	b;
}	t_complex;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int 	bpp;
	int     endian;
	int    size_line;
}	t_img;

typedef struct s_shifting
{
	double	x;
	double	y;
	double	zoom;
}	t_shifting;

typedef struct s_fractol
{
	char	*name;
	void	*connection;
	void	*wind;
	t_img	img;
	t_shifting	shifting;
	double	zoom;
	int iteration;
	double x_max;
	double x_min;
	double y_max;
	double y_min;
	t_color color;
	double julia_x;
	double julia_y;

}t_fractol;


int	ft_strncmp(const char *s1, const char *s2, size_t n);
double scale(double max, double min, double unscaled, double size);
t_complex complex_add(t_complex x, t_complex y);
t_complex	square_complex(t_complex x);
void	fractal_init(t_fractol *fractal);
void fractal_draw(t_fractol fractol);
void	handl_pixel(int x, int y, t_fractol fractol);
void	color_the_pixel(int x, int y, int i, t_fractol fractol);
unsigned int smooth_color(int i, t_fractol fractol);
int key_hook(int key_hook, t_fractol *fractol);
void	hook_init(t_fractol *fractol);
int	mouse_hook(int button, int x, int y, t_fractol *fractol);
void	map(t_fractol *fractol);
void	ft_scale(t_fractol *fractol, double x, double y);
void change_color(t_fractol *fractol);
void	julia_mandelbrot(t_complex *c, t_complex *z, t_fractol fractol);
double	string_to_double(char *str, double res, double dec, int i);
int	check_arg(char *str);
void error();
t_complex	the_absolut_value(t_complex z);
void	burning_ship_or_mandelbort(t_complex *z,t_complex*c, t_fractol fractol);






#endif