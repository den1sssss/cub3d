/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_p2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrdeysuvorov <anrdeysuvorov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 16:34:31 by anrdeysuvor       #+#    #+#             */
/*   Updated: 2022/10/30 16:35:00 by anrdeysuvor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_ray_sub(t_raycast *rc)
{
	if (rc->config->plr_ch == 'N')
			rc->ray.dirx = -1;
	if (rc->config->plr_ch == 'S')
			rc->ray.dirx = 1;
	if (rc->config->plr_ch == 'E')
			rc->ray.diry = 1;
	if (rc->config->plr_ch == 'W')
			rc->ray.diry = -1;
	if (rc->config->plr_ch == 'N')
			rc->ray.plany = 0.66;
	if (rc->config->plr_ch == 'S')
			rc->ray.plany = -0.66;
	if (rc->config->plr_ch == 'E')
			rc->ray.planx = 0.66;
	if (rc->config->plr_ch == 'W')
			rc->ray.planx = -0.66;
}

void	ft_init_ray(t_raycast *rc)
{
	rc->data.forward = 0;
	rc->data.back = 0;
	rc->data.left = 0;
	rc->data.right = 0;
	rc->data.rotate_right = 0;
	rc->data.rotate_left = 0;
	rc->ray.posx = (double)rc->config->plr_x + 0.5;
	rc->ray.posy = (double)rc->config->plr_y + 0.5;
	rc->ray.dirx = 0;
	rc->ray.diry = 0;
	rc->ray.planx = 0;
	rc->ray.plany = 0;
	ft_init_ray_sub(rc);
}

void	ft_error(t_raycast *rc, char *str)
{
	int	i;

	rc->error = 1;
	write(1, "Error\n", 6);
	write(1, str, ft_strlen(str));
	if (rc->config->n)
		free(rc->config->n);
	if (rc->config->s)
		free(rc->config->s);
	if (rc->config->w)
		free(rc->config->w);
	if (rc->config->e)
		free(rc->config->e);
	i = 0;
	if (rc->config->map)
	{
		while (rc->config->map[i])
			free(rc->config->map[i++]);
		free(rc->config->map);
	}
	ft_exit(rc);
}

void	ft_get_texture(t_raycast *rc)
{
	rc->texture[0].img = mlx_xpm_file_to_image(rc->data.mlx_ptr, \
			rc->config->n, &(rc->texture[0].width), &(rc->texture[0].height));
	if (!rc->texture[0].img)
		ft_error(rc, "Texture NO\n");
	rc->texture[1].img = mlx_xpm_file_to_image(rc->data.mlx_ptr, \
			rc->config->n, &(rc->texture[1].width), &(rc->texture[1].height));
	if (!rc->texture[1].img)
		ft_error(rc, "Texture SO\n");
	rc->texture[2].img = mlx_xpm_file_to_image(rc->data.mlx_ptr, \
			rc->config->n, &(rc->texture[2].width), &(rc->texture[2].height));
	if (!rc->texture[2].img)
		ft_error(rc, "Texture WE\n");
	rc->texture[3].img = mlx_xpm_file_to_image(rc->data.mlx_ptr, \
			rc->config->n, &(rc->texture[3].width), &(rc->texture[3].height));
	if (!rc->texture[3].img)
		ft_error(rc, "Texture EA\n");
	ft_get_texture_adress(rc);
}
