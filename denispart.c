#include "cub3d.h"
void free_exit(t_game *game)
{
	int	i;

	i = 0;
	if (game->map)
	{
		while (game->map[i])
			free(game->map[i++]);
		free(game->map);
	}
	free(game);
	write(2, "Error: problem with fd\n", 24);
	exit(0);
}
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
    char *newstr; // новая строчка
    char *current_file; //все с начала до новой строчки

	newstr = NULL;
	current_file = NULL;
    fd = open(argv,O_RDONLY);
    if(fd == -1)
		free_exit(game);
    while(get_next_line(fd,&newstr))
    {
        current_file = game->file;
		game->file = ft_strjoin(current_file, newstr);
		// printf("newstr = %s\n",game->file); // test
		free(current_file);
		free(newstr);
		current_file = game->file;
		game->file = ft_strjoin(current_file, "\n");
		free(current_file);
    }
    current_file = game->file;
    game->file = ft_strjoin(current_file, newstr);
    printf("readfile:\n%s\n",game->file); // test
	// printf("curr= %s\n",current_file); // test
    free(current_file);
    free(newstr);
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