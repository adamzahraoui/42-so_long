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
    printf("map close button pressed. Exiting...\n");
    mlx_destroy_window(close->mlx, close->mlx_win);
    exit(0);
    return 0;
}

int key_press(int keycode, so_long_check *data)
{
    static int i = 1;
    
    if (keycode == 65307) {  // ESC key (X11)
        printf("ESC pressed. Closing map...\n");
        mlx_destroy_window(data->mlx, data->mlx_win);
        exit(0);
    }
    else if(keycode == 120)
    {
        printf("X pressed. Closing map...\n");
        mlx_destroy_window(data->mlx, data->mlx_win);
        exit(0);
    }
    else if ((keycode == 119 || keycode == 65362) && (data->str[data->y - 1][data->x] == '0' || data->str[data->y - 1][data->x] == 'C'))
    {
        if(data->str[data->y - 1][data->x] == 'C')
            data->makla--;
        mlx_put_image_to_window(data->mlx, data->mlx_win, data->ground, (data->x)*32, (data->y)*32);
        mlx_put_image_to_window(data->mlx, data->mlx_win, data->player, (data->x)*32, (data->y-1)*32);
        data->str[data->y][data->x] = '0';
        printf("%d\n", i++);
        data->y--;
    }
    else if ((keycode == 100 || keycode == 65363) && (data->str[data->y][data->x+1] == '0' || data->str[data->y][data->x+1] == 'C'))
    {
        if(data->str[data->y][data->x+1] == 'C')
            data->makla--;
        mlx_put_image_to_window(data->mlx, data->mlx_win, data->ground, (data->x)*32, (data->y)*32);
        mlx_put_image_to_window(data->mlx, data->mlx_win, data->player, (data->x + 1)*32, (data->y)*32);
        data->str[data->y][data->x] = '0';
        printf("%d\n", i++);
        data->x++;
    }
    else if ((keycode == 115 || keycode == 65364) && (data->str[data->y + 1][data->x] == '0' || data->str[data->y + 1][data->x] == 'C'))
    {
        if(data->str[data->y + 1][data->x] == 'C')
            data->makla--;
        mlx_put_image_to_window(data->mlx, data->mlx_win, data->ground, (data->x)*32, (data->y)*32);
        mlx_put_image_to_window(data->mlx, data->mlx_win, data->player, (data->x)*32, (data->y+1)*32);
        data->str[data->y][data->x] = '0';
        printf("%d\n", i++);
        data->y++;        
    }
    else if ((keycode == 97 || keycode == 65361) && (data->str[data->y][data->x - 1] == '0' || data->str[data->y][data->x - 1] == 'C'))
    {
        if(data->str[data->y][data->x - 1] == 'C')
            data->makla--;
        mlx_put_image_to_window(data->mlx, data->mlx_win, data->ground, (data->x)*32, (data->y)*32);
        mlx_put_image_to_window(data->mlx, data->mlx_win, data->player_left, (data->x - 1)*32, (data->y)*32);
        data->str[data->y][data->x] = '0';
        printf("%d\n", i++);
        data->x--;       
    }
    else if((keycode == 119 || keycode == 65362) && (data->str[data->y - 1][data->x] == '0' || data->str[data->y - 1][data->x] == 'E') && data->makla <= 0)
    {
        mlx_put_image_to_window(data->mlx, data->mlx_win, data->ground, (data->x)*32, (data->y)*32);
        mlx_put_image_to_window(data->mlx, data->mlx_win, data->player, (data->x)*32, (data->y-1)*32);
        data->str[data->y][data->x] = '0';
        data->y--;
        printf("%d\n", i++);
        close_map(data);
    }
    else if ((keycode == 100 || keycode == 65363) && (data->str[data->y][data->x+1] == '0' || data->str[data->y][data->x+1] == 'E') && data->makla <= 0)
    {
        mlx_put_image_to_window(data->mlx, data->mlx_win, data->ground, (data->x)*32, (data->y)*32);
        mlx_put_image_to_window(data->mlx, data->mlx_win, data->player, (data->x + 1)*32, (data->y)*32);
        data->str[data->y][data->x] = '0';
        data->x++;
        printf("%d\n", i++);
        close_map(data);
    }
    else if ((keycode == 115 || keycode == 65364) && (data->str[data->y + 1][data->x] == '0' || data->str[data->y + 1][data->x] == 'E') && data->makla <= 0)
    {
        mlx_put_image_to_window(data->mlx, data->mlx_win, data->ground, (data->x)*32, (data->y)*32);
        mlx_put_image_to_window(data->mlx, data->mlx_win, data->player, (data->x)*32, (data->y+1)*32);
        data->str[data->y][data->x] = '0';
        data->y++;
        printf("%d\n", i++);
        close_map(data);
    }
    else if((keycode == 97 || keycode == 65361) && (data->str[data->y][data->x - 1] == '0' || data->str[data->y][data->x - 1] == 'E') && data->makla <= 0)
    {
        mlx_put_image_to_window(data->mlx, data->mlx_win, data->ground, (data->x)*32, (data->y)*32);
        mlx_put_image_to_window(data->mlx, data->mlx_win, data->player_left, (data->x - 1)*32, (data->y)*32);
        data->str[data->y][data->x] = '0';
        data->x--;
        printf("%d\n", i++);
        close_map(data);
    }
    return 0;
}


void    set_window(so_long_check *map)
{
    int width;
    int height;

    int width_g;
    int height_g;

    int width_p;
    int height_p;

    int width_l;
    int height_l;

    int width_c;
    int height_c;

    int width_e;
    int height_e;

    int x;
    int y;
    int z;
    int w;

    map->mlx = NULL;
    map->mlx_win = NULL;
    map->wall = NULL;
    map->mlx = mlx_init();
    map->mlx_win = mlx_new_window(map->mlx, map->tol*32, (map->l3rd - 1)*32, "so_long");
    map->wall = mlx_xpm_file_to_image(map->mlx, "./picture/wall.xpm", &width, &height);
    map->ground = mlx_xpm_file_to_image(map->mlx, "./picture/ground.xpm", &width_g, &height_g);
    map->player = mlx_xpm_file_to_image(map->mlx, "./picture/right.xpm", &width_p, &height_p);
    map->player_left = mlx_xpm_file_to_image(map->mlx, "./picture/left.xpm", &width_l, &height_l);
    map->coin = mlx_xpm_file_to_image(map->mlx, "./picture/coin.xpm", &width_c, &height_c);
    map->exit = mlx_xpm_file_to_image(map->mlx, "./picture/exit.xpm", &width_e, &height_e);
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
                mlx_put_image_to_window(map->mlx, map->mlx_win, map->exit, x, y);
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
