/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzahrao <adzahrao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 09:48:22 by adzahrao          #+#    #+#             */
/*   Updated: 2025/02/04 11:38:45 by adzahrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int    close_window(game *close)
{
    printf("Window close button pressed. Exiting...\n");
    mlx_destroy_window(close->mlx, close->mlx_win);
    exit(0);
    return 0;
}

int key_press(int keycode, game *data) {
    printf("Key pressed: %d\n", keycode);
    
    if (keycode == 65307) {  // ESC key (X11)
        printf("ESC pressed. Closing window...\n");
        mlx_destroy_window(data->mlx, data->mlx_win);
        exit(0);
    }
    else if(keycode == 120)
    {
        printf("X pressed. Closing window...\n");
        mlx_destroy_window(data->mlx, data->mlx_win);
        exit(0);
    }
    else if (keycode == 119 || keycode == 65362)
    {
            
    }
    esle if (keycode == 100 || keycode == 65363)
    {

    }
    else if (keycode == 115 || keycode == 65364)
    {
        
    }
    else if (keycode == 97 || keycode == 65361)
    {
        
    }
    return 0;
}


void    set_window(char *argv, so_long_check *map)
{
    game window;

    int width;
    int height;

    int width_g;
    int height_g;

    int width_p;
    int height_p;

    int width_c;
    int height_c;

    int width_e;
    int height_e;

    char **str = NULL;
    int fd;
    int x;
    int y;
    int z = 0;
    int w;

    fd = open(argv, O_RDONLY);
    str = malloc((map->l3rd + 1) * sizeof(char *));
    str[z] = malloc(map->tol + 1);
    while((str[z] = get_next_line(fd)) != NULL)
    {
        z++;
        str[z] = malloc(map->tol + 1);
    }
    
    window.mlx = NULL;
    window.mlx_win = NULL;
    window.wall = NULL;
    window.mlx = mlx_init();
    window.mlx_win = mlx_new_window(window.mlx, map->tol*32, (map->l3rd-1)*32, "so_long");
    window.wall = mlx_xpm_file_to_image(window.mlx, "./picture/wall.xpm", &width, &height);
    window.ground = mlx_xpm_file_to_image(window.mlx, "./picture/ground.xpm", &width_g, &height_g);
    window.player = mlx_xpm_file_to_image(window.mlx, "./picture/right.xpm", &width_p, &height_p);
    window.coin = mlx_xpm_file_to_image(window.mlx, "./picture/coin.xpm", &width_c, &height_c);
    window.exit = mlx_xpm_file_to_image(window.mlx, "./picture/exit.xpm", &width_e, &height_e);
    x = 0;
    y = 0;
    z = 0;

    while(str[z])
    {
        w = 0;
        x = 0;
        while(str[z][w])
        {
            if(str[z][w] == '1')
                mlx_put_image_to_window(window.mlx, window.mlx_win, window.wall, x, y);
            if(str[z][w] == '0')
                mlx_put_image_to_window(window.mlx, window.mlx_win, window.ground, x, y);
            if(str[z][w] == 'P')
                mlx_put_image_to_window(window.mlx, window.mlx_win, window.player, x, y);
            if(str[z][w] == 'C')
                mlx_put_image_to_window(window.mlx, window.mlx_win, window.coin, x, y);
            if(str[z][w] == 'E')
                mlx_put_image_to_window(window.mlx, window.mlx_win, window.exit, x, y);
            x+=32;
            w++;
        }
        y+=32;
        z++;
    }
    mlx_key_hook(window.mlx_win, key_press, &window);
    mlx_hook(window.mlx_win, 17, 0, close_window, &window);
    mlx_loop(window.mlx);
}
