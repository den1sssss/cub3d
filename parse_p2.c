/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_p2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrdeysuvorov <anrdeysuvorov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 16:34:12 by anrdeysuvor       #+#    #+#             */
/*   Updated: 2022/10/30 16:35:08 by anrdeysuvor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_extention(t_game *game)
{
	if (ft_strncmp(&game->e[ft_strlen(game->e) - 4], ".xpm", 4))
		return (1);
	if (ft_strncmp(&game->n[ft_strlen(game->n) - 4], ".xpm", 4))
		return (1);
	if (ft_strncmp(&game->s[ft_strlen(game->s) - 4], ".xpm", 4))
		return (1);
	if (ft_strncmp(&game->w[ft_strlen(game->w) - 4], ".xpm", 4))
		return (1);
	return (0);
}

void	check_permission(t_game *game)
{
	int	fd;

	fd = open(game->n, O_RDONLY);
	if (fd == -1)
		error_and_close("Error: dont have a \
		 permission to read or open or wrong path\n", fd);
	fd = open(game->e, O_RDONLY);
	if (fd == -1)
		error_and_close("Error: dont have a permission \
		 to read or open or wrong path\n", fd);
	fd = open(game->s, O_RDONLY);
	if (fd == -1)
		error_and_close("Error: dont have a \
		permission to read or open or wrong path\n", fd);
	fd = open(game->w, O_RDONLY);
	if (fd == -1)
		error_and_close("Error: dont have a \
		 permission to read or open or wrong path\n", fd);
}

void	check_params(t_game *game)
{
	if (game->e == NULL || game->n == NULL || \
		game->s == NULL || game->w == NULL)
		print_error("Error: blank parameter\n");
	if (check_extention(game))
		print_error("Error: wrong extention\n");
	check_permission(game);
	check_color(game, game->bottom, 'F');
	check_color(game, game->top, 'C');
	printf("FLOOR = %d", game->floor);
	printf("FLOOR = %d", game->ceiling);
}

void	parse_param_value(char **param, int *i, t_game *game)
{
	int	pos;

	pos = 0;
	if (*param)
		print_error("Error: parameter already exists\n");
	while (game->file[*i] && (game->file[*i] == ' ' || game->file[*i] == '\t'))
		(*i)++;
	pos = *i;
	while (game->file[*i] && game->file[*i] != ' ' && \
			game->file[*i] != '\n' && game->file[*i] != '\t')
		(*i)++;
	if (pos == (*i))
		print_error("Parse_param_value error\n");
	*param = ft_substr(game->file, pos, (*i) - pos);
}

int	check_param_value(char *target, int i, t_game *game, int flag)
{
	if (flag == 1)
	{
		if (target[0] == game->file[i] && target[1] == game->file[i + 1])
		{
			if (game->file[i + 2] == ' ' || game->file[i + 2] == '\t')
				return (1);
			else
				print_error("Value parse error\n");
		}
	}
	else if (flag == 0)
	{
		if (target[0] == game->file[i])
		{
			if (game->file[i + 1] == ' ' || game->file[i + 1] == '\t')
				return (1);
			else
				print_error("Color parse error\n");
		}
	}
	return (0);
}
