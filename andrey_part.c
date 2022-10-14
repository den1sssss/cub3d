#include "cub3d.h"


int	big_str_print(char **str)
{
	int i;
	int j;

	if (!str || !(*str))
		return (printf("print_big_str error: no str!\n"));
	while (str[i])
	{
		j = 0;
		while (str[i][j])
			printf("%c", str[i][j++]);
		i++;
	}
	return (0);
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

typedef struct t_map
{
	t_player	*player;
	t_game		*game;
	float		scale;
	
	int	w;
	int	h;
}				t_map;

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_player	*player;
	t_map	*map;
	float	fov;
	float	pov;
	//projection plane - размеры окна
	
	//parsing start
	t_game *game;
	game = (t_game *)malloc(sizeof(t_game));
	denispart(game, argv);
//	game->map = ft_split("        1111111111111111111111111\n1000000000110000000000001\n   1011000001110000000000001\n   1001000000000000000000001\n11111111011000001110000000000001\n100000000011000001110111111111111\n11110111111111011100000010001\n11110111111111011101010010001\n11000000110101011100000010001\n10000000000000001100000010001\n10000000000000001101010010001\n11000001110101011111011110N01\n11110111 1110101 101111010001\n11111111 1111111 111111111111", '\n');
	//parsing end
//	big_str_print(game->map);


	player = malloc(sizeof(t_player *));
	map = malloc(sizeof(t_map *));

	
	int color = 0x00FFFFFF; //0,5626
	int	win_w = 700;
	int	win_h = 700;
	
	
	int	color_ceil = 0x000000FF;
	int	color_floor = 0x00FFFF00;
	
	

	player->angle = 0.7;
	player->x = 200;
	player->y = 200;
	player->dist = 100;
	
	map->player = player;
	map->game = game;
//	map->
//	float	player_cos = player_x / dist;
//	float	player_sin = player_y / dist;

	
 

//	a = (color >> 24) & 255;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, win_w, win_h, "Hello world!");
	img.img = mlx_new_image(mlx, win_w, win_h);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	
	
	

	draw_background(&img, color_ceil, color_floor, win_w, win_h);
	
	
	
	
	
	
	
	
	
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	//кнопки крест и esc
	mlx_hook(mlx_win, 2, 0, ft_esc, &img);
	mlx_hook(mlx_win, 17, 0, ft_cross_button, &img);
	mlx_loop(mlx);
}
