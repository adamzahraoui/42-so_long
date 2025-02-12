/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzahrao <adzahrao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:29:36 by adzahrao          #+#    #+#             */
/*   Updated: 2025/02/12 11:00:38 by adzahrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	enemy_left(t_so_long_check *data)
{
	if (data->str[data->y][data->x - 1] == 'L')
	{
		ft_printf("Game Over :( ...\n");
		close_x(data);
	}
}

void	enemy_right(t_so_long_check *data)
{
	if (data->str[data->y][data->x + 1] == 'L')
	{
		ft_printf("Game Over :( ...\n");
		close_x(data);
	}
}

void	enemy_up(t_so_long_check *data)
{
	if (data->str[data->y - 1][data->x] == 'L')
	{
		ft_printf("Game Over :( ...\n");
		close_x(data);
	}
}

void	enemy_down(t_so_long_check *data)
{
	if (data->str[data->y + 1][data->x] == 'C')
		(1) && (data->str[data->y + 1][data->x] = '0', data->eat--);
	if (data->str[data->y + 1][data->x] == 'L')
	{
		ft_printf("Game Over :( ...\n");
		close_x(data);
	}
}
