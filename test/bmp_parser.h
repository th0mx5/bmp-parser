/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <maxisimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 17:11:44 by thbernar          #+#    #+#             */
/*   Updated: 2018/11/16 15:05:19 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BMP_PARSER_H
# define BMP_PARSER_H

# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct	s_bmp
{
	int			width;
	int			height;
	int			data_offset;
	int			*data;
	t_coord		cursor;
	double		scale;
}				t_bmp;

void			load_bmp(t_bmp *img, char *filename);
t_color			get_pixel_color(t_bmp *img, int x, int y);

#endif
