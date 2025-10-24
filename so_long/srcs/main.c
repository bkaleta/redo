/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:06:53 by bkaleta           #+#    #+#             */
/*   Updated: 2025/10/24 23:32:41 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1280, 720, "Hello world!");
	img.img = mlx_new_image(mlx, 1280, 720);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	int y = 100;
	int x = 300;
	while (y < 500)
	{
		x = 300;
		while (x < 1000)
		{
			my_mlx_pixel_put(&img, x, y, 0x00FF0000);
			x++;
		}
		y++;
	}

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
