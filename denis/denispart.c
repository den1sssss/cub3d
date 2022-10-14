#include "../cub3d.h"
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
	print_error("Error: problem with fd or permission\n");
}
void	init_data(t_game *game)
{
	game->top = NULL;
	game->bottom = NULL;
	game->file = NULL;
	game->map = NULL;
	game->e = NULL;
	game->n = NULL;
	game->s = NULL;
	game->w = NULL;
}
int is_player(char c)
{
	return(c == 'N' || c == 'E' || c == 'W' || c == 'E');
}
void player_position(t_game *game)
{
	int i;
	int j;

	i = 0;
	while(game->map[i])
	{
		j = 0;
		while(game->map[i][j])
		{
			if (is_player(game->map[i][j]))
			{
				game->plr_ch = game->map[i][j];
				game->plr_x = j;
				game->plr_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

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
    fd = open(argv, O_RDONLY);
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
    printf("readfile:\n%s",game->file); // test
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
	read_file(game, argv[1]);
    //
	parse(game);
	player_position(game);
	printf("\nplr_ch = %c",game->plr_ch);
	printf("\nplr_x = %d",game->plr_x);
	printf("\nplr_y = %d",game->plr_y);
    // printf("Player position: %d %d\n", game->plr_x, game->plr_y);
	// int i;

	// i = 0;
	// while (game->map[i])
	// {
	// 	printf("%s\n", game->map[i]);
	// 	i++;
	// }
}
