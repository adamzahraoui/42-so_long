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

int	close_map(t_so_long_check *close)
{
	if (close->eat == 0 && close->y == close->pos_e_y
		&& close->x == close->pos_e_x)
		ft_printf("you win :)");
	if (close->wall != NULL)
		mlx_destroy_image(close->mlx, close->wall);
	if (close->ground != NULL)
		mlx_destroy_image(close->mlx, close->ground);
	if (close->player != NULL)
		mlx_destroy_image(close->mlx, close->player);
	if (close->player_left != NULL)
		mlx_destroy_image(close->mlx, close->player_left);
	if (close->coin != NULL)
		mlx_destroy_image(close->mlx, close->coin);
	if (close->exit != NULL)
		mlx_destroy_image(close->mlx, close->exit);
	if (close->mlx_win)
		mlx_destroy_window(close->mlx, close->mlx_win);
	if (close->mlx)
		mlx_destroy_display(close->mlx);
	free(close->mlx);
	free_free(close);
	exit(0);
	return (0);
}

int	close_x(t_so_long_check *close)
{
	ft_printf("Closing game...\n");
	if (close->wall != NULL)
		mlx_destroy_image(close->mlx, close->wall);
	if (close->ground != NULL)
		mlx_destroy_image(close->mlx, close->ground);
	if (close->player != NULL)
		mlx_destroy_image(close->mlx, close->player);
	if (close->player_left != NULL)
		mlx_destroy_image(close->mlx, close->player_left);
	if (close->coin != NULL)
		mlx_destroy_image(close->mlx, close->coin);
	if (close->exit != NULL)
		mlx_destroy_image(close->mlx, close->exit);
	mlx_destroy_window(close->mlx, close->mlx_win);
	mlx_destroy_display(close->mlx);
	return (free(close->mlx), free_free(close), exit(0), 0);
}

int	key_press(int keycode, t_so_long_check *data)
{
	if (data->str[data->y][data->x] == 'P')
		data->str[data->y][data->x] = '0';
	if (keycode == 65307)
	{
		ft_printf("ESC pressed. Closing game...\n");
		close_map(data);
		exit(0);
	}
	else if (keycode == 119 || keycode == 65362)
		up(data);
	else if (keycode == 100 || keycode == 65363)
		right(data);
	else if (keycode == 115 || keycode == 65364)
		down(data);
	else if (keycode == 97 || keycode == 65361)
		left(data);
	if (data->eat <= 0)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->exit,
			data->pos_ex, data->pos_ey);
	if (data->eat == 0 && data->y == data->pos_e_y && data->x == data->pos_e_x)
		close_map(data);
	return (0);
}

void	declaration(t_so_long_check *map)
{
	t_so_long_check	data;

	(1) && (map->move = 1, map->mlx = NULL);
	(1) && (map->mlx_win = NULL, map->wall = NULL);
	(1) && (map->ground = NULL, map->coin = NULL);
	map->player = NULL;
	map->player_left = NULL;
	map->exit = NULL;
	map->mlx = mlx_init();
	if (!map->mlx)
		close_map(map);
	map->mlx_win = mlx_new_window(map->mlx, map->tol * 32, (map->l3rd - 1) * 32,
			"so_long");
	map->wall = mlx_xpm_file_to_image(map->mlx, PICTURE_WALL, &data.width,
			&data.height);
	map->ground = mlx_xpm_file_to_image(map->mlx, PICTURE_GROUND, &data.width_g,
			&data.height_g);
	map->player = mlx_xpm_file_to_image(map->mlx, PICTURE_PLAYER_R,
			&data.width_p, &data.height_p);
	map->player_left = mlx_xpm_file_to_image(map->mlx, PICTURE_PLAYER_L,
			&data.width_l, &data.height_l);
	map->coin = mlx_xpm_file_to_image(map->mlx, PICTURE_COIN, &data.width_c,
			&data.height_c);
	map->exit = mlx_xpm_file_to_image(map->mlx, PICTURE_EXIT, &data.width_e,
			&data.height_e);
}

void	set_window(t_so_long_check *map)
{
	int	x;
	int	y;

	declaration(map);
	(1) && (x = 0, y = 0, map->z = 0);
	while (map->str[map->z])
	{
		map->w = 0;
		x = 0;
		while (map->str[map->z][map->w])
		{
			set_pic(map->str[map->z][map->w], map, x, y);
			x += 32;
			map->w++;
		}
		y += 32;
		map->z++;
	}
	mlx_hook(map->mlx_win, 2, 1, key_press, map);
	mlx_hook(map->mlx_win, 17, 0, close_x, map);
	mlx_loop(map->mlx);
}
