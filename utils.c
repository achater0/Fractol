/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achater <achater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 02:16:43 by achater           #+#    #+#             */
/*   Updated: 2024/03/19 00:01:03 by achater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void map(t_fractol *fractol)
{
	fractol->x_max = 2.0;
	fractol->x_min = -2.0;
	fractol->y_max = -2.0;
	fractol->y_min = 2.0;
	fractol->shifting.x = 0;
	fractol->shifting.y = 0;
	fractol->shifting.zoom = 1;
	fractol->iteration = 0;
	fractol->color.r = 0;
	fractol->color.g = 255;
	fractol->color.b = 255;
}
int key_hook(int key_hook, t_fractol *fractol)
{
	if (key_hook == 53)
		exit(0);
	else if (key_hook == 123)
		fractol->shifting.x -= 0.2;
	else if (key_hook == 124)
		fractol->shifting.x += 0.2;
	else if (key_hook == 125)
		fractol->shifting.y += 0.2;
	else if (key_hook == 126)
		fractol->shifting.y -= 0.2;
	else if(key_hook == 69)
		fractol->iteration += 10;
	else if(key_hook == 78)
		fractol->iteration -= 10;
	else if(key_hook == 49)
		change_color(fractol);
	else
		return (0);
	fractal_draw(*fractol);
	return (0);
}

void	ft_scale(t_fractol *fractol, double x, double y)
{
	fractol->x_max = x + fractol->zoom * (fractol->x_max - x);
	fractol->x_min = x + fractol->zoom * (fractol->x_min - x);
	fractol->y_max = y + fractol->zoom * (fractol->y_max - y);
	fractol->y_min = y + fractol->zoom * (fractol->y_min - y);
}


int	mouse_hook(int button, int x, int y, t_fractol *fractol)
{
	double sy ;
	double sx ;

	sx= scale(fractol->x_max, fractol->x_min, x, 800);
	sy= scale(fractol->y_max, fractol->y_min, y, 800);
	if (button == 4)
	{
		fractol->zoom = 1.05;
		fractol->shifting.zoom *= 1.05;
		ft_scale(fractol, sx, sy);
	}
	else if (button == 5)
	{
		fractol->zoom = 0.95;
		fractol->shifting.zoom *= 0.95;
		ft_scale(fractol, sx, sy);
	}
	fractal_draw(*fractol);
	return (0);
}
int	close_window(int button, t_fractol *fractol)
{
	(void)button;
	(void)fractol;
	exit(0);
	return (0);
}

void	hook_init(t_fractol *fractol)
{
	mlx_hook(fractol->wind, 2, 0, key_hook, fractol);
	mlx_hook(fractol->wind, 4, 0, mouse_hook, fractol);
	mlx_hook(fractol->wind, 17, 0, close_window, fractol);
}