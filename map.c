#include "cub3d.h"

void draw_miniblock(int x, int y, int color, t_minimap *minimap)
{
	int	x0;
	int	y0;

	x *= minimap->pix_per_block;
	y *= minimap->pix_per_block;
	y0 = -1;
//	printf("x = %d\ty = %d\tcolor = %d\n", x, y, color);
	while (++y0 < minimap->pix_per_block)
	{
		x0 = -1;
		while (++x0 < minimap->pix_per_block)
			my_mlx_pixel_put(minimap->data, x + x0, y + y0, color);
	}
}

//	my_mlx_pixel_put(img, x++, y, color_ceil);

int choose_miniblock_color(t_minimap *minimap, char c) //returns -1 for absence
{
	if (c == '0')
		return (minimap->color_space);
	if (c == '1')
		return (minimap->color_wall);
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E') //убрать вообще, просто на позиции по x y в конце рисовки карты наложить сверху позицию игрока
		return (minimap->color_player);
	return (-1);
}

void	draw_minimap(t_minimap *minimap) //только надо будет менять позицию игрока=>через ссылку в player передавать номер ячейки
{
	t_game	*game;
	int		color;
	int		x;
	int		y;

	game = minimap->game;
	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			color = choose_miniblock_color(minimap, game->map[y][x]);
			if (color != -1) //not absence
				draw_miniblock(x, y, color, minimap);
			
		}
	}
	draw_miniblock(minimap->player->x / game->block_size, minimap->player->y / game->block_size, minimap->color_player, minimap);
}
