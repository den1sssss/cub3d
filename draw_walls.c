#include "cub3d.h"


void	wall_init(t_player *player, t_wall *wall)
{
	wall->player = player;
	wall->map = player->game->map;
	wall->block_size = player->game->block_size;
	wall->angle =  (int)player->angle % 360;
	wall->cast_angle = wall->angle  - player->view_angle / 2;
	wall->dist_real = player->data->win_w / tan(player->view_angle);
	wall->color = create_trgb(0, 15, 0, 0);
}

//t_player	*player;
//char		**map;
//double		angle;
//double		cast_angle;
//int			block_size;
//int			dist_real;
//int			dist_vertical;
//int			dist_horizontal;
//int			dist_wall;
//int			inter_x;
//int			inter_y;
//int			dx;
//int			dy;
//int			x_grid;
//int			y_grid;

void	find_wall(t_wall *wall)
{
	wall->x_grid = wall->inter_x / wall->block_size;
	wall->y_grid = wall->inter_y / wall->block_size;
	while (wall->map[wall->y_grid][wall->x_grid] != 1)
	{
		wall->inter_x += wall->dx;
		wall->inter_y += wall->dy;
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
	wall->inter_y = wall->player->y + (wall->player->x - wall->inter_x) * tan(wall->cast_angle); //?
//	A.y = Py + (Px-A.x)*tan(ALPHA);
	wall->dx = wall->block_size / tan(wall->cast_angle);
	find_wall(wall);
	return (ft_abs(wall->player->y - wall->inter_y) / sin(wall->cast_angle));
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
	wall->inter_x = wall->player->x + (wall->player->y - wall->inter_y) / tan(wall->cast_angle); //?
	wall->dx = wall->block_size / tan(wall->cast_angle);
	find_wall(wall);
	return (ft_abs(wall->player->y - wall->inter_y) / sin(wall->cast_angle));
	
//	A.x = Px + (Py-A.y)/tan(ALPHA);
}

void	draw_column(t_player *player, t_wall *wall, int x)
{
	int	y;

	wall->dist_horizontal = find_horizontal_dist(wall);
	wall->dist_vertical = find_vertical_dist(wall);
	wall->dist_proj = ft_min(wall->dist_vertical, wall->dist_horizontal);
	wall->wall_height = wall->wall_height * wall->dist_proj / wall->dist_real;
	
	y = -1;
	while (++y < wall->wall_height / 2)
	{
		my_mlx_pixel_put(player->data, x, player->y_horizon + y, wall->color);
		my_mlx_pixel_put(player->data, x, player->y_horizon - y, wall->color);
	}
	wall->cast_angle += player->delta_angle;
}


void	draw_walls(t_player *player, t_wall *wall)
{
	//мб добавит t_wall wall
	int		x;
	double	angle;
	
	wall_init(player, wall);
	x = -1;
	while (++x < player->data->win_w)
		draw_column(player, wall, x);
	
}


//сначала каст одного луча. Сначала по горизонтали, потом по вертикали, по горизонтали сначала вычисляем
