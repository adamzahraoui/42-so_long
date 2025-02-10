/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_tri9.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzahrao <adzahrao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:03:36 by adzahrao          #+#    #+#             */
/*   Updated: 2025/02/10 10:27:26 by adzahrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putchar_ft(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb >= 0 && nb <= 9)
	{
		ft_putchar_ft(nb + '0');
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		nb *= -1;
		write(1, "-", 1);
		ft_putnbr(nb);
	}
}

int	check_tri9(char **tri9, int x, int y, t_so_long_check *map)
{
	if (x < 0 || y < 0 || tri9[y] == NULL || tri9[y][x] == '1'
		|| tri9[y][x] == 'F')
		return (0);
	if (tri9[y][x] == 'C')
		map->find_c++;
	if (tri9[y][x] == 'E')
		map->find_e++;
	tri9[y][x] = 'F';
	check_tri9(tri9, x - 1, y, map);
	check_tri9(tri9, x + 1, y, map);
	check_tri9(tri9, x, y - 1, map);
	check_tri9(tri9, x, y + 1, map);
	return (map->find_c == map->makla && map->find_e == map->lbab);
}

void	set_pic(char c, t_so_long_check *map, int x, int y)
{
	if (c == '1')
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->wall, x, y);
	if (c == '0')
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->ground, x, y);
	if (c == 'P')
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->player, x, y);
	if (c == 'C')
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->coin, x, y);
	if (c == 'E')
	{
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->ground, x, y);
		map->pos_e_x = map->w;
		map->pos_e_y = map->z;
		map->pos_ex = x;
		map->pos_ey = y;
	}
}

void	free_free_map(t_so_long_check *map, int i)
{
	while (i--)
		free(map->str_copy[i]);
	free(map->str_copy);
	return ;
}
