/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrdeysuvorov <anrdeysuvorov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 16:34:04 by anrdeysuvor       #+#    #+#             */
/*   Updated: 2022/10/30 16:35:06 by anrdeysuvor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_next_line_p2(int fd, char **line, int *r, int *len)
{
	char	c;
	char	*tmp;
	int		i;

	*r = read(fd, &c, 1);
	while (*r && (*len)++ && c != '\n')
	{
		tmp = malloc(*len);
		i = 0;
		while (i < *len - 2)
		{
			tmp[i] = (*line)[i];
			i++;
		}
		tmp[i] = c;
		tmp[i + 1] = 0;
		free(*line);
		*line = tmp;
		*r = read(fd, &c, 1);
	}
}

int	get_next_line(int fd, char **line)
{
	int		i;
	int		len;
	int		r;

	r = 0;
	len = 1;
	*line = malloc(len);
	(*line)[0] = 0;
	get_next_line_p2(fd, line, &r, &len);
	return (r);
}
