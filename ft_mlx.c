#include "cub3d.h"
//ft_init_ray
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
//
//ft_error
void	ft_error(t_raycast *rc, char *str)
{
    // int i;

    // i = -1;
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
//    if (rc->config.map)
//    {
//        while (++i < rc->nblines)
//            free(rc->config.map[i]);
//    }
    if (rc->config->map)
        free(rc->config->map);
    ft_exit(rc);
}
//
//ft_get_texture
void	ft_get_texture(t_raycast *rc)
{
    if (!(rc->texture[0].img = mlx_xpm_file_to_image(rc->data.mlx_ptr,
                                                     rc->config->n, &(rc->texture[0].width),
                                                     &(rc->texture[0].height))))
        ft_error(rc, "Texture NO\n");
    if (!(rc->texture[1].img = mlx_xpm_file_to_image(rc->data.mlx_ptr,
                                                     rc->config->s, &(rc->texture[1].width),
                                                     &(rc->texture[1].height))))
        ft_error(rc, "Texture SO\n");
    if (!(rc->texture[2].img = mlx_xpm_file_to_image(rc->data.mlx_ptr,
                                                     rc->config->w, &(rc->texture[2].width),
                                                     &(rc->texture[2].height))))
        ft_error(rc, "Texture WE\n");
    if (!(rc->texture[3].img = mlx_xpm_file_to_image(rc->data.mlx_ptr,
                                                     rc->config->e, &(rc->texture[3].width),
                                                     &(rc->texture[3].height))))
        ft_error(rc, "Texture EA\n");
    ft_get_texture_adress(rc);
}
void	ft_get_texture_adress(t_raycast *rc)
{
    rc->texture[0].addr = (int *)mlx_get_data_addr(rc->texture[0].img,
                                                   &rc->texture[0].bits_per_pixel,
                                                   &rc->texture[0].line_length, &rc->texture[0].endian);
    rc->texture[1].addr = (int *)mlx_get_data_addr(rc->texture[1].img,
                                                   &rc->texture[1].bits_per_pixel,
                                                   &rc->texture[1].line_length, &rc->texture[1].endian);
    rc->texture[2].addr = (int *)mlx_get_data_addr(rc->texture[2].img,
                                                   &rc->texture[2].bits_per_pixel,
                                                   &rc->texture[2].line_length, &rc->texture[2].endian);
    rc->texture[3].addr = (int *)mlx_get_data_addr(rc->texture[3].img,
                                                   &rc->texture[3].bits_per_pixel,
                                                   &rc->texture[3].line_length, &rc->texture[3].endian);
}

//
int		ft_exit(t_raycast *rc)
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
//
int		ft_key_press(int keycode, t_raycast *rc)
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
//
int		ft_key_release(int keycode, t_raycast *rc)
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
//
int		ft_mlx(t_raycast *rc)
{
    ft_init_ray(rc);
    if (!(rc->data.mlx_ptr = mlx_init()))
        ft_error(rc, "Mlx init impossible\n");
    ft_get_texture(rc);
    rc->data.img = mlx_new_image(rc->data.mlx_ptr, rc->screenx, rc->screeny);
    rc->data.addr = (int *)mlx_get_data_addr(rc->data.img, &rc->data.
            bits_per_pixel, &rc->data.line_length, &rc->data.endian);
    rc->data.mlx_win = mlx_new_window(rc->data.mlx_ptr, rc->screenx,
                                      rc->screeny, "Cub3d");

    mlx_hook(rc->data.mlx_win, 33, 1L << 17, ft_exit, rc);
    mlx_hook(rc->data.mlx_win, 2, 1L << 0, ft_key_press, rc);
    mlx_loop_hook(rc->data.mlx_ptr, ft_raycasting, rc);
    mlx_hook(rc->data.mlx_win, 3, 1L << 1, ft_key_release, rc);
    mlx_loop(rc->data.mlx_ptr);
    return (0);
}

