/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 11:35:51 by carodrig          #+#    #+#             */
/*   Updated: 2016/10/07 12:33:53 by carodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	frac(void)
{
	ft_putstr("parametres disponibles : Julia, ");
	ft_putstr("Mandelbrot, Burning_Ship, Tricorne.\n");
	return (0);
}

static void	frac2(t_t *t)
{
	char	*s2;

	mlx_string_put(t->mlx, t->window, 620, 50, 0xffffff, t->fractale);
	mlx_string_put(t->mlx, t->window, 620, 80, 0xffffff, "iter :");
	s2 = ft_itoa(t->max);
	mlx_string_put(((t_t *)t)->mlx, t->window, 740, 80, 0xffffff, s2);
	free(s2);
	if (t->fractal == 1)
		julia(t);
	else if (t->fractal == 2)
		mandelbrot(t);
	else if (t->fractal == 3)
		burning(t);
	else if (t->fractal == 4)
		tricorne(t);
	mlx_put_image_to_window(t->mlx, t->window, t->image, 0, 0);
	mlx_hook(t->window, 6, 1L << 6, julia_hook, t);
	mlx_hook(t->window, 17, 1L << 17, exit_hook, t);
	mlx_mouse_hook(t->window, mouse_echap, t);
	mlx_key_hook(t->window, key_echap, t);
	mlx_loop(t->mlx);
}

int			main(int argc, char **argv)
{
	t_t		*t;

	if (argc != 2)
		return (frac());
	t = (t_t *)malloc(sizeof(t_t));
	if (!t)
		return (0);
	if (ft_strequ(argv[1], "Julia"))
		t->fractal = 1;
	else if (ft_strequ(argv[1], "Mandelbrot"))
		t->fractal = 2;
	else if (ft_strequ(argv[1], "Burning_Ship"))
		t->fractal = 3;
	else if (ft_strequ(argv[1], "Tricorne"))
		t->fractal = 4;
	else
		return (frac());
	t->mlx = mlx_init();
	init(t);
	t->image = mlx_new_image(t->mlx, 500, 500);
	t->data = mlx_get_data_addr(t->image, &t->bpp, &t->sl, &t->e);
	t->window = mlx_new_window(t->mlx, 800, 500, "fractol");
	frac2(t);
	return (0);
}
