#include "cub3d.h"


void	draw_background(t_data *img, int color_ceil, int color_floor, int win_w, int win_h)
{
	int	x;
	int	y;

	y = 0;
	while (y < win_h / 2)
	{
		x = 0;
		while (x < win_w)
			my_mlx_pixel_put(img, x++, y, color_ceil);
		printf("%d %d\n", x, y);
		y++;
	}
	
	while (y < win_h)
	{
		x = 0;
		while (x < win_w)
			my_mlx_pixel_put(img, x++, y, color_floor);
		printf("%d %d\n", x, y);
		y++;
	}
//	my_mlx_pixel_put(img, x+ 100, y + 100, color);
}
