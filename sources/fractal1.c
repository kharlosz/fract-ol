/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 12:38:40 by carodrig          #+#    #+#             */
/*   Updated: 2016/10/06 19:54:23 by carodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	mandelbrot1(t_t *t, int *i, int x, int y)
{
	int		j;

	t->cre = 1.5 * (x - 250) / t->zoom + t->movex;
	t->cim = (y - 250) / t->zoom + t->movey;
	t->newre = 0;
	t->newim = 0;
	t->oldre = 0;
	t->oldim = 0;
	j = 1;
	while (*i < t->max && j)
	{
		t->oldre = t->newre;
		t->oldim = t->newim;
		t->newre = t->oldre * t->oldre - t->oldim * t->oldim + t->cre;
		t->newim = 2 * t->oldre * t->oldim + t->cim;
		if ((t->newre * t->newre + t->newim * t->newim) > 4)
			j = 0;
		*i = *i + 1;
	}
}

void		mandelbrot(t_t *t)
{
	int		i;
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < 500)
	{
		while (x < 500)
		{
			i = 0;
			mandelbrot1(t, &i, x, y);
			t->data[x * 4 + y * 500 * 4 + 1] = t->r % 256 * i % 256;
			t->data[x * 4 + y * 500 * 4] = t->v % 256 * i % 256;
			t->data[x * 4 + y * 500 * 4 + 2] = t->b % 256 * i % 256;
			x++;
		}
		x = 0;
		y++;
	}
}

static void	julia1(t_t *t, int *i)
{
	t->oldre = t->newre;
	t->oldim = t->newim;
	t->newre = t->oldre * t->oldre - t->oldim * t->oldim + t->cre;
	t->newim = 2 * t->oldre * t->oldim + t->cim;
	*i = *i + 1;
}

void		julia(t_t *t)
{
	int		i;
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < 500)
	{
		while (x < 500)
		{
			t->newre = 1.5 * (x - 250) / t->zoom + t->movex;
			t->newim = (y - 250) / t->zoom + t->movey;
			i = 0;
			while (i < t->max && t->newre * t->newre + t->newim * t->newim <= 4)
				julia1(t, &i);
			t->data[x * 4 + y * 500 * 4 + 1] = t->r % 256 * i % 256;
			t->data[x * 4 + y * 500 * 4] = t->v % 256 * i % 256;
			t->data[x * 4 + y * 500 * 4 + 2] = t->b % 256 * i % 256;
			x++;
		}
		x = 0;
		y++;
	}
}
