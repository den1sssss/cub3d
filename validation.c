#include "cub3d.h"

void	check_first_last_string(int j, t_game *game)
{
	int	i;

	i = 0;
	while (game->map[j][i])
	{
		if (game->map[j][i] != '1' && is_space_or_tab(game->map[j][i], 1))
            print_error("Error: parameters problem[1]\n");
		i++;
	}
}
void	check_error(t_game *game, int j, int i)
{
	while (game->map[j][i])
	{
		if (game->map[j][i] && game->map[j][i] != '0'
			&& game->map[j][i] != '1' && is_space_or_tab(game->map[j][i], 1)
			&& !is_player(game->map[j][i]))
            print_error("Error: map error\n");
		if (game->map[j][i] == '0')
		{
			if ((game->map[j - 1] && ft_strlen(game->map[j - 1]) < (size_t)i)
				|| (game->map[j - 1][i] && is_space_or_tab(game->map[j - 1][i], 0)))
		            print_error("Error: map error\n");
			if ((game->map[j + 1] && ft_strlen(game->map[j + 1]) < (size_t)i)
				|| (game->map[j + 1][i] && is_space_or_tab(game->map[j + 1][i], 0)))
	            print_error("Error: map error\n");
		}
		if (game->map[j][i] && is_player(game->map[j][i]) && !game->plr_ch)
			game->plr_ch = game->map[j][i];
		else if (game->map[j][i] && is_player(game->map[j][i]) && game->plr_ch)
            print_error("Error: map error\n");
		i++;
		if ((is_space_or_tab(game->map[j][i], 0) || game->map[j][i] == '\n'
			|| game->map[j][i] == '\0') && (game->map[j][i - 1] != '1'
			&& is_space_or_tab(game->map[j][i - 1], 1)))
            print_error("Error: map error\n");
	}
}
int	is_space_or_tab(char a, int check)
{
	if (check)
		return (a != ' ' && a != '\t');
	return (a == ' ' || a == '\t');
}
void validation(t_game *game)
{
    int	i;
	int	j;

	j = 1;
	check_first_last_string(0, game);
	while (game->map[j])
	{
		i = 0;
		while (game->map[j][i] && is_space_or_tab(game->map[j][i], 0))
			i++;
		if (i == 0 && game->map[j][i] == '\0')
            print_error("Error: parameters problem[2]\n");
		if (game->map[j][i] && game->map[j][i] != '1')
            print_error("Error: map is open\n");
		check_error(game, j, i);
		j++;
		if (!game->map[j + 1])
		{
			check_first_last_string(j, game);
			break ;
		}
	}
	if (!game->plr_ch)
        print_error("Error: no player position\n");
    printf("MAP IS CORRECT!\n");
}