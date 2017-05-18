/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 12:06:02 by carodrig          #+#    #+#             */
/*   Updated: 2016/06/10 12:39:04 by carodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	tricorne1(t_t *t, int *i, int x, int y)
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
		t->newim = -1 * (2 * t->oldre * t->oldim + t->cim);
		if ((t->newre * t->newre + t->newim * t->newim) > 4)
			j = 0;
		*i = *i + 1;
	}
}

void		tricorne(t_t *t)
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
			tricorne1(t, &i, x, y);
			t->data[x * 4 + y * 500 * 4 + 1] = t->r % 256 * i % 256;
			t->data[x * 4 + y * 500 * 4] = t->v % 256 * i % 256;
			t->data[x * 4 + y * 500 * 4 + 2] = t->b % 256 * i % 256;
			x++;
		}
		x = 0;
		y++;
	}
}

static void	burning1(t_t *t, int *i, int x, int y)
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
		t->newim = 2 * fabs(t->oldre * t->oldim) + t->cim;
		if ((t->newre * t->newre + t->newim * t->newim) > 4)
			j = 0;
		*i = *i + 1;
	}
}

void		burning(t_t *t)
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
			burning1(t, &i, x, y);
			t->data[x * 4 + y * 500 * 4 + 1] = t->r % 256 * i % 256;
			t->data[x * 4 + y * 500 * 4] = t->v % 256 * i % 256;
			t->data[x * 4 + y * 500 * 4 + 2] = t->b % 256 * i % 256;
			x++;
		}
		x = 0;
		y++;
	}
}
