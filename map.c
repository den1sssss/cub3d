#include "cub3d.h"

void	draw_map(t_map *map)
{
	int	x;
	int	y;

	map->
	y = 0;
	while (y < win_h / 2)
	{
		x = 0;
		while (x < win_w)
			my_mlx_pixel_put(img, x++, y, color_ceil);
//		printf("%d %d\n", x, y);
		y++;
	}
	
}
