/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrdeysuvorov <anrdeysuvorov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 16:34:33 by anrdeysuvor       #+#    #+#             */
/*   Updated: 2022/10/30 16:35:03 by anrdeysuvor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_get_texture_adress(t_raycast *rc)
{
		rc->texture[0].addr = (int *)mlx_get_data_addr(rc->texture[0].img, \
		&rc->texture[0].bits_per_pixel, \
&rc->texture[0].line_length, &rc->texture[0].endian);
		rc->texture[1].addr = (int *)mlx_get_data_addr(rc->texture[1].img, \
		&rc->texture[1].bits_per_pixel, \
		&rc->texture[1].line_length, &rc->texture[1].endian);
		rc->texture[2].addr = (int *)mlx_get_data_addr(rc->texture[2].img, \
		&rc->texture[2].bits_per_pixel, \
		&rc->texture[2].line_length, &rc->texture[2].endian);
		rc->texture[3].addr = (int *)mlx_get_data_addr(rc->texture[3].img, \
	&rc->texture[3].bits_per_pixel, \
	&rc->texture[3].line_length, &rc->texture[3].endian);
}

int	ft_exit(t_raycast *rc)
{
	if (rc->error == 0)
		ft_error(rc, "Error = 0\n");
	if (rc->data.img)
		mlx_destroy_image(rc->data.mlx_ptr, rc->data.img);
	if (rc->texture[0].img)
		mlx_destroy_image(rc->data.mlx_ptr, rc->texture[0].img);
	if (rc->texture[1].img)
		mlx_destroy_image(rc->data.mlx_ptr, rc->texture[1].img);
	if (rc->texture[2].img)
		mlx_destroy_image(rc->data.mlx_ptr, rc->texture[2].img);
	if (rc->texture[3].img)
		mlx_destroy_image(rc->data.mlx_ptr, rc->texture[3].img);
	if (rc->data.mlx_win)
		mlx_destroy_window(rc->data.mlx_ptr, rc->data.mlx_win);
	exit(0);
}

int	ft_key_press(int keycode, t_raycast *rc)
{
	printf("key : %d\n", keycode);
	if (keycode == W_KEY)
			rc->data.forward = 1;
	else if (keycode == S_KEY)
			rc->data.back = 1;
	else if (keycode == A_KEY)
			rc->data.left = 1;
	else if (keycode == D_KEY)
			rc->data.right = 1;
	else if (keycode == LEFT_KEY)
			rc->data.rotate_left = 1;
	else if (keycode == RIGHT_KEY)
			rc->data.rotate_right = 1;
	else if (keycode == ESC_KEY)
		ft_error(rc, "Esc button\n");
	return (1);
}

int	ft_key_release(int keycode, t_raycast *rc)
{
	if (keycode == W_KEY)
			rc->data.forward = 0;
	else if (keycode == S_KEY)
			rc->data.back = 0;
	else if (keycode == A_KEY)
			rc->data.left = 0;
	else if (keycode == D_KEY)
			rc->data.right = 0;
	else if (keycode == LEFT_KEY)
			rc->data.rotate_left = 0;
	else if (keycode == RIGHT_KEY)
			rc->data.rotate_right = 0;
	return (1);
}

int	ft_mlx(t_raycast *rc)
{
	ft_init_ray(rc);
	rc->data.mlx_ptr = mlx_init();
	if (!(rc->data.mlx_ptr))
		ft_error(rc, "Mlx init impossible\n");
	ft_get_texture(rc);
	rc->data.img = mlx_new_image(rc->data.mlx_ptr, rc->screenx, rc->screeny);
	rc->data.addr = (int *)mlx_get_data_addr(rc->data.img, \
		&rc->data.bits_per_pixel, \
		&rc->data.line_length, &rc->data.endian);
	rc->data.mlx_win = mlx_new_window(rc->data.mlx_ptr, \
					rc->screenx, rc->screeny, "Cub3d");
	mlx_hook(rc->data.mlx_win, 33, 1L << 17, ft_exit, rc);
	mlx_hook(rc->data.mlx_win, 2, 1L << 0, ft_key_press, rc);
	mlx_loop_hook(rc->data.mlx_ptr, ft_raycasting, rc);
	mlx_hook(rc->data.mlx_win, 3, 1L << 1, ft_key_release, rc);
	mlx_loop(rc->data.mlx_ptr);
	return (0);
}
