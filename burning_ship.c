/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achater <achater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 00:38:13 by achater           #+#    #+#             */
/*   Updated: 2024/03/17 01:11:59 by achater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	the_absolut_value(t_complex z)
{
	t_complex c;

	c.a  =sqrt(z.a * z.a);
	c.b = sqrt(z.b * z.b);
	return (c);
}

void	burning_ship_or_mandelbort( t_complex *c,t_complex *z, t_fractol fractol)
{
	if(ft_strncmp(fractol.name, "burningship", 11) == 0)
		*z = complex_add(square_complex(the_absolut_value(*z)), *c);
	else
		*z = complex_add(square_complex(*z), *c);
}