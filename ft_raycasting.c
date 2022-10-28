#include "cub3d.h"
//ft_cacl_ray
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
        rc->ray.deltadistx = sqrt(1 + (rc->ray.raydiry
                                       * rc->ray.raydiry) / (rc->ray.raydirx *
                                                             rc->ray.raydirx));
    if (rc->ray.raydirx == 0)
        rc->ray.deltadisty = 0;
    else if (rc->ray.raydiry == 0)
        rc->ray.deltadisty = 1;
    else
        rc->ray.deltadisty = sqrt(1 + (rc->ray.raydirx *
                                       rc->ray.raydirx) / (rc->ray.raydiry *
                                                           rc->ray.raydiry));
}
//
//ft_calc_step
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
        // printf("Map x: %d\n", rc->ray.mapx);
        // printf("Map y: %d\n", rc->ray.mapy);
        // printf("Player on the map: %d %d\n", rc->config->plr_x, rc->config->plr_y);
        // printf("Char on the map: %c\n", rc->config->map[2][6]);
        // if (rc->config->map[rc->ray.mapx][rc->ray.mapy] == '1')
        //     rc->ray.hit = 1;
        if (rc->config->map[rc->ray.mapx][rc->ray.mapy] == '1')
            rc->ray.hit = 1;
    }
    ft_calc_start_end(rc);
}
void	ft_calc_start_end(t_raycast *rc)
{
    
    if (rc->ray.side == 0)
        rc->ray.perpwalldist = ((double)rc->ray.mapx - \
				rc->ray.posx + (1 - (double)rc->ray.
                stepx) / 2) / rc->ray.raydirx;
    else
        rc->ray.perpwalldist = ((double)rc->ray.mapy - \
				rc->ray.posy + (1 - (double)rc->ray.
                stepy) / 2) / rc->ray.raydiry;
    rc->ray.lineheight = (int)(rc->screeny / rc->ray.perpwalldist);
    rc->ray.drawstart = -rc->ray.lineheight / 2 + rc->screeny / 2;
    if (rc->ray.drawstart < 0)
        rc->ray.drawstart = 0;
    rc->ray.drawend = rc->ray.lineheight / 2 + rc->screeny / 2;
    if (rc->ray.drawend >= rc->screeny || rc->ray.drawend < 0)
        rc->ray.drawend = rc->screeny - 1;
}
//
//ft_color_column
int		ft_color_column(t_raycast *rc)
{
    int j;
    int i;

    j = -1;
    rc->ray.drawend = rc->screeny - rc->ray.drawstart;
    i = rc->ray.drawend;
    while (++j < rc->ray.drawstart)
        rc->data.addr[j * rc->data.line_length / 4 +
                      rc->ray.x] = rc->config->ceiling;
    if (j <= rc->ray.drawend)
        ft_draw_texture(rc, rc->ray.x, j);
    j = i;
    while (++j < rc->screeny)
        rc->data.addr[j * rc->data.line_length / 4 +
                      rc->ray.x] = rc->config->floor;
    return (0);
}
void	ft_draw_texture(t_raycast *rc, int x, int y)
{
    y = rc->ray.drawstart - 1;
    ft_init_texture(rc);
    rc->t.step = 1.0 * rc->texture[0].height / rc->ray.lineheight;
    rc->t.texx = (int)(rc->t.wallx * (double)rc->texture
    [rc->t.texdir].width);
    if (rc->ray.side == 0 && rc->ray.raydirx > 0)
        rc->t.texx = rc->texture[rc->t.texdir].width -
                     rc->t.texx - 1;
    if (rc->ray.side == 1 && rc->ray.raydiry < 0)
        rc->t.texx = rc->texture[rc->t.texdir].width -
                     rc->t.texx - 1;
    rc->t.texpos = (rc->ray.drawstart - rc->screeny / 2 +
                    rc->ray.lineheight / 2) * rc->t.step;
    while (++y <= rc->ray.drawend)
    {
        rc->t.texy = (int)rc->t.texpos &
                     (rc->texture[rc->t.texdir].height - 1);
        rc->t.texpos += rc->t.step;
        if (y < rc->screeny && x < rc->screenx)
            rc->data.addr[y * rc->data.line_length / 4 + x] =
                    rc->texture[rc->t.texdir].addr[rc->t.texy *
                                                   rc->texture[rc->t.texdir].line_length /
                                                   4 + rc->t.texx];
    }
}
void	ft_init_texture(t_raycast *rc)
{
    if (rc->ray.side == 0 && rc->ray.raydirx < 0)
        rc->t.texdir = 0;
    if (rc->ray.side == 0 && rc->ray.raydirx >= 0)
        rc->t.texdir = 1;
    if (rc->ray.side == 1 && rc->ray.raydiry < 0)
        rc->t.texdir = 2;
    if (rc->ray.side == 1 && rc->ray.raydiry >= 0)
        rc->t.texdir = 3;
    if (rc->ray.side == 0)
        rc->t.wallx = rc->ray.posy + rc->ray.perpwalldist \
						* rc->ray.raydiry;
    else
        rc->t.wallx = rc->ray.posx + rc->ray.perpwalldist \
						* rc->ray.raydirx;
    rc->t.wallx -= floor((rc->t.wallx));
}
//
//ft_forward_back
void	ft_forward_back(t_raycast *rc)
{
    if (rc->data.forward == 1)
    {
        if (rc->config->map[(int)(rc->ray.posx + (rc->ray.dirx * rc->
                ray.movespeed * 2))][(int)rc->ray.posy] == '0')
            rc->ray.posx += rc->ray.dirx * rc->ray.movespeed;
        if (rc->config->map[(int)(rc->ray.posx)][(int)(rc->ray.posy +
                                                      (rc->ray.diry * rc->ray.movespeed * 2))] == '0')
            rc->ray.posy += rc->ray.diry * rc->ray.movespeed;
    }
    if (rc->data.back == 1)
    {
        if (rc->config->map[(int)(rc->ray.posx - (rc->ray.dirx * rc->
                ray.movespeed * 2))][(int)(rc->ray.posy)] == '0')
            rc->ray.posx -= rc->ray.dirx * rc->ray.movespeed;
        if (rc->config->map[(int)(rc->ray.posx)][(int)(rc->ray.posy -
                                                      (rc->ray.diry * rc->ray.movespeed * 2))] == '0')
            rc->ray.posy -= rc->ray.diry * rc->ray.movespeed;
    }
}

