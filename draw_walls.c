#include "cub3d.h"


void	find_wall(t_wall *wall)
{
	wall->x_grid = wall->inter_x / wall->block_size;
	wall->y_grid = wall->inter_y / wall->block_size;
	while (wall->map[wall->y_grid][wall->x_grid] != 1)
	{
		wall->inter_x += dx;
		wall->inter_y += dy;
		wall->x_grid = wall->inter_x / wall->block_size;
		wall->y_grid = wall->inter_y / wall->block_size;
	}
}

int	find_vertical_dist(t_wall *wall)
{
	if (wall->angle <= M_PI * 1.5 && wall->angle >= M_PI / 2)
	{
		wall->inter_x = (wall->player->x / wall->block_size) *  wall->block_size + wall->block_size;
		wall->dx = wall->block_size;
	}
	else
	{
		wall->inter_x = (wall->player->x / wall->block_size) * wall->block_size - 1;
		wall->dx = -1 * wall->block_size;
	}
	wall->inter_y = wall->player->y + (wall->player->x - inter_x) * tan(wall->angle); //?
	A.y = Py + (Px-A.x)*tan(ALPHA);
	wall->dx = wall->block_size / tan(wall->angle);
	find_wall(wall);
	return (ft_abs(wall->player->y - wall->inter_y) / sin(wall->angle));
}

int	find_horizontal_dist(t_wall *wall)
{
	if (wall->angle <= M_PI)
	{
		wall->inter_y = (wall->player->y / wall->block_size) * wall->block_size - 1;
		wall->dy = -1 * wall->block_size;
	}
	else
	{
		wall->inter_y = (wall->player->y / wall->block_size) *  wall->block_size + wall->block_size;
		wall->dy = wall->block_size;
	}
	wall->inter_x = wall->player->x + (wall->player->y - inter_y) / tan(wall->angle); //?
	wall->dx = wall->block_size / tan(wall->angle);
	find_wall(wall);
	return (ft_abs(wall->player->y - wall->inter_y) / sin(wall->angle));
	
//	A.x = Px + (Py-A.y)/tan(ALPHA);
}

void	draw_column(t_player *player, t_wall *wall)
{
	wall->dist_horizontal = find_horizontal_dist(wall);
	wall->dist_vertical = find_vertical_dist(wall);
	wall->dist_wall = ft_min(wall->dist_vertical, wall->dist_horizontal);
	
	
}

void	wall_init(t_player *player, t_wall *wall)
{
	wall->player = player;
	wall->map = player->game->map;
	wall->block_size = player->block_size;
	wall->angle =  player->angle % 360;
	wall->cast_angle = wall->angle  - player->view_angle / 2;
}

void	draw_walls(t_player *player, t_wall *wall)
{
	//мб добавит t_wall wall
	int		i;
	double	angle;
	
	wall_init(wall, player);
	i = -1;
	while (++i < player->game->win_w)
		draw_column(player, wall);
	
}


//сначала каст одного луча. Сначала по горизонтали, потом по вертикали, по горизонтали сначала вычисляем
