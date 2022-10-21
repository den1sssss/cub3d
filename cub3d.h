#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include "libft/libft.h"
#include "MLX/mlx.h"

// #  define BUFFER_SIZE 1

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

	int		win_w;
	int		win_h;
}				t_data;

typedef struct game
{
	t_data	*data;
    char    plr_ch;
    int     plr_x;
    int     plr_y;
    char	*n;
    char	*s;
    char	*w;
    char	*e;
    char    *file;
    char	*bottom;
    char	  *top;
    char	**map;
	int		map_w;
	int		map_h;
	int		block_size;
}			t_game;


typedef	struct s_wall
{
	t_player	*player;
	int			block_size;
	int			dist_real;
	int			dist_vertical;
	int			dist_horizontal;
	int			dist_wall;
	int			inter_x;
	int			inter_y;
	int			dx;
	int			dy;
	int			x_grid;
	int			y_grid;
	
	
	
}			t_wall;



typedef struct s_player
{
	t_data		*data;
	t_game		*game;
	t_wall		*wall;
	
//	int		block_size;
	double	view_angle;
	double	delta_angle;
	int	x;
	int	y;
	
	double	angle;

	int		wall_dist;
	int		ray_dist;
	
}	t_player;


typedef struct s_minimap
{
	t_player	*player;
	t_game		*game;
	t_data		*data;
	int			color_wall;
	int			color_player;
	int			color_space;
	int			pix_per_block; //pixels per block
	int			w;
	int			h;
}	t_minimap;

//gnl
// int		ft_strlenn(char *str);
// int		indexkek(char *str);
// char	*ft_strdupp(char *str);
// char	*ft_strjoinn(char *str, char *kek);
// char	*perdelstr(char *str);
// char	*ostatok(char *str, int fd);
// char	*strochka(char *str);
// char	*get_next_line(int fd);
int		get_next_line(int fd, char **line);
// char	*cut_next_line(char *line);
// char	*push_line(char *line);
// int		check_line_break(char *str);

//validation.c
int validation(int argc,char **argv);
int	**getmap(char *file, char **str);
int	getwidth(char *file);
int	getheight(char *file);
//denispart.c
void denispart(t_game *game,char **argv);
void	init_data(t_game *game);
void read_file(t_game *game,char *argv);
void player_position(t_game *game);
int is_player(char c);

//parse.c
void    parse(t_game *game);
int     is_complete(t_game *game);
void get_params(int *i, t_game *game);
void check_params(t_game *game);
int check_param_value(char *target,int i,t_game *game, int flag);
void parse_param_value();
int	check_extention(t_game *game);
void check_permission(t_game *game);

//parse_map.c
int get_map_size(int i, t_game *game);
void parse_map(int i,t_game *game);
int	check_n(int i, t_game *game, char **map_elem);
//


//main.c
void denispart(t_game *game,char **argv);
void print_error(char *str);
void error_and_close(char *str,int fd);






//andrey part
void	draw_background(t_data *img, int color_ceil, int color_floor, int win_w, int win_h);

//events
int	ft_esc(int key);
int	ft_cross_button(int key);

//drawing tools
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int	create_trgb(int t, int r, int g, int b);

//minimap
void	draw_minimap(t_minimap *minimap);

//funcs
int	ft_min(int a, int b);
int	ft_max(int a, int b);



#endif
