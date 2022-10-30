/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting_p2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrdeysuvorov <anrdeysuvorov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 16:33:54 by anrdeysuvor       #+#    #+#             */
/*   Updated: 2022/10/30 16:35:03 by anrdeysuvor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_calc_ray(t_raycast *rc)
{
	rc->ray.hit = 0;
	rc->ray.perpwalldist = 0;
	rc->ray.camerax = 2 * rc->ray.x / (double)rc->screenx - 1;
	rc->ray.raydirx = rc->ray.dirx + rc->ray.planx * \
						rc->ray.camerax;
	rc->ray.raydiry = rc->ray.diry + rc->ray.plany * \
						rc->ray.camerax;
	rc->ray.mapx = (int)rc->ray.posx;
	rc->ray.mapy = (int)rc->ray.posy;
	rc->ray.movespeed = 0.1;
	rc->ray.rotspeed = 0.033 * 1.8;
	ft_calc_ray_sub(rc);
}

void	ft_calc_ray_sub(t_raycast *rc)
{
	if (rc->ray.raydiry == 0)
		rc->ray.deltadistx = 0;
	else if (rc->ray.raydirx == 0)
		rc->ray.deltadistx = 1;
	else
		rc->ray.deltadistx = sqrt(1 + (rc->ray.raydiry \
		* rc->ray.raydiry) / (rc->ray.raydirx * rc->ray.raydirx));
	if (rc->ray.raydirx == 0)
		rc->ray.deltadisty = 0;
	else if (rc->ray.raydiry == 0)
		rc->ray.deltadisty = 1;
	else
		rc->ray.deltadisty = sqrt(1 + (rc->ray.raydirx * \
			rc->ray.raydirx) / (rc->ray.raydiry * rc->ray.raydiry));
}

void	ft_calc_step(t_raycast *rc)
{
	if (rc->ray.raydirx < 0)
	{
		rc->ray.stepx = -1;
		rc->ray.sidedistx = (rc->ray.posx - rc->ray.mapx) \
			* rc->ray.deltadistx;
	}
	else
	{
		rc->ray.stepx = 1;
		rc->ray.sidedistx = (rc->ray.mapx + 1.0 - rc->ray.posx) \
			* rc->ray.deltadistx;
	}
	if (rc->ray.raydiry < 0)
	{
		rc->ray.stepy = -1;
		rc->ray.sidedisty = (rc->ray.posy - rc->ray.mapy) \
			* rc->ray.deltadisty;
	}
	else
	{
		rc->ray.stepy = 1;
		rc->ray.sidedisty = (rc->ray.mapy + 1.0 - rc->ray.posy) \
			* rc->ray.deltadisty;
	}
	ft_increment_ray(rc);
}

void	ft_increment_ray(t_raycast *rc)
{
	while (rc->ray.hit == 0)
	{
		if (rc->ray.sidedistx < rc->ray.sidedisty)
		{
			rc->ray.sidedistx += rc->ray.deltadistx;
			rc->ray.mapx += rc->ray.stepx;
			rc->ray.side = 0;
		}
		else
		{
			rc->ray.sidedisty += rc->ray.deltadisty;
			rc->ray.mapy += rc->ray.stepy;
			rc->ray.side = 1;
		}
		if (rc->config->map[rc->ray.mapx][rc->ray.mapy] == '1')
			rc->ray.hit = 1;
	}
	ft_calc_start_end(rc);
}

void	ft_calc_start_end(t_raycast *rc)
{
	if (rc->ray.side == 0)
		rc->ray.perpwalldist = ((double)rc->ray.mapx - \
			rc->ray.posx + (1 - (double)rc->ray.stepx) / 2) / rc->ray.raydirx;
	else
		rc->ray.perpwalldist = ((double)rc->ray.mapy - \
			rc->ray.posy + (1 - (double)rc->ray.stepy) / 2) / rc->ray.raydiry;
	rc->ray.lineheight = (int)(rc->screeny / rc->ray.perpwalldist);
	rc->ray.drawstart = -rc->ray.lineheight / 2 + rc->screeny / 2;
	if (rc->ray.drawstart < 0)
		rc->ray.drawstart = 0;
	rc->ray.drawend = rc->ray.lineheight / 2 + rc->screeny / 2;
	if (rc->ray.drawend >= rc->screeny || rc->ray.drawend < 0)
		rc->ray.drawend = rc->screeny - 1;
}
