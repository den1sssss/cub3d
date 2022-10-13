#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include "libft/libft.h"

// #  define BUFFER_SIZE 1

typedef struct game
{
    char    plr_ch;
    int     plr_x;
    int     plr_y;
    char	*n;
    char	*s;
    char	*w;
    char	*e;
    char    *file;
    char    *bottom;
    char    *top;
    char	**map;
}	t_game;


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
void validation(t_game *game);
int is_space_or_tab(char a, int check);
void	check_error(t_game *game, int j, int i);
void	check_first_last_string(int j, t_game *game);
// void map_validation(t_game *game);
// int	**getmap(char *file, char **str);
// int	getwidth(char *file);
// int	getheight(char *file);

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
void print_error(char *str);
void error_and_close(char *str,int fd);

#endif