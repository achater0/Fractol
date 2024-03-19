/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achater <achater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 06:24:14 by achater           #+#    #+#             */
/*   Updated: 2024/03/17 01:47:37 by achater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double scale(double max, double min, double unscaled, double size)
{
	return ((max - min) *(unscaled) / (size) + min);
}

t_complex complex_add(t_complex x, t_complex y)
{
	t_complex c;

	c.a = x.a + y.a;
	c.b = x.b + y.b;
	return (c);
}
t_complex	square_complex(t_complex x)
{
	t_complex c;

	c.a = x.a * x.a - x.b * x.b;
	c.b = 2 * x.a * x.b;
	return (c);
}

double	string_to_double(char *str, double res, double dec, int i)
{
	int j;
	int signe;

	signe = 1;
	if (str[i] == '-')
	{
		signe = -1;
		i++;
	}
	while (str[i] != '.' && str[i] != 0)
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] == 0)
		return (signe * res);
	i++;
	j = 1;
	while (str[i] != 0)
	{
		dec = dec + (str[i] - '0') / pow(10, j);
		i++;
		j++;
	}
	return(signe * (res + dec));
}

int	check_arg(char *str)
{
	int i;
	int x;

	x = 0;
	i = 0;

	if((str[i] == '-' || str[i] == '+' ) && str[i + 1] == 0)
		return (1);
	if(str[i] == '-' || str[i] == '+')
		i++;
	if(str[i] == '.')
		return(1);
	while (str[i])
	{
		if ( str[i] == '.' && str[i + 1] == 0)
			return (1);
		if (str[i] == '.')
			x++;
		else if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	if (x > 1)
		return (1);
	return (0);
}
