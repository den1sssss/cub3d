/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrdeysuvorov <anrdeysuvorov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 16:34:14 by anrdeysuvor       #+#    #+#             */
/*   Updated: 2022/10/30 16:35:10 by anrdeysuvor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_params_p2(int *i, t_game *game)
{
	if (check_param_value("NO", *i, game, 1))
	{
		(*i) += 2;
		parse_param_value(&(game->n), i, game);
	}
	else if (check_param_value("WE", *i, game, 1))
	{
		(*i) += 2;
		parse_param_value(&(game->w), i, game);
	}
	else if (check_param_value("SO", *i, game, 1))
	{
		(*i) += 2;
		parse_param_value(&(game->s), i, game);
	}
}

void	get_params_p3(int *i, t_game *game)
{
	if (check_param_value("EA", *i, game, 1))
	{
		(*i) += 2;
		parse_param_value(&(game->e), i, game);
	}
	else if (check_param_value("F", *i, game, 0))
	{
		(*i) += 2;
		parse_param_value(&(game->bottom), i, game);
	}
	else if (check_param_value("C", *i, game, 0))
	{
		(*i) += 2;
		parse_param_value(&(game->top), i, game);
	}
}

void	get_params(int *i, t_game *game)
{
	while (game->file[*i] && (game->file[*i] == ' ' || \
				game->file[*i] == '\t' || game->file[*i] == '\n'))
		(*i)++;
	get_params_p2(i, game);
	get_params_p3(i, game);
}

int	is_complete(t_game *game)
{
	if (game->bottom && game->top && game->e \
	&& game->s && game->n && game->w)
		return (1);
	return (0);
}

void	parse(t_game *game)
{
	int	i;

	if (game)
		printf("\n--------\ncool.Parsing started...\n-------\n");
	i = 0;
	while (game->file[i])
	{
		if (is_complete(game))
			break ;
		get_params(&i, game);
		i++;
	}
	check_params(game);
	printf("Parse results:\n");
	printf("n = %s\n", game->n);
	printf("s = %s\n", game->s);
	printf("w = %s\n", game->w);
	printf("e = %s\n", game->e);
	printf("bottom = %s\n", game->bottom);
	printf("top= %s\n", game->top);
	parse_map(i, game);
}
