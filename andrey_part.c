#include "cub3d.h"




void	draw_player(t_data *img, t_player *player)
{
	
}



int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_player	*player;
	float	fov;
	float	pov;
	//projection plane - размеры окна
	
	player = malloc(sizeof(player));
	
	
	int color = 0x00FFFFFF; //0,5626
	int	win_w = 700;
	int	win_h = 700;
	
	
	int	color_ceil = 0x000000FF;
	int	color_floor = 0x00FFFF00;
	
	

	player->angle = 0.7;
	player->x = 200;
	player->y = 200;
	player->dist = 100;
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
