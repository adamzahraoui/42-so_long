/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fram.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzahrao <adzahrao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:40:09 by adzahrao          #+#    #+#             */
/*   Updated: 2025/02/12 14:32:59 by adzahrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void    set_image_frame(t_so_long_check *map)
{
    t_so_long_check	data;

	map->f1 = mlx_xpm_file_to_image(map->mlx, PICTURE_F1, &data.width_f,
			&data.height_f);
    map->f2 = mlx_xpm_file_to_image(map->mlx, PICTURE_F2, &data.width_f,
			&data.height_f);
    map->f3 = mlx_xpm_file_to_image(map->mlx, PICTURE_F3, &data.width_f,
			&data.height_f);
	map->f4 = mlx_xpm_file_to_image(map->mlx, PICTURE_F4, &data.width_f,
			&data.height_f);
	map->f5 = mlx_xpm_file_to_image(map->mlx, PICTURE_F5, &data.width_f,
			&data.height_f);
	map->f6 = mlx_xpm_file_to_image(map->mlx, PICTURE_F6, &data.width_f,
			&data.height_f);
}

int animate_frames(t_so_long_check *map)
{
    static int frame_count = 0;
    static int current_frame = 0;
    void *frame_to_display;
    int x = 0;
    int y = 0;

    if (frame_count++ >= 20000)
    {
        for (y = 0; map->str[y]; y++)
        {
            for (x = 0; map->str[y][x]; x++)
            {
                if (map->str[y][x] == 'C')
                {
                        frame_to_display = (current_frame % 6 == 0) ? map->f1 :
                                            (current_frame % 6 == 1) ? map->f2 :
                                            (current_frame % 6 == 2) ? map->f3 :
                                            (current_frame % 6 == 3) ? map->f4 :
                                            (current_frame % 6 == 4) ? map->f5 : map->f6;

                    
                    mlx_put_image_to_window(map->mlx, map->mlx_win, frame_to_display, x * 32, y * 32);
                }
            }
        }
        current_frame = (current_frame + 1) % 6;
        frame_count = 0;
    }
    return (0);
}

void    close_frame(t_so_long_check *close)
{
	if (close->f1 != NULL)
		mlx_destroy_image(close->mlx, close->f1);
	if (close->f1 != NULL)
		mlx_destroy_image(close->mlx, close->f2);
	if (close->f3 != NULL)
		mlx_destroy_image(close->mlx, close->f3);
	if (close->f4 != NULL)
		mlx_destroy_image(close->mlx, close->f4);
	if (close->f5 != NULL)
		mlx_destroy_image(close->mlx, close->f5);
	if (close->f6 != NULL)
		mlx_destroy_image(close->mlx, close->f6);
}
