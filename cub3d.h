#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include "libft/libft.h"

#  define BUFFER_SIZE 1

// typedef struct game
// {
//     int **map;
// } t_game;
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
    int		bottom;
    int		top;
    char	**map;
}	t_game;


//gnl
int		ft_strlenn(char *str);
int		indexkek(char *str);
char	*ft_strdupp(char *str);
char	*ft_strjoinn(char *str, char *kek);
char	*perdelstr(char *str);
char	*ostatok(char *str, int fd);
char	*strochka(char *str);
char	*get_next_line(int fd);
//validation.c
int validation(int argc,char **argv);
int	**getmap(char *file, char **str);
int	getwidth(char *file);
int	getheight(char *file);
//denispart.c
void denispart(t_game *game,char **argv);
void	init_data(t_game *game);
void read_file(t_game *game,char *argv);

//parse.c


#endif