/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achater <achater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:09:13 by achater           #+#    #+#             */
/*   Updated: 2024/03/18 22:28:23 by achater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	fractal_init(t_fractol *fractal)
{
	fractal->connection = mlx_init();
	fractal->wind = mlx_new_window(fractal->connection, 800, 800, fractal->name);
	fractal->img.img_ptr = mlx_new_image(fractal->connection, 800, 800);
	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr,
		&fractal->img.bpp, &fractal->img.size_line, &fractal->img.endian);
	map(fractal);
}

void fractal_draw(t_fractol fractol)
{
	int x;
	int y;


	y = -1;
	while (++y < 800)
	{
		x = -1;
		while (++x < 800)
			handl_pixel(x, y, fractol);
	}
	mlx_put_image_to_window(fractol.connection, fractol.wind, fractol.img.img_ptr, 0, 0);
}

int main(int ac, char **av)
{
	t_fractol fractal;

	if ((ac == 2 && (ft_strncmp(av[1], "mandelbrot", 11) == 0))
		|| (ac == 4 && (ft_strncmp(av[1], "julia", 6) == 0 ))
		|| (ac == 2 && (ft_strncmp(av[1], "burningship", 12) == 0)))
	{
		fractal.name = av[1];
		if(ft_strncmp(av[1], "julia", 5) == 0 && ac == 4)
		{
			if (check_arg(av[2]) != 0 || check_arg(av[3]) != 0 )
				error();
			fractal.julia_x = string_to_double(av[2], 0.0, 0.0, 0) ;
			fractal.julia_y = string_to_double(av[3], 0.0, 0.0, 0) ;
		}
		fractal_init(&fractal);
		hook_init(&fractal);
		fractal_draw(fractal);
		mlx_loop(fractal.connection);
	}
	else
	{
		write(1, "Usage: ./fractol [mandelbrot/julia/burningship]\n", 48);
		exit(0);
	}
}
