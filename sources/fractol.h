/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 11:33:27 by carodrig          #+#    #+#             */
/*   Updated: 2016/10/07 12:34:35 by carodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdlib.h>
# include <libft.h>
# include <math.h>

typedef struct		s_s
{
	int				bpp;
	int				sl;
	int				e;
	double			cre;
	double			cim;
	double			newre;
	double			newim;
	double			oldre;
	double			oldim;
	double			zoom;
	int				espace;
	int				max;
	double			movex;
	double			movey;
	int				fractal;
	int				color;
	int				r;
	int				v;
	int				b;
	char			*fractale;
	char			*data;
	void			*mlx;
	void			*window;
	void			*image;
}					t_t;

void				tricorne(t_t *t);
void				burning(t_t *t);
void				mandelbrot(t_t *t);
void				julia(t_t *t);
int					julia_hook(int x, int y, void *t);
void				init(void *t);
int					mouse_echap(int button, int x, int y, void *t);
int					exit_hook(void *t);
int					key_echap(int keycode, void *t);

#endif
