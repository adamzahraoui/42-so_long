/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   click_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzahrao <adzahrao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:14:59 by adzahrao          #+#    #+#             */
/*   Updated: 2025/02/12 10:52:37 by adzahrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	up(t_so_long_check *data)
{
	if ((data->str[data->y - 1][data->x] == '0' || data->str[data->y
			- 1][data->x] == 'C' || data->str[data->y - 1][data->x] == 'E'
			|| data->str[data->y - 1][data->x] == 'L') && data->eat > 0)
	{
		enemy_up(data);
		if (data->str[data->y - 1][data->x] == 'C')
			(1) && (data->str[data->y - 1][data->x] = '0', data->eat--);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->ground,
			(data->x) * 32, (data->y) * 32);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->player,
			(data->x) * 32, (data->y-- - 1) * 32);
		display_move(data);
	}
	else if ((data->str[data->y - 1][data->x] == '0' || data->str[data->y
			- 1][data->x] == 'E' || data->str[data->y - 1][data->x] == 'L')
		&& data->eat <= 0)
	{
		enemy_up(data);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->ground,
			(data->x) * 32, (data->y) * 32);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->player,
			(data->x) * 32, (data->y - 1) * 32);
		data->str[data->y--][data->x] = '0';
		display_move(data);
	}
}

void	right(t_so_long_check *data)
{
	if ((data->str[data->y][data->x + 1] == '0' || data->str[data->y][data->x
		+ 1] == 'C' || data->str[data->y][data->x + 1] == 'E'
			|| data->str[data->y][data->x + 1] == 'L') && data->eat > 0)
	{
		enemy_right(data);
		if (data->str[data->y][data->x + 1] == 'C')
			(1) && (data->str[data->y][data->x + 1] = '0', data->eat--);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->ground,
			(data->x) * 32, (data->y) * 32);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->player,
			(data->x++ + 1) * 32, (data->y) * 32);
		display_move(data);
	}
	else if ((data->str[data->y][data->x + 1] == '0'
		|| data->str[data->y][data->x + 1] == 'E'
			|| data->str[data->y][data->x + 1] == 'L') && data->eat == 0)
	{
		enemy_right(data);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->ground,
			(data->x) * 32, (data->y) * 32);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->player, (data->x
				+ 1) * 32, (data->y) * 32);
		data->str[data->y][data->x++] = '0';
		display_move(data);
	}
}

void	down(t_so_long_check *data)
{
	if ((data->str[data->y + 1][data->x] == '0' || data->str[data->y
			+ 1][data->x] == 'C' || data->str[data->y + 1][data->x] == 'E'
			|| data->str[data->y + 1][data->x] == 'L') && data->eat > 0)
	{
		enemy_down(data);
		if (data->str[data->y + 1][data->x] == 'C')
			(1) && (data->str[data->y + 1][data->x] = '0', data->eat--);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->ground,
			(data->x) * 32, (data->y) * 32);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->player,
			(data->x) * 32, (data->y + 1) * 32);
		data->str[data->y++][data->x] = '0';
		display_move(data);
	}
	else if ((data->str[data->y + 1][data->x] == '0' || data->str[data->y
			+ 1][data->x] == 'E' || data->str[data->y + 1][data->x] == 'L')
		&& data->eat == 0)
	{
		enemy_down(data);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->ground,
			(data->x) * 32, (data->y) * 32);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->player,
			(data->x) * 32, (data->y + 1) * 32);
		data->str[data->y++][data->x] = '0';
		display_move(data);
	}
}

void	left(t_so_long_check *data)
{
	if ((data->str[data->y][data->x - 1] == '0' || data->str[data->y][data->x
		- 1] == 'C' || data->str[data->y][data->x - 1] == 'E'
			|| data->str[data->y][data->x - 1] == 'L') && data->eat > 0)
	{
		enemy_left(data);
		if (data->str[data->y][data->x - 1] == 'C')
			(1) && (data->str[data->y][data->x - 1] = '0', data->eat--);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->ground,
			(data->x) * 32, (data->y) * 32);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->player_left,
			(data->x-- - 1) * 32, (data->y) * 32);
		display_move(data);
	}
	else if ((data->str[data->y][data->x - 1] == '0'
		|| data->str[data->y][data->x - 1] == 'E'
			|| data->str[data->y][data->x - 1] == 'L') && data->eat == 0)
	{
		enemy_left(data);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->ground,
			(data->x) * 32, (data->y) * 32);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->player_left,
			(data->x - 1) * 32, (data->y) * 32);
		data->str[data->y][data->x--] = '0';
		display_move(data);
	}
}
