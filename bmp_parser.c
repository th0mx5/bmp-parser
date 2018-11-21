/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <maxisimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 15:11:51 by thbernar          #+#    #+#             */
/*   Updated: 2018/11/13 13:42:35 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmp_parser.h"

static void bmp_readfile(t_bmp *bmp, char *fname)
{
	int fd;
	int i;
	int j;
	int bytes_read = 1;
	unsigned char c;

	i = 0;
	j = 0;
	if (((fd = open(fname, O_RDONLY)) < 0))
	{
		ft_putstr("Fatal error : invalid file.");
		exit(-1);
	}
	while (bytes_read != 0)
	{
		bytes_read = read(fd, &c, 1);
		if (i >= 18 && i <= 21)
		{
			if (i == 18)
				bmp->width = c;
			if (i == 19)
				bmp->width += c << 8;
			if (i == 20)
				bmp->width += c << 16;
			if (i == 21)
				bmp->width += c << 24;
		}
		if (i >= 22 && i <= 25)
		{
			if (i == 22)
				bmp->height = c;
			if (i == 23)
				bmp->height += c << 8;
			if (i == 24)
				bmp->height += c << 16;
			if (i == 25)
				bmp->height += c << 24;
		}
		if (i == 54)
			bmp->data = (int*)malloc(sizeof(int) * bmp->width * bmp->height * 3);
		if (i >= 54)
		{
			if (i % 3 == 0)
				bmp->data[j + 2] = c;
			if (i % 3 == 1)
				bmp->data[j] = c;
			if (i % 3 == 2)
				bmp->data[j - 2] = c;
			j++;
		}
		i++;
	}
	bmp->fsize = i;
}

t_color		get_pixel_color(t_bmp *img, int x, int y)
{
	int		os;
	t_color	color;

	os = (x + y * img->width) * 3;
	color.r = img->data[0 + os];
	color.g = img->data[1 + os];
	color.b = img->data[2 + os];
	return (color);
}

int main(int ac, char **av)
{
	t_bmp bmp;
	t_color clr;

	(void)ac;
	//load_bmp(&bmp, av[1]);
	bmp_readfile(&bmp, av[1]);
	clr = get_pixel_color(&bmp, 0, 0);
	printf("(%d, %d)\n", bmp.width, bmp.height);
	printf("%d\n", clr.g);
	return (0);
}
