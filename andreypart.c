#include "cub3d.h"
void    ft_count_lines(t_raycast *rc)
{
    int i;

    i = 0;
    while(rc->config->map[i])
        i++;
    rc->nblines = i;
}
//ft_init
void	ft_init(t_raycast *rc)
{
//    ft_count_lines(rc);
    // rc->config->map = NULL;
    // rc->config->no = NULL;
    // rc->config->so = NULL;
    // rc->config->we = NULL;
    // rc->config->ea = NULL;
    // rc->config->floor = -1;
    // rc->config->ceiling = -1;
    rc->nblines = 0;
    // rc->config->plr_x = 0;
    // rc->config->plr_y = 0;
    rc->count = 0;
    rc->screenx = 1024;
    rc->screeny = 540;
    write(1, "Try 2\n", 6);
    ft_init_sub(rc);
}
void	ft_init_sub(t_raycast *rc)
{
    write(1, "Try 3\n", 6);
    
    //rc->config->plr_ch = 'x';
    rc->error = 0;
    rc->data.img = NULL;
    rc->texture[0].img = NULL;
    rc->texture[1].img = NULL;
    rc->texture[2].img = NULL;
    rc->texture[3].img = NULL;
    rc->data.mlx_win = NULL;
    //rc->config->map = NULL;
}
//
void ft_kekfree(char **map,int n)
{
    int i;

    i = -1;
   if (map)
   {
       while (++i < n)
           free(map[i]);
   }
   free(map);
}

void andreypart(t_game *game)
{
    t_raycast	rc;
    
    ft_init(&rc);
    int swap;

	swap = 0;
	swap = game->plr_x;
	game->plr_x = game->plr_y;
	game->plr_y = swap;

	printf("Player letter: %c\n", game->plr_ch);
		
	game->map[game->plr_x][game->plr_y] = '0';
	printf("Player letter: %c\n", game->plr_ch);
	rc.config = game;
    ft_count_lines(&rc);
	ft_mlx(&rc);
    // ft_kekfree(rc.config->map,rc.nblines);

}