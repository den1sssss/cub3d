/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrdeysuvorov <anrdeysuvorov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 16:34:10 by anrdeysuvor       #+#    #+#             */
/*   Updated: 2022/10/30 16:35:09 by anrdeysuvor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_max_width(t_game *game)
{
	int	width;
	int	i;
	int	j;

	width = 0;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '1' && j > width)
				width = j;
			j++;
		}
		i++;
	}
	return (width);
}

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

int	get_map_size(int i, t_game *game)
{
	int	size;

	size = 0;
	while (game->file[i])
	{
		if (game->file[i] == '\n')
			size++;
		i++;
	}
	return (size);
}

void	parse_map(int i, t_game *game)
{
	int	save_i;
	int	size;
	int	j;

	j = 0;
	printf("\nMap parsing started\n");
	while (game->file[i] && (game->file[i] == ' ' || \
	game->file[i] == '\t' || game->file[i] == '\n'))
		i++;
	save_i = i;
	size = get_map_size(i, game);
	game->max_height = size;
	printf("MAX_HEIGHT = %d\n", game->max_height);
	i = save_i;
	game->map = (char **)malloc(sizeof(char *) * (size + 2));
	while (i > 0 && game->file[i - 1] != '\n')
		--i;
	while (j < size + 1)
	{
		i = check_n(i, game, &game->map[j]);
		++j;
	}
	game->map[j] = NULL;
	game->max_width = get_max_width(game);
	printf("MAX_WIDTH = %d", game->max_width);
}
