/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 13:55:50 by carodrig          #+#    #+#             */
/*   Updated: 2016/10/07 12:28:03 by carodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		init(void *t)
{
	((t_t *)t)->cre = 1000;
	((t_t *)t)->cim = 1000;
	((t_t *)t)->zoom = 100;
	((t_t *)t)->max = 30;
	((t_t *)t)->movex = 0;
	((t_t *)t)->movey = 0;
	((t_t *)t)->espace = 0;
	((t_t *)t)->color = 0;
	((t_t *)t)->r = 1000;
	((t_t *)t)->v = 1000;
	((t_t *)t)->b = 1000;
	if (((t_t *)t)->fractal == 1)
		((t_t *)t)->fractale = "Julia";
	else if (((t_t *)t)->fractal == 2)
		((t_t *)t)->fractale = "Mandelbrot";
	else if (((t_t *)t)->fractal == 3)
		((t_t *)t)->fractale = "Burning Ship";
	else if (((t_t *)t)->fractal == 4)
		((t_t *)t)->fractale = "Tricorne";
}

int			mouse_echap(int button, int x, int y, void *t)
{
	if (button == 4)
	{
		((t_t *)t)->zoom *= 1.1;
		((t_t *)t)->max += 2;
		((t_t *)t)->movex += (((double)x - 250) / (((t_t *)t)->zoom * 6.86666));
		((t_t *)t)->movey += (((double)y - 250) / (((t_t *)t)->zoom * 10.03));
		if (((t_t *)t)->color == 1)
		{
			((t_t *)t)->r += 554;
			((t_t *)t)->v += 87285;
			((t_t *)t)->b += 2567;
		}
	}
	else if (button == 5)
	{
		((t_t *)t)->max -= 2;
		((t_t *)t)->movex -= (((double)x - 250) / (((t_t *)t)->zoom * 6.86666));
		((t_t *)t)->movey -= (((double)y - 250) / (((t_t *)t)->zoom * 10.03));
		((t_t *)t)->zoom /= 1.1;
	}
	julia_hook(1, 1, t);
	return (0);
}

int			exit_hook(void *t)
{
	mlx_destroy_image(((t_t *)t)->mlx, ((t_t *)t)->image);
	mlx_destroy_window(((t_t *)t)->mlx, ((t_t *)t)->window);
	exit(EXIT_SUCCESS);
	return (0);
}
