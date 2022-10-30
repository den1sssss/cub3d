/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrdeysuvorov <anrdeysuvorov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 16:34:42 by anrdeysuvor       #+#    #+#             */
/*   Updated: 2022/10/30 16:34:58 by anrdeysuvor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include "libft/libft.h"
# include "MLX/mlx.h"
# define LEFT_KEY   123
# define RIGHT_KEY   124
# define W_KEY	  13
# define S_KEY	  1
# define D_KEY	  2
# define A_KEY	  0
# define ESC_KEY	53

typedef struct game
{
	char	plr_ch;
	int		plr_x;
	int		plr_y;
	char	*n;
	char	*s;
	char	*w;
	char	*e;
	char	*file;
	char	*bottom;
	char	*top;
	int		floor;
	int		ceiling;
	char	**map;
	int		max_height;
	int		max_width;
}	t_game;

typedef struct s_texture
{
	int				texdir;
	double			wallx;
	int				texx;
	int				texy;
	double			step;
	double			texpos;
}					t_texture;

typedef struct s_ray
{
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planx;
	double			plany;
	double			raydirx;
	double			raydiry;
	double			camerax;
	int				mapx;
	int				mapy;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	double			perpwalldist;
	int				lineheight;
	int				drawstart;
	int				drawend;
	double			movespeed;
	double			rotspeed;
	int				x;
	int				texture;
}					t_ray;

typedef struct s_info
{
	void			*mlx_ptr;
	void			*mlx_win;
	void			*img;
	int				*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				forward;
	int				back;
	int				left;
	int				right;
	int				rotate_left;
	int				rotate_right;
	int				width;
	int				height;
}					t_info;

typedef struct s_raycast
{
	int				nblines;
	int				error;
	int				screenx;
	int				screeny;
	int				count;
	t_info			texture[4];
	t_info			data;
	t_ray			ray;
	t_texture		t;
	t_game			*config;
}					t_raycast;

void	ft_freemap(t_game *game);
int		get_next_line(int fd, char **line);
void	validation(t_game *game);
int		is_space_or_tab(char a, int check);
void	check_error(t_game *game, int j, int i);
void	check_first_last_string(int j, t_game *game);
void	denispart(t_game *game, char **argv);
void	init_data(t_game *game);
void	read_file(t_game *game, char *argv);
void	player_position(t_game *game);
int		is_player(char c);
void	free_exit(t_game *game);
void	parse(t_game *game);
int		is_complete(t_game *game);
void	get_params(int *i, t_game *game);
void	check_params(t_game *game);
int		check_param_value(char *target, int i, t_game *game, int flag);
void	parse_param_value(char **str, int *i, t_game *game);
int		check_extention(t_game *game);
void	check_permission(t_game *game);
int		get_map_size(int i, t_game *game);
void	parse_map(int i, t_game *game);
int		check_n(int i, t_game *game, char **map_elem);
int		get_max_width(t_game *game);
void	check_color(t_game *game, char *str, char color);
void	check_numbers(char **str);
int		create_trgb(int r, int g, int b);
void	free_param(char **param);
void	print_error(char *str);
void	error_and_close(char *str, int fd);
void	andreypart(t_game *game);
void	ft_init_sub(t_raycast *rc);
void	ft_init(t_raycast *rc);
void	ft_count_lines(t_raycast *rc);
int		ft_mlx(t_raycast *rc);
int		ft_key_release(int keycode, t_raycast *rc);
int		ft_key_press(int keycode, t_raycast *rc);
int		ft_exit(t_raycast *rc);
void	ft_get_texture(t_raycast *rc);
void	ft_get_texture_adress(t_raycast *rc);
void	ft_error(t_raycast *rc, char *str);
void	ft_init_ray(t_raycast *rc);
void	ft_init_ray_sub(t_raycast *rc);
int		ft_raycasting(t_raycast *rc);
void	ft_rotate_left(t_raycast *rc, double olddirx);
void	ft_rotate_right_left(t_raycast *rc);
void	ft_left_right(t_raycast *rc);
void	ft_forward_back(t_raycast *rc);
void	ft_init_texture(t_raycast *rc);
void	ft_draw_texture(t_raycast *rc, int x, int y);
int		ft_color_column(t_raycast *rc);
void	ft_calc_start_end(t_raycast *rc);
void	ft_increment_ray(t_raycast *rc);
void	ft_calc_step(t_raycast *rc);
void	ft_calc_ray_sub(t_raycast *rc);
void	ft_calc_ray(t_raycast *rc);
void	ft_kekfree(char **map, int n);

#endif
