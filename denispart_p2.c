/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   denispart_p2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrdeysuvorov <anrdeysuvorov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 16:34:38 by anrdeysuvor       #+#    #+#             */
/*   Updated: 2022/10/30 16:35:00 by anrdeysuvor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_exit(t_game *game)
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
