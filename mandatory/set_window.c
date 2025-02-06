/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzahrao <adzahrao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 09:48:22 by adzahrao          #+#    #+#             */
/*   Updated: 2025/02/04 17:40:13 by adzahrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int    close_map(so_long_check *close)
{
    printf("you win !!");
    mlx_destroy_window(close->mlx, close->mlx_win);
    exit(0);
    return 0;
}
void    booton_close(int key, so_long_check *close)
{
    if (key == 65307) 
    {
        printf("ESC pressed. Closing map...\n");
        mlx_destroy_window(close->mlx, close->mlx_win);
        exit(0);
    }
    else if(key == 120)
    {
        printf("X pressed. Closing map...\n");
        mlx_destroy_window(close->mlx, close->mlx_win);
        exit(0);
    }
}

int key_press(int keycode, so_long_check *data)
{   
    if(data->str[data->y][data->x] == 'P')
        data->str[data->y][data->x] = '0';
    if(keycode == 65307)
        booton_close(keycode, data);
    else if(keycode == 120)
        booton_close(keycode, data);
    else if (keycode == 119 || keycode == 65362)
        up(data);
    else if (keycode == 100 || keycode == 65363)
        right(data);
    else if (keycode == 115 || keycode == 65364)
        down(data);
    else if (keycode == 97 || keycode == 65361)
        left(data);
    if(data->makla <=0 )
        mlx_put_image_to_window(data->mlx, data->mlx_win, data->exit, data->pos_EX, data->pos_EY);
    if(data->lbab <= 0)
        close_map(data);
    return 0;
}


void    set_window(so_long_check *map)
{

    so_long_check data;

    int x;
    int y;
    int z;
    int w;
    map->move = 1;

    map->mlx = NULL;
    map->mlx_win = NULL;
    map->wall = NULL;
    map->mlx = mlx_init();
    map->mlx_win = mlx_new_window(map->mlx, map->tol*32, (map->l3rd - 1)*32, "so_long");
    map->wall = mlx_xpm_file_to_image(map->mlx, "./picture/wall.xpm", &data.width, &data.height);
    map->ground = mlx_xpm_file_to_image(map->mlx, "./picture/ground.xpm", &data.width_g, &data.height_g);
    map->player = mlx_xpm_file_to_image(map->mlx, "./picture/right.xpm", &data.width_p, &data.height_p);
    map->player_left = mlx_xpm_file_to_image(map->mlx, "./picture/left.xpm", &data.width_l, &data.height_l);
    map->coin = mlx_xpm_file_to_image(map->mlx, "./picture/coin.xpm", &data.width_c, &data.height_c);
    map->exit = mlx_xpm_file_to_image(map->mlx, "./picture/exit.xpm", &data.width_e, &data.height_e);
    x = 0;
    y = 0;
    z = 0;

    while(map->str[z])
    {
        w = 0;
        x = 0;
        while(map->str[z][w])
        {
            if(map->str[z][w] == '1')
                mlx_put_image_to_window(map->mlx, map->mlx_win, map->wall, x, y);
            if(map->str[z][w] == '0')
                mlx_put_image_to_window(map->mlx, map->mlx_win, map->ground, x, y);
            if(map->str[z][w] == 'P')
                mlx_put_image_to_window(map->mlx, map->mlx_win, map->player, x, y);
            if(map->str[z][w] == 'C')
                mlx_put_image_to_window(map->mlx, map->mlx_win, map->coin, x, y);
            if(map->str[z][w] == 'E')
            {
                mlx_put_image_to_window(map->mlx, map->mlx_win, map->ground, x, y);
                map->pos_E_x = w;
                map->pos_E_y = z;
                map->pos_EX = x;
                map->pos_EY = y;
            }
            x+=32;
            w++;
        }
        y+=32;
        z++;        
    }
    mlx_hook(map->mlx_win, 2, 1L << 0, key_press, map);
    mlx_hook(map->mlx_win, 17, 0, close_map, map);
    mlx_loop(map->mlx);
}
