#include "cub3d.h"


void	wall_init(t_player *player, t_wall *wall)
{
	wall->player = player;
	wall->map = player->game->map;
	wall->block_size = player->game->block_size;
	wall->angle =  player->angle; //200 * M_PI + angle
	wall->cast_angle = wall->angle  - player->view_angle / 2;
	wall->dist_real = player->data->win_w / fabs(tan(player->view_angle));
	wall->wall_height = wall->block_size;
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
	while (wall->map[wall->y_grid][wall->x_grid] != '1')
	{
		wall->inter_x += wall->dx;
		wall->inter_y += wall->dy;
		wall->x_grid = wall->inter_x / wall->block_size;
		wall->y_grid = wall->inter_y / wall->block_size;
//		wall->map[wall->y_grid][wall->x_grid] = 1;
	}
}

double	choose_tan_coef(t_wall *wall, int edge_case)
{
	if (edge_case == HORIZON)
	{
		if (wall->cast_angle >= M_PI / 2 && wall->cast_angle <= 1.5 * M_PI) // луч идет влево (вверх или вниз неважно) то вычитыаем из x
			return (-fabs(tan(wall->cast_angle)));
		else
			return (fabs(tan(wall->cast_angle)));
	}
	else
	{
		if (wall->cast_angle >= 0 && wall->cast_angle <= M_PI) // луч идет вверх (лево или право неважно) то вычитыаем из y
			return (-fabs(tan(wall->cast_angle)));
		else
			return (fabs(tan(wall->cast_angle)));
	}

}

int	find_vertical_dist(t_wall *wall)
{
	if (wall->cast_angle >=  0.7 *  M_PI / 2 &&  wall->cast_angle <= 1.3 *  M_PI / 2)
		return (wall->player->y);
	wall->tan = choose_tan_coef(wall, VERTICAL);
	if (wall->cast_angle >= M_PI * 1.5 || wall->angle <= M_PI / 2)
	{
		wall->inter_x = (wall->player->x / wall->block_size) *  wall->block_size + wall->block_size;
		wall->dx = wall->block_size;
	}
	else
	{
		wall->inter_x = (wall->player->x / wall->block_size) * wall->block_size - 1;
		wall->dx = -1 * wall->block_size;
	}
	wall->inter_y = wall->player->y + (wall->player->x - wall->inter_x) * wall->tan; //?
//	A.y = Py + (Px-A.x)*tan(ALPHA);
	wall->dy = wall->block_size * wall->tan;
	find_wall(wall);
	return (fabs((wall->player->y - wall->inter_y) / sin(wall->cast_angle))); //почему abs взял на всю скобку? потому что в не зависимости от знака синуса результат не должен меняться, если пересечение дальше, то оно и должно быть дальше, иначе минимум не работает
}

int	find_horizontal_dist(t_wall *wall)
{
	if (wall->cast_angle <=  0.3 *  M_PI &&  wall->cast_angle >= 1.7 *  M_PI)
		return (wall->player->x);
	wall->tan = choose_tan_coef(wall, HORIZON);
	if (wall->cast_angle <= M_PI)
	{
		wall->inter_y = (wall->player->y / wall->block_size) * wall->block_size - 1;
		wall->dy = -1 * wall->block_size;
	}
	else
	{
		wall->inter_y = (wall->player->y / wall->block_size) *  wall->block_size + wall->block_size;
		wall->dy = wall->block_size;
	}
	
	wall->inter_x = wall->player->x + (wall->player->y - wall->inter_y) / wall->tan; //?
	wall->dx = wall->block_size / wall->tan;
	find_wall(wall);
	return (fabs((wall->player->y - wall->inter_y) / sin(wall->cast_angle))); //как раз проработать исклчение на синус и тангенс в нуле градусов.
}

void	draw_column(t_player *player, t_wall *wall, int x)
{
	int	y;

	wall->i = x;
	wall->dist_horizontal = find_horizontal_dist(wall);
	wall->dist_vertical = find_vertical_dist(wall);
	wall->dist_proj = ft_min(wall->dist_vertical, wall->dist_horizontal);
	wall->wall_height = wall->block_size * wall->dist_proj / wall->dist_real;
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
	while (++x < player->data->win_w) //x = 16 краш
		draw_column(player, wall, x);
	
}


//сначала каст одного луча. Сначала по горизонтали, потом по вертикали, по горизонтали сначала вычисляем
