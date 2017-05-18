/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 12:47:54 by carodrig          #+#    #+#             */
/*   Updated: 2016/10/06 19:53:46 by carodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	julia_hook1(t_t *t)
{
	char	*s2;

	mlx_destroy_image(t->mlx, t->image);
	mlx_clear_window(t->mlx, t->window);
	mlx_string_put(t->mlx, t->window, 620, 50, 0xffffff, t->fractale);
	mlx_string_put(t->mlx, t->window, 620, 80, 0xffffff, "iter :");
	s2 = ft_itoa(t->max);
	mlx_string_put(t->mlx, t->window, 740, 80, 0xffffff, s2);
	free(s2);
	t->image = mlx_new_image(t->mlx, 500, 500);
	t->data = mlx_get_data_addr(t->image, &t->bpp, &t->sl, &t->e);
}

int			julia_hook(int x, int y, void *t)
{
	if (((t_t *)t)->espace == 0 && ((t_t *)t)->fractal == 1)
	{
		if (x > 0 && x < 500 && y > 0 && y < 500)
		{
			julia_hook1((t_t *)t);
			((t_t *)t)->cre = (double)x / 25 - 10;
			((t_t *)t)->cim = (double)y / 25 - 10;
			julia(t);
			mlx_put_image_to_window(((t_t *)t)->mlx, \
					((t_t *)t)->window, ((t_t *)t)->image, 0, 0);
		}
	}
	else
	{
		julia_hook1((t_t *)t);
		(((t_t *)t)->fractal == 1) ? julia(t) : x;
		(((t_t *)t)->fractal == 2) ? mandelbrot(t) : x;
		(((t_t *)t)->fractal == 3) ? burning(t) : x;
		(((t_t *)t)->fractal == 4) ? tricorne(t) : x;
		mlx_put_image_to_window(((t_t *)t)->mlx, \
				((t_t *)t)->window, ((t_t *)t)->image, 0, 0);
	}
	return (0);
}

static void	key_echap2(int keycode, void *t)
{
	if (keycode == 36)
	{
		((t_t *)t)->fractal++;
		if (((t_t *)t)->fractal == 5)
			((t_t *)t)->fractal = 1;
		init((t_t *)t);
	}
}

static void	key_echap1(int keycode, void *t)
{
	if (keycode == 9)
	{
		if (((t_t *)t)->color == 1)
			((t_t *)t)->color = 0;
		else
			((t_t *)t)->color = 1;
	}
	else if (keycode == 8)
	{
		if (((t_t *)t)->r > 2000000)
			((t_t *)t)->r = 1000;
		else
			((t_t *)t)->r += 554;
		if (((t_t *)t)->v > 2000000)
			((t_t *)t)->v = 1000;
		else
			((t_t *)t)->v += 87285;
		if (((t_t *)t)->b > 2000000)
			((t_t *)t)->b = 1000;
		else
			((t_t *)t)->b += 2567;
	}
	else
		key_echap2(keycode, (t_t *)t);
}

int			key_echap(int keycode, void *t)
{
	if (keycode == 53)
		exit_hook((t_t *)t);
	else if (keycode == 49)
	{
		if (((t_t *)t)->espace == 1)
			((t_t *)t)->espace = 0;
		else
			((t_t *)t)->espace = 1;
	}
	else if (keycode == 13)
		((t_t *)t)->max += 2;
	else if (keycode == 1)
		((t_t *)t)->max -= 2;
	else if (keycode == 126)
		((t_t *)t)->movey -= 100 / ((t_t *)t)->zoom;
	else if (keycode == 125)
		((t_t *)t)->movey += 100 / ((t_t *)t)->zoom;
	else if (keycode == 123)
		((t_t *)t)->movex -= 100 / ((t_t *)t)->zoom;
	else if (keycode == 124)
		((t_t *)t)->movex += 100 / ((t_t *)t)->zoom;
	else
		key_echap1(keycode, (t_t *)t);
	julia_hook(1, 1, t);
	return (0);
}
