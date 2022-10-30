/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrdeysuvorov <anrdeysuvorov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 16:34:45 by anrdeysuvor       #+#    #+#             */
/*   Updated: 2022/10/30 16:34:55 by anrdeysuvor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_trgb( int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	check_numbers(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]))
				print_error("Error: incorrect color value");
			j++;
		}
		i++;
	}
}

void	free_param(char **param)
{
	int	i;

	i = 0;
	if (param)
	{
		while (param[i])
			free(param[i++]);
		free(param);
	}
}

void	check_color(t_game *game, char *str, char color)
{
	char		**param;
	int			r;
	int			g;
	int			b;
	int			i;

	i = 0;
	param = ft_split(str, ',');
	while (param[i])
		i++;
	if (i != 3)
		print_error("Error: problem with colors\n");
	check_numbers(param);
	r = ft_atoi(param[0]);
	g = ft_atoi(param[1]);
	b = ft_atoi(param[2]);
	if (r > 255 || g > 255 || b > 255)
		print_error("Error: incorrect color values");
	if (color == 'F')
		game->floor = create_trgb(r, g, b);
	else if (color == 'C')
		game->ceiling = create_trgb(r, g, b);
	free_param(param);
}
