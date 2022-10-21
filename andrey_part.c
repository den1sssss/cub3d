#include "cub3d.h"


int	big_str_print(char **str)
{
	int i;
	int j;

	if (!str || !(*str))
		return (printf("print_big_str error: no str!\n"));
	i = 0;
	while (str[i])
	{
		printf("[i = %d]\n", i);
		j = 0;
		while (str[i][j])
			printf("%c ", str[i][j++]);
		printf("\n");
		i++;
	}
	printf("i = %d\n", i);
//	return (0);
	exit(0);
}

//void	draw_player(t_data *img, t_player *player)
//{
//	
//}

//#include "cub3d.h"
//void print_error(char *str)
//{
//	write(2,str,ft_strlen(str));
//	exit(1);
//}
//void error_and_close(char *str,int fd)
//{
//	close(fd);
//	write(2,str,ft_strlen(str));
//	exit(1);
//}
//int main(int argc, char **argv)
//{
//	t_game *game;
//
//	if (argc != 2 || ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".cub", 4))
//		print_error("Error: bad arguments: try ./cub3d <___.cub>\n");
//	else
//	{
//		game = (t_game *)malloc(sizeof(t_game));
//		if (!game)
//			print_error("Error: cannot allocate memory\n");
//		denispart(game,argv);
//		// andreypart(&rc);
//	}
//	return (0);
//}

//typedef struct t_map
//{
//	t_player	*player;
//	t_game		*game;
//	float		scale;
//

//	int	w;
//	int	h;
//}				t_map;

void	find_player_x_y_angle(int x, int y, t_player *player, t_game *game, t_wall *wall)
{
	player->game = game;
	player->data = game->data;
	player->wall = wall;
	
	player->angle = M_PI * 200; //просто очень большой угол с запасом
	if (game->map[y][x] == 'N')
		player->angle += M_PI * 1.5;
	else if (game->map[y][x] == 'W')
		player->angle += M_PI;
	else if (game->map[y][x] == 'S')
		player->angle += M_PI * 0.5;
	player->x = x * game->block_size;
	player->y = y * game->block_size;
	player->view_angle = M_PI / 3; //угол обзора можно попробовать разным
	player->delta_angle = player->view_angle / game->map_w;
	player->y_horizon = game->data->win_h / 2;
}



void	player_init(t_player *player, t_game *game, t_wall *wall) //поставить в начале мэйна после парсинга сразу
{
	int	x;
	int	y;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == 'N' || game->map[y][x] == 'W' \
				|| game->map[y][x] == 'E' || game->map[y][x] == 'S')
			{
				find_player_x_y_angle(x, y, player, game, wall);
				break ;
			}
		}
	}
}

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	t_data	*data;
	t_wall *wall;
	t_player	*player;
	t_minimap	*minimap;
	float	fov;
	float	pov;
	//projection plane - размеры окна
	
	//parsing start
	t_game *game;
	game = (t_game *)malloc(sizeof(t_game));
	game->block_size = 64; //можно попробовать разным, степень двойки желательно
	denispart(game, argv);
//	game->map = ft_split("        1111111111111111111111111\n1000000000110000000000001\n   1011000001110000000000001\n   1001000000000000000000001\n11111111011000001110000000000001\n100000000011000001110111111111111\n11110111111111011100000010001\n11110111111111011101010010001\n11000000110101011100000010001\n10000000000000001100000010001\n10000000000000001101010010001\n11000001110101011111011110N01\n11110111 1110101 101111010001\n11111111 1111111 111111111111", '\n');
	//parsing end
	

	data = malloc(sizeof(t_data));
	player = malloc(sizeof(t_player));
	minimap = malloc(sizeof(t_minimap));
	wall = malloc(sizeof(t_wall));
	


	//data_init
//	int color = 0x00FFFFFF; //0,5626
	data->win_w = 1000;
	data->win_h = 800;

	
	//game_init
	game->map_w = 33; //для map = 1.cub
	game->map_h = 14;
	game->data = data;
	game->map[14] = NULL;
//	big_str_print(game->map);
	int	color_ceil = create_trgb(0, 0, 0, 255);
	int	color_floor = create_trgb(0, 0, 255, 255);
	
	
	player_init(player, game, wall);
	
	minimap->player = player;
	minimap->game = game;
	minimap->data = data;
	minimap->pix_per_block = ft_min(data->win_h, data->win_w) / (4 * ft_max(game->map_w, game->map_h));
	printf("pix = %d\n", minimap->pix_per_block);
	minimap->color_wall =  create_trgb(127, 255, 255, 255);
	minimap->color_player =  create_trgb(0, 255, 0, 0);
	minimap->color_space =  create_trgb(255, 255, 255, 255);
	
//	printf("win_h = %d\nwin_w = %d\n", data->win_h, data->win_h);
//	printf("minimap_h = %d\nmap_w = %d\n", game->map_h, game->map_w);
//	printf("znam = %d\n", 4 * ft_max(game->map_w, game->map_h));
//	printf("pix_per_block = %d", minimap->block_scale);

	
	//player_init

	
	
//	map->
//	float	player_cos = player_x / dist;
//	float	player_sin = player_y / dist;

	
 

	//part to make window
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, data->win_w, data->win_h, "Hello world!");
	data->img = mlx_new_image(mlx, data->win_w, data->win_h);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length,
								&data->endian);
	
	
	

	
	

	
	//draw background
	draw_background(data, color_ceil, color_floor, data->win_w, data->win_h);
	
	//draw minimap
	draw_minimap(minimap);
	draw_walls(player, wall);
	
	
	//turning on window and events
	mlx_put_image_to_window(mlx, mlx_win, data->img, 0, 0);
	mlx_hook(mlx_win, 2, 0, ft_esc, data);
	mlx_hook(mlx_win, 17, 0, ft_cross_button, data);
	mlx_loop(mlx);
}
