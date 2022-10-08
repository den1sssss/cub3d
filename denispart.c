#include "cub3d.h"
void	init_data(t_game *game)
{
	game->top = -10;
	game->bottom = -10;
	game->file = NULL;
	game->map = NULL;
	game->e = NULL;
	game->n = NULL;
	game->s = NULL;
	game->w = NULL;
}
// void init_player(t_game *game)
// {

// }
// void parse_data(t_game *game)
// {

// }
void read_file(t_game *game,char *argv)
{
    int fd;
    char *save;
    char *addition;

	save = NULL;
	addition = NULL;
    fd = open(argv,O_RDONLY);
    // if(fd == -1)
        // ft_error();
    while(get_next_line(fd))
    {
        addition = game->file;
		game->file = ft_strjoin(addition, save);
		free(addition);
		free(save);
		addition = game->file;
		game->file = ft_strjoin(addition, "\n");
		free(addition);
    }
    addition = game->file;
    game->file = ft_strjoin(addition, save);
    printf("readfile = %s\n",game->file); // test
    free(addition);
    free(save);
    close(fd);

    //test
    // printf("readfile = %s",game->file);

}
void denispart(t_game *game,char **argv)
{
    init_data(game);
    //
	read_file(game, argv[1]);
    
	// parse(game);
	// init_player(game);	
    // printf("Player position: %d %d\n", game->plr_x, game->plr_y);
	// int i;

	// i = 0;
	// while (game->map[i])
	// {
	// 	printf("%s\n", game->map[i]);
	// 	i++;
	// }
}