#include "cub3d.h"
int	check_n(int i, t_game *game, char **map_elem)
{
	int	start;

	start = i;
	while (game->file[i] && game->file[i] != '\n')
		++i;
	*map_elem = ft_substr(game->file, start, i - start);
	if (game->file[i] == '\n')
		++i;
	return (i);
}
int get_map_size(int i, t_game *game)
{
    int size;

    size = 0;
    while(game->file[i])
    {
        if(game->file[i] == '\n')
            size++;
        i++;
    }
    return (size);
}
void parse_map(int i, t_game * game)
{
    int	save_i;
	int	size;
	int	j;

    j = 0;
    printf("\nMap parsing started\n");
    while(game->file[i] && (game->file[i] == ' ' ||  \
    game->file[i] == '\t' || game->file[i] == '\n'))
        i++;
	save_i = i;
	size = get_map_size(i, game);
    printf("SIZE = %d",size);
	i = save_i;
	game->map = (char **)malloc(sizeof(char *) * (size + 2));
	while (i > 0 && game->file[i - 1] != '\n')
		--i;
	while (j < size + 1)
	{
		i = check_n(i, game, &game->map[j]);
		++j;
	}
	// game->map[j] = NULL;
	//
	printf("\n------MAP-----\n");
	for(i = 0; i < size; i++)
		printf("%s\n",game->map[i]);
	printf("------MAP-----\n");
	//
}