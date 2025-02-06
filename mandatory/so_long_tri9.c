/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_tri9.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzahrao <adzahrao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:03:36 by adzahrao          #+#    #+#             */
/*   Updated: 2025/02/06 15:32:02 by adzahrao         ###   ########.fr       */
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

int check_tri9(char **tri9, int x, int y, so_long_check *map)
{
    if(x < 0 || y < 0 || tri9[y] == NULL || tri9[y][x] == '1' || tri9[y][x] == 'F')
        return 0;
    if (tri9[y][x] == 'C')
        map->find_C++;
    if (tri9[y][x] == 'E')
        map->find_E++;
    tri9[y][x] = 'F';
    
    check_tri9(tri9, x - 1, y ,map);
    check_tri9(tri9, x + 1, y ,map);
    check_tri9(tri9, x, y - 1,map);
    check_tri9(tri9, x, y + 1,map);
    
    return (map->find_C == map->makla && map->find_E == map->lbab);
}
