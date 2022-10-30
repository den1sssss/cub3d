/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   andreypart.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrdeysuvorov <anrdeysuvorov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 16:34:48 by anrdeysuvor       #+#    #+#             */
/*   Updated: 2022/10/30 16:34:53 by anrdeysuvor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_count_lines(t_raycast *rc)
{
	int	i;

	i = 0;
	while (rc->config->map[i])
		i++;
	rc->nblines = i;
}

void	ft_init(t_raycast *rc)
{
	rc->nblines = 0;
	rc->count = 0;
	rc->screenx = 1024;
	rc->screeny = 540;
	write(1, "Try 2\n", 6);
	ft_init_sub(rc);
}

void	ft_init_sub(t_raycast *rc)
{
	write(1, "Try 3\n", 6);
	rc->error = 0;
	rc->data.img = NULL;
	rc->texture[0].img = NULL;
	rc->texture[1].img = NULL;
	rc->texture[2].img = NULL;
	rc->texture[3].img = NULL;
	rc->data.mlx_win = NULL;
}

void	ft_kekfree(char **map, int n)
{
	int	i;

	i = -1;
	if (map)
	{
		while (++i < n)
			free(map[i]);
		free(map);
	}
}

void	andreypart(t_game *game)
{
	t_raycast	rc;
	int			swap;

	ft_init(&rc);
	swap = game->plr_x;
	game->plr_x = game->plr_y;
	game->plr_y = swap;
	printf("Player letter: %c\n", game->plr_ch);
	game->map[game->plr_x][game->plr_y] = '0';
	printf("Player letter: %c\n", game->plr_ch);
	rc.config = game;
	ft_count_lines(&rc);
	ft_mlx(&rc);
}
