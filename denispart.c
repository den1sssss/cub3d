/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   denispart.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrdeysuvorov <anrdeysuvorov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 16:34:35 by anrdeysuvor       #+#    #+#             */
/*   Updated: 2022/10/30 16:35:02 by anrdeysuvor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_player(char c)
{
	return (c == 'N' || c == 'E' || c == 'W' || c == 'E');
}

void	player_position(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
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

void	read_file_p2(t_game *game, int fd, char **newstr, char *current_file)
{
	while (get_next_line(fd, newstr))
	{
		current_file = game->file;
		game->file = ft_strjoin(current_file, *newstr);
		free(current_file);
		free(*newstr);
		current_file = game->file;
		game->file = ft_strjoin(current_file, "\n");
		free(current_file);
	}
}

void	read_file(t_game *game, char *argv)
{
	int		fd;
	char	*newstr;
	char	*current_file;

	newstr = NULL;
	current_file = NULL;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		free_exit(game);
	read_file_p2(game, fd, &newstr, current_file);
	current_file = game->file;
	game->file = ft_strjoin(current_file, newstr);
	printf("readfile:\n%s", game->file);
	free(current_file);
	free(newstr);
	close(fd);
}

void	denispart(t_game *game, char **argv)
{
	int	i;

	init_data(game);
	read_file(game, argv[1]);
	parse(game);
	validation(game);
	player_position(game);
	printf("\nplr_ch = %c", game->plr_ch);
	printf("\nplr_x = %d", game->plr_x);
	printf("\nplr_y = %d", game->plr_y);
	printf("\nFLOOR = %x", game->floor);
	printf("\nCEILING = %x", game->ceiling);
	printf("Player position: %d %d\n", game->plr_x, game->plr_y);
}