//
//ft_left_right
void	ft_left_right(t_raycast *rc)
{
    if (rc->data.right == 1)
    {
        if (rc->config->map[(int)(rc->ray.posx + rc->ray.diry *
                                                (rc->ray.movespeed * 2))][(int)rc->ray.posy] == '0')
            rc->ray.posx += rc->ray.diry * rc->ray.movespeed;
        if (rc->config->map[(int)rc->ray.posx][(int)(rc->ray.posy -
                                                    rc->ray.dirx *
                                                    (rc->ray.movespeed * 2))] == '0')
            rc->ray.posy -= rc->ray.dirx * rc->ray.movespeed;
    }
    if (rc->data.left == 1)
    {
        if (rc->config->map[(int)(rc->ray.posx - rc->ray.diry *
                                                (rc->ray.movespeed * 2))][(int)rc->ray.posy] == '0')
            rc->ray.posx -= rc->ray.diry * rc->ray.movespeed;
        if (rc->config->map[(int)rc->ray.posx][(int)(rc->ray.posy +
                                                    rc->ray.dirx *
                                                    (rc->ray.movespeed * 2))] == '0')
            rc->ray.posy += rc->ray.dirx * rc->ray.movespeed;
    }
}
//
//ft_rotate_right_left
void	ft_rotate_right_left(t_raycast *rc)
{
    double oldplanx;
    double olddirx;

    oldplanx = rc->ray.planx;
    olddirx = rc->ray.dirx;
    if (rc->data.rotate_right == 1)
    {
        rc->ray.dirx = rc->ray.dirx * cos(-rc->ray.rotspeed / 2) -
                       rc->ray.diry * sin(-rc->ray.rotspeed / 2);
        rc->ray.diry = olddirx * sin(-rc->ray.rotspeed / 2) +
                       rc->ray.diry * cos(-rc->ray.rotspeed / 2);
        rc->ray.planx = rc->ray.planx * cos(-rc->ray.rotspeed / 2)
                        - rc->ray.plany * sin(-rc->ray.rotspeed / 2);
        rc->ray.plany = oldplanx * sin(-rc->ray.rotspeed / 2) +
                        rc->ray.plany * cos(-rc->ray.rotspeed / 2);
    }
    ft_rotate_left(rc, olddirx);
}
void	ft_rotate_left(t_raycast *rc, double olddirx)
{
    double oldplanex;

    if (rc->data.rotate_left == 1)
    {
        olddirx = rc->ray.dirx;
        oldplanex = rc->ray.planx;
        rc->ray.dirx = rc->ray.dirx * cos(rc->ray.rotspeed / 2) -
                       rc->ray.diry * sin(rc->ray.rotspeed / 2);
        rc->ray.diry = olddirx * sin(rc->ray.rotspeed / 2) + rc->
                ray.diry * cos(rc->ray.rotspeed / 2);
        rc->ray.planx = rc->ray.planx * cos(rc->ray.rotspeed / 2) -
                        rc->ray.plany * sin(rc->ray.rotspeed / 2);
        rc->ray.plany = oldplanex * sin(rc->ray.rotspeed / 2) +
                        rc->ray.plany * cos(rc->ray.rotspeed / 2);
    }
}

//
int		ft_raycasting(t_raycast *rc)
{
    rc->ray.x = 0;
    while (rc->ray.x < rc->screenx)
    {
        ft_calc_ray(rc);
        ft_calc_step(rc);
        ft_color_column(rc);
        rc->ray.x++;
    }
    mlx_put_image_to_window(rc->data.mlx_ptr, rc->data.mlx_win,
                            rc->data.img, 0, 0);
    ft_forward_back(rc);
    ft_left_right(rc);
    ft_rotate_right_left(rc);
    return (0);
}